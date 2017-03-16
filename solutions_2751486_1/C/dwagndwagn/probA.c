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

long long int distToPrev[2000000];
long long int posMinDistPlusOne[2000000];
long long int total[2000000];
long long int consec[2000000];



char currMessage [2000000];
long long int currMessageLen;
long long int currNValue;

char strTemp [2000000];




void flushLine()
{
	gets(strTemp);
}

void readCase()
{
	scanf("%s", currMessage);
	currMessageLen = strlen(currMessage);
	scanf("%lld", &currNValue);
}

void writeCase(long long int caseNum, long long int result)
{
	printf("Case #%lld: %lld\n", caseNum, result );
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

void processCol(long long int col)
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

void printCol(long long int col)
{
	printf("%lld %lld %lld %lld\n", consec[col], distToPrev[col], posMinDistPlusOne[col], total[col]);
}

long long int processCase()
{
	long long int messageCol;

	init();
//		printCol(0);

	for (messageCol=1; messageCol < currMessageLen; messageCol++)
	{
		processCol(messageCol);
//		printCol(messageCol);
	}

	return total[currMessageLen-1];
}

void runCase(long long int caseNum)
{
	long long int result;
	readCase();
	result = processCase();
	writeCase(caseNum, result);
}

void main()
{
	long long int numCases;
	long long int caseNum;

	scanf("%lld", &numCases);
	flushLine();

	for (caseNum = 1; caseNum <= numCases; caseNum++)
	{
		runCase(caseNum);
		flushLine();
	}
}
