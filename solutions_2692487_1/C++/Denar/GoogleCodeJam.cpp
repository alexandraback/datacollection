// GoogleCodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "stdint.h"
#include "stdlib.h"
#include <vector>
#include <math.h>

using namespace std;

int findMin(vector<int>& sizes)
{
	int nMin = sizes[0];
	int nIndexMin = 0;
	
	for (int i = 1; i < sizes.size(); i++)
	{
		if (sizes[i] < nMin)
		{
			nMin = sizes[i];
			nIndexMin = i;
		}
	}

	return nIndexMin;
}

void solve(FILE* fout, int index, int A, int N, vector<int>& sizes)
{
	// Worst case, we can delete all motes
	int nOpMax = N;
	int64_t nCurr = A;
	int nChanges = 0;
	int nConsecutiveChanges = 0;

	while (sizes.size() > 0)
	{
		int nIndexMin = findMin(sizes);

		if (sizes[nIndexMin] < nCurr)
		{
			nCurr += sizes[nIndexMin];
			sizes.erase(sizes.begin() + nIndexMin);
			nConsecutiveChanges = 0;
		}
		else
		{
			// Add a nCurr - 1 mote
			nCurr = 2 * nCurr - 1;
			nConsecutiveChanges++;
			nChanges++;

			// If we could stop it here
			// By deleting all the remaining ones
			// Instead of adding new ones
			if (nConsecutiveChanges == sizes.size())
				break;
		}
	}

	sizes.clear();

	if (nChanges > nOpMax)
		nChanges = nOpMax;

	fprintf(fout, "Case #%d: %d\n", index, nChanges);
}

// Checker quelle peut etre la taille max d'une ligne
char buff[10000*8];
vector<int> sizes;

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
		int A, N;
		
		fgets(buff, sizeof (buff), fp);
		sscanf(buff, "%d %d", &A, &N);

		fgets(buff, sizeof (buff), fp);
		char* currBuff = buff;

		for (int i = 0; i < N; i++)
		{
			sizes.push_back(strtol(currBuff, &currBuff, 0));
		}

		solve(fout, index, A, N, sizes);
		printf("Solved test case %d\n", index);

		numberOfTestCases--;
		index++;
	}
}

