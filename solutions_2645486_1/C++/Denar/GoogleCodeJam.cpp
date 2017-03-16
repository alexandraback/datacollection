// GoogleCodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "stdint.h"
#include "stdlib.h"
#include <vector>
#include <math.h>

using namespace std;

int opti[10000];
int accu[10000];

void solve(FILE* fout, int index, int E, int R, int N, int* value)
{
	for (int i = 0; i < N; i++)
		opti[i] = R;

	if (!R)
	{
		// special case

		int nMax = -1;
		int iMax = -1;

		for (int i = 0; i < N; i++)
		{
			if (value[i] > nMax)
			{
				nMax = value[i];
				iMax = i;
			}
		}

		fprintf(fout, "Case #%d: %d\n", index, nMax*E);

		return;
	}

	int nMax = -1;
	int iMax = -1;

	for (int i = 0; i < N; i++)
	{
		if (value[i] > nMax)
		{
			nMax = value[i];
			iMax = i;
		}
	}

	opti[iMax] = E;

	for (int i = 0; i < N; i++)
	{
		if (i <= iMax)
			accu[i] = E;
		else
			accu[i] = 0;
	}

	int lookAhead = (E + R - 1) / R;

	for (int k = 0; k < lookAhead; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i && value[i - 1] < value[i])
			{
				if (accu[i-1] < E)
				{
					int storage = E - accu[i-1];
					int diff = E - opti[i];

					int toMove = min(storage, diff);
					toMove = min(toMove, opti[i-1]);

					accu[i-1] += toMove;
					opti[i] += toMove;
					opti[i - 1] -= toMove;
				}
			}
			
			if (i < (N - 1) && value[i + 1] < value[i])
			{
				if (accu[i+1] > 0)
				{
					int storage = accu[i+1];
					int diff = E - opti[i];

					int toMove = min(storage, diff);
					toMove = min(toMove, opti[i+1]);

					accu[i+1] -= toMove;
					opti[i] += toMove;
					opti[i+1] -= toMove;
				}
			}
		}
	}

	int64_t nTotal = 0;

	for (int i = 0; i < N; i++)
		nTotal += static_cast<int64_t>(opti[i]) * static_cast<int64_t>(value[i]);

	fprintf(fout, "Case #%d: %lld\n", index, nTotal);
}

// Checker quelle peut etre la taille max d'une ligne
char buff[100000];
int value[10000];

int _tmain(int argc, _TCHAR* argv[])
{
	string fileToOpen = "input.txt";
	string fileToWrite = "output.txt";

	FILE* fp = fopen (fileToOpen.c_str(), "rb");
	if (!fp)
    {
		printf("Error: could not open file '%s'!\n", fileToOpen.c_str());
		return 0;
    }
	FILE* fout = fopen (fileToWrite.c_str(), "w");

	int numberOfTestCases;

	fgets(buff, sizeof (buff), fp);
	sscanf(buff, "%d", &numberOfTestCases);

	int index = 1;

	while (numberOfTestCases > 0)
	{
		int E, R, N;
		
		fgets(buff, sizeof (buff), fp);
		sscanf(buff, "%d %d %d", &E, &R, &N);

		fgets(buff, sizeof (buff), fp);
		char* currBuff = buff;

		for (int i = 0; i < N; i++)
		{
			value[i] = strtol(currBuff, &currBuff, 0);
		}

		solve(fout, index, E, R, N, value);
		printf("Solved test case %d\n", index);

		numberOfTestCases--;
		index++;
	}
}

