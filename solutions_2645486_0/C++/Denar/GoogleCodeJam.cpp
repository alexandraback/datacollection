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

#if 0
	int currUpgrade = N - 1;

	for (int i = N - 2; i >= 0; i--)
	{
		// Check if the one before is lower
		if (value[i] < value[currUpgrade])
		{
			if (opti[currUpgrade] < E)
			{
				int toMove;
				
				if (E - opti[currUpgrade] > opti[i])
				{
					toMove = opti[i];
				}
				else
				{
					toMove = E - opti[currUpgrade];
					currUpgrade = i;
				}

				opti[currUpgrade] += toMove;
				opti[i] -= toMove;
			}
			else
				currUpgrade = i;
		}
		else
		{
			currUpgrade = i;
		}
	}
#endif

	// Optimisation

	
#if 0
	int lookAhead = (E + R - 1) / R;
	int nLastBest = 0;

	if (R < E)
	{
		int i = 0;

		while (i < N)
		{
			int nValue = value[i];
			int k = 1;

			for (; k <= lookAhead; k++)
			{
				if (value[i + k] < nValue)
				{
					if (opti[i] < E)
					{
						int diff = E - opti[i];

						if (opti[i + k] < diff)
						{
							opti[i] += opti[i + k];
							opti[i + k] = 0;
						}
						else
						{

						}
					}
					else
					{
						break;
					}
				}
				else
					break;
			}

			nLastBest = i;
			i += k;
		}
	}
#endif

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
		nTotal += opti[i] * value[i];

	fprintf(fout, "Case #%d: %d\n", index, nTotal);
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

