// GoogleCodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "stdint.h"
#include "stdlib.h"
#include <vector>
#include <math.h>

using namespace std;


void solve(FILE* fout, int index, int E, int R, int N, int* value)
{


	
}

// Checker quelle peut etre la taille max d'une ligne
char buff[100000];
int product[10000];

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
		int R, N, M, K;
		
		fgets(buff, sizeof (buff), fp);
		sscanf(buff, "%d %d %d %d", &R, &N, &M, &K);

		fprintf(fout, "Case #%d:\n", index);

		while (R > 0)
		{
			fgets(buff, sizeof (buff), fp);
			char* currBuff = buff;

			bool isEven = false;
			bool isThree = false;
			bool isFour = false;
			bool isFive = false;
			bool isNine = false;
			bool is25 = false;
			bool is125 = false;

			bool isNeverNot4 = false;
			bool isNeverNot25 = false;

			for (int i = 0; i < K; i++)
			{
				product[i] = strtol(currBuff, &currBuff, 0);

				if (product[i] == 1)
					continue;

				if (product[i] % 4)
					isNeverNot4 = true;

				if (product[i] % 25)
					isNeverNot25 = true;

				if (!(product[i] % 2))
					isEven = true;

				if (!(product[i] % 3))
					isThree = true;

				if (!(product[i] % 4))
					isFour = true;

				if (!(product[i] % 5))
					isFive = true;

				if (!(product[i] % 9))
					isNine = true;

				if (!(product[i] % 25))
					is25 = true;

				if (!(product[i] % 125))
					is125 = true;
			}

			if (isEven && isThree && isFive)
			{
				fprintf(fout, "235\n", index);
				R--;
				continue;
			}
			else if (isFive && !isThree)
			{
				if (isNeverNot25 && isEven && isNeverNot4)
				{
					fprintf(fout, "255\n", index);
					R--;
					continue;
				}
				else if (isNeverNot25 && isEven)
				{
					fprintf(fout, "455\n", index);
					R--;
					continue;
				}
			}
			else
			{
				fprintf(fout, "244\n", index);
				R--;
			}
		}
		


		printf("Solved test case %d\n", index);

		numberOfTestCases--;
		index++;
	}
}

