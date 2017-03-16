#include <stdio.h>
#include <stdlib.h>
#include <share.h>
#include <string>
#include <math.h>
#include <unordered_map>
using namespace std;
using namespace std::tr1;

const unsigned int MAX_LINE = 1050000;

void main(int argc, char *argv[])
{
	char* fileName = "input\\A-small-attempt0.in";
	char* fileOutName = "output\\A-small-attempt0.out";
	//char* fileName = "input\\A-large.in";
	//char* fileOutName = "output\\A-large.out";
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

		int flipCount = 0;
		int strLen = strlen(currStr);
		string outputStr = "";
		int firstChar = 0;
		for (int currIndex = 0; currIndex < strLen; currIndex++)
		{
			char nextChar = currStr[currIndex];
			int val = nextChar - 'A';
			if (val >= firstChar)
			{
				firstChar = val;
				outputStr = nextChar + outputStr;
			}
			else
			{
				outputStr += nextChar;
			}
		}
		fprintf(fileOutPtr, "Case #%d: %s\n", tt + 1, outputStr.c_str());
	}
	fflush(fileOutPtr);
	fclose(fileOutPtr);
	fclose(filePtr);
}