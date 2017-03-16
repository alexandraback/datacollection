#include <stdio.h>
#include <stdlib.h>
#include <share.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
using namespace std::tr1;

const unsigned int MAX_LINE = 1050000;

void main(int argc, char *argv[])
{
	//char* fileName = "input\\B-small-attempt0.in";
	//char* fileOutName = "output\\B-small-attempt0.out";
	char* fileName = "input\\B-large.in";
	char* fileOutName = "output\\B-large.out";
	FILE* filePtr = _fsopen(fileName, "r", _SH_DENYNO);
	FILE* fileOutPtr = _fsopen(fileOutName, "w", _SH_DENYNO);
	if (!filePtr || !fileOutPtr)
	{
		printf("File not found\n");
		return;
	}

	char* currStr = (char*)malloc(MAX_LINE);
	fgets(currStr, MAX_LINE, filePtr);
	int numCases = atoi(currStr);
	for (int tt = 0; tt < numCases; tt++)
	{
		fgets(currStr, MAX_LINE, filePtr);
		currStr[strcspn(currStr, "\r\n")] = 0;

		int numSoliders = atoi(currStr);
		int heights[2501] = {0};

		int numReps = (numSoliders * 2) - 1;
		for (int i = 0; i < numReps; i++)
		{
			fgets(currStr, MAX_LINE, filePtr);
			currStr[strcspn(currStr, "\r\n")] = 0;

			char* parseContext = NULL;
			char* currNumAsStr;
			char* currParse = currStr;
			while (currNumAsStr = strtok_s(currParse, " ", &parseContext))
			{
				int currNum = atoi(currNumAsStr);
				heights[currNum]++;
				currParse = NULL;
			}
		}

		vector<int> answers;
		for (int i = 1; i <= 2500; i++)
		{
			if (heights[i] && (heights[i] % 2))
				answers.push_back(i);
		}
		std::sort(answers.begin(), answers.end());

		fprintf(fileOutPtr, "Case #%d:", tt + 1);
		for (int i = 0; i < numSoliders; i++)
			fprintf(fileOutPtr, " %d", answers[i]);
		fprintf(fileOutPtr, "\n");
	}
	fflush(fileOutPtr);
	fclose(fileOutPtr);
	fclose(filePtr);
}