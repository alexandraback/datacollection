#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <hash_set>
#include <array>

#define FILE_BUF_SIZE 512
#define MAX_R 1
#define MAX_C 10

using namespace std;



int main()
{
	// Prepare file
	FILE* inputFile;
	fopen_s(&inputFile, "A-small-attempt0.in", "r");
	if (inputFile == nullptr)
	{
		printf("Input file open error!\n");
	}

	FILE* outputFile;
	fopen_s(&outputFile, "Small-Output.txt", "w");
	if (outputFile == nullptr)
	{
		printf("Output file open error!\n");
	}

	// Read count of test case
	char fileBuf[FILE_BUF_SIZE + 1];
	fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);
	int countOfTestCase = atoi(fileBuf);

	int r = 0;
	int c = 0;
	int w = 0;
	for (int caseNo = 1; caseNo <= countOfTestCase; caseNo++)
	{
		// Read R, C, W
		fscanf(inputFile, "%d %d %d", &r, &c, &w);		
		fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);

		int countOfTry = r * (c / w);

		bool remainBlock = (c % w != 0);
		if (remainBlock)
			countOfTry++;

		countOfTry += (w - 1);
		
		fprintf(outputFile, "Case #%d: %d \n", caseNo, countOfTry);
	}

	return 1;
}
