// prob1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define NOFIT -1
#define FIT -2
#define NOCHANGE -3

// char * dictionary[521196];
// char * cases[100];
// int score[100][5];

int distToPrev[1000000];
int posMinDistPlusOne[1000000];
int total[1000000];
int consec[1000000];



char currMessage [1000000];
int currMessageLen;
int currNValue;

char strTemp [1000000];




void flushLine()
{
	gets(strTemp);
}

void readCase()
{
	scanf("%s", currMessage);
	currMessageLen = strlen(currMessage);
	scanf("%d", &currNValue);
}

void writeCase(int caseNum, int result)
{
	printf("Case #%d: %d\n", caseNum, result );
}

char isVowel(char c)
{
	switch (c)
	{
		case 'a': return TRUE;
		case 'e': return TRUE;
		case 'i': return TRUE;
		case 'o': return TRUE;
		case 'u': return TRUE;
	}
	return FALSE;
}
	
void init()
{
	consec[0] = isVowel(currMessage[0]) ?  0: 1;
	distToPrev[0] = -1;
	if (consec[0] >= currNValue) distToPrev[0] = currNValue - 1;	
	else distToPrev[0] = -1;
	if (distToPrev[0] == -1) posMinDistPlusOne[0] = -1;
	else posMinDistPlusOne[0] = 1;
	if (posMinDistPlusOne[0] == -1) total[0] = 0;
	else total[0] = posMinDistPlusOne[0];
}

void processCol(int col)
{
	consec[col] = isVowel(currMessage[col]) ?  0: consec[col-1] + 1;
	if (consec[col] >= currNValue) distToPrev[col] = currNValue - 1;	
	else if (distToPrev[col-1] == -1) distToPrev[col] = -1;
	else distToPrev[col] = distToPrev[col-1] + 1;
	if (distToPrev[col] == -1) posMinDistPlusOne[col] = -1;
	else posMinDistPlusOne[col] = col - distToPrev[col] + 1;
	if (posMinDistPlusOne[col] == -1) total[col] = 0;
	else total[col] = total[col-1] + posMinDistPlusOne[col];
	
}

void printCol(int col)
{
	printf("%d %d %d %d\n", consec[col], distToPrev[col], posMinDistPlusOne[col], total[col]);
}

int processCase()
{
	int messageCol;

	init();
//		printCol(0);

	for (messageCol=1; messageCol < currMessageLen; messageCol++)
	{
		processCol(messageCol);
//		printCol(messageCol);
	}

	return total[currMessageLen-1];
}

void runCase(int caseNum)
{
	int result;
	readCase();
	result = processCase();
	writeCase(caseNum, result);
}

void main()
{
	int numCases;
	int caseNum;

	scanf("%d", &numCases);
	flushLine();

	for (caseNum = 1; caseNum <= numCases; caseNum++)
	{
		runCase(caseNum);
		flushLine();
	}
}
