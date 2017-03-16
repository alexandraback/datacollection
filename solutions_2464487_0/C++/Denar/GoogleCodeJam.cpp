// GoogleCodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "stdint.h"
#include "stdlib.h"
#include <vector>
#include <math.h>

using namespace std;

#define PI (3.141592653589793)

void solve(FILE* fout, int index, int64_t r, int64_t t)
{
	int64_t paint = 0;
	int x = 0;

	while (paint <= t)
	{
		x++;
		int64_t sum2 = x*(2*r + 2 * (x - 1));
		paint = (sum2 + x);
	}

	x--;

	fprintf(fout, "Case #%d: %d\n", index, x);
}

// Checker quelle peut etre la taille max d'une ligne
char buff[1024];

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
		int64_t r, t;
		
		fgets(buff, sizeof (buff), fp);
		sscanf(buff, "%lld %lld", &r, &t);

		solve(fout, index, r, t);
		printf("Solved test case %d\n", index);

		numberOfTestCases--;
		index++;
	}
}

