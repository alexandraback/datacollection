// GoogleCodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "stdint.h"
#include "stdlib.h"
#include <vector>
#include <math.h>

using namespace std;


void solve(FILE* fout, int index, int N, int X, int Y)
{
	double prob = 0.0;

	int nPyramidSizeInf = 0;
	int nPyramidSizeSup = 1;
	int nPyramidIndex = -1;

	if (!N)
	{
		fprintf(fout, "Case #%d: %llf\n", index, prob);
		return;
	}

	while (nPyramidSizeSup <= N)
	{
		nPyramidSizeInf = nPyramidSizeSup;
		nPyramidSizeSup += nPyramidSizeSup * 2 + 1 + 2;
		nPyramidIndex++;
	}

	// nPyramidSizeSup = size of the pyramid we are building
	// nPyramidSizeInf = size of the pyramid already existing
	// nPyramidIndex = Y max of the Pyramid Inf.

	if (Y + abs(X) <= nPyramidIndex * 2)
		prob = 1.0;
	else if (Y + abs(X) >= (nPyramidIndex + 2) * 2)
		prob = 0.0;
	else if (Y == (nPyramidIndex + 1) * 2)
		prob = 0.0;
	else if (N == nPyramidSizeSup - 1)
		prob = 1.0;
	else
	{
		// Here, Y + abs(X) = (nPyramidIndex + 1) * 2

		// Hard case, we are on the pyramid face being built
		int nBlocks = N - nPyramidSizeInf;

		if (nBlocks <= Y)
			prob = 0.0;
		else if (nBlocks >= ((nPyramidIndex + 1) * 2) + Y)
			prob = 1.0;
		else
		{	
			double* dSpots = (double*)malloc(sizeof(double) * (nBlocks + 1));
			dSpots[0] = 1.0;

			for (int n = 1; n < nBlocks + 1; n++)
				dSpots[n] = 0.0;

			for (int i = 0; i < nBlocks; i++)
				if (i < (nPyramidIndex + 1) * 2)
				{
					for (int n = i + 1; n > 0; n--)
						dSpots[n] += (dSpots[n-1] - dSpots[n]) * 0.5;
				}
				else
				{
					int n = i - (nPyramidIndex + 1) * 2;

					double diff = 1.0 - dSpots[n + 1];

					for (; n < nBlocks - 1; n++)
						dSpots[n + 1] += diff;
				}


			prob = dSpots[Y + 1];
		}
	}


	fprintf(fout, "Case #%d: %llf\n", index, prob);
}

// Checker quelle peut etre la taille max d'une ligne
char buff[10000*8];

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
		int N, X, Y;
		
		fgets(buff, sizeof (buff), fp);
		sscanf(buff, "%d %d %d", &N, &X, &Y);

		solve(fout, index, N, X, Y);
		printf("Solved test case %d\n", index);

		numberOfTestCases--;
		index++;
	}
}

