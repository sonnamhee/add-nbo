#include <stdint.h>
#include <stdio.h>
//#include <netinet/in.h>

uint32_t ntohl(uint32_t num){
	uint32_t n1 = ( num & 0xff000000) >> 24;
        uint32_t n2 = ( num & 0x00ff0000) >> 8;
	uint32_t n3 = ( num & 0x0000ff00) << 8;
	uint32_t n4 = ( num & 0x000000ff) << 24;	
	return (n1|n2|n3|n4);
}

void main(int argc, char** argv)
{
	char* fileName1 = argv[1];
	char* fileName2 = argv[2];
	uint32_t num1 = 0;
	uint32_t num2 = 0;

	FILE *fp1 = fopen(fileName1,"rb");
	if(fp1 != NULL){
		fread(&num1, 4, 1, fp1);
		fclose(fp1);
	}

	FILE *fp2 = fopen(fileName2,"rb");
	if(fp2 != NULL){
		fread(&num2, 4, 1, fp2);
		fclose(fp2);
	}

	num1 = ntohl(num1);
	num2 = ntohl(num2);
	uint32_t sum = num1 + num2;
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);
	
}

