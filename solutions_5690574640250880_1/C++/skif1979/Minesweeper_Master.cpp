#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>       
#include <math.h> 
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double time_to_get_farm(int farm_number, double C, double F, double X)
{
	double d = 0;
	for (int i = 1; i <= farm_number; i++)
		d += C / (2 + (i - 1) * F);
	return d;
}


int main()
{
	FILE *infile;
	if (fopen_s(&infile, "C-large.in", "r+"))
	{
		cout << "Error opening input file ";
		return getchar();
	}

	ofstream outfile("7.out", std::ios::out);
	if (outfile.bad())
	{
		cout << "Error opening output file ";
		return getchar();
	}

	int tcNumber;
	fscanf_s(infile, "%i\n", &tcNumber);

	for (int tc = 1; tc <= tcNumber; tc++)
	{
		int R, C, M;
		fscanf_s(infile, "%d %d %d\n", &R, &C, &M);
		int free = R*C - M;
		char cc[50 * 50];
		memset(cc, '*', 50 * 50);
		bool possible = true;

		if (M == 0)
		{
			for (int i = 0; i < R*C; i++)
				cc[i] = '.';
		}
		else if ((R == 1) || (C == 1))
		{
			for (int i = 0; i < free; i++)
					cc[i] = '.';
		}
		else if (free == 1)
		{
			possible = true;
		}
		else if ((free == 2) || (free == 3) || (free == 5) || (free == 7))
		{
			possible = false;
		}
		else if (fmod(free, 2) == 0)  // we have free cells = (odd numbers >= 4),  R >= 2 and C >= 2
		{
			int i = 0;
			for (i = 0; i < R; i += 2)
			{
				if ((free <= 2) || (i + 1 >= R))
					break;
				
				for (int j = 0; j < C; j++)  // we should fill 2 rows
				{
					if (free <= 0) 
						break;
	
					cc[i*C + j] = '.';
					cc[(i + 1)*C + j] = '.';
					free -= 2;
				}
			}

			if (free > 0)
			{
				for (int j = 0; j < free; j++)
					cc[i*C + j] = '.';
			}
		}
		else  // even numbers >= 9
		{
			if ((R <= 2) || (C <= 2))
			{
				possible = false;
			}
			else    // we have free cells = (even numbers >= 9),  R >= 3 and C >= 3
			{
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						cc[i*C + j] = '.';
				free -= 9;				
				
				for (int i = 0; i < R; i += 2)
				{
					if (free <= 0)
						break;

					for (int j = 0; j < C; j++)  // we should fill 2 rows
					{
						if (free <= 0)
							break;

						if (cc[i*C + j] == '*')
						{
							cc[i*C + j] = '.';
							free--;
						}

						if ((free > 0) && (i + 1 < R) && (cc[(i+1)*C + j] == '*'))
						{
							if ((free == 2) && (j + 1 == C))
							{
								break;
							}
							cc[(i + 1)*C + j] = '.';
							free--;
						}
					}
				}
			}
		}	

		cc[0] = 'c';

		// printing
		outfile << "Case #" << tc << ":" << endl;
		if (possible)
		{
			int checksum = 0;
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					outfile << cc[i*C + j];
					if (cc[i*C + j] == '*')
						checksum++;
				}
				outfile << endl;
			}
			if (checksum != M)
			{
				cout << "ERROR! M=" << M << endl;
				cout << "checksum=" << checksum << endl;
			}
		}
		else
		{
			outfile << "Impossible" << endl;
		}
	}

	cout << "DONE" << endl;
	//outfile   cout
	outfile.close();
	return getchar();
}





/*
else    // we have free cells = (even numbers >= 9),  R >= 3 and C >= 3
{
int i = 0;
for (i = 0; i < R; i += 2)
{
if (i + 1 >= R)
break;

for (int j = 0; j < C; j++)  // we should fill 2 rows
{
if (free <= 1)
break;

if ((free <= 3) && (j > 2))
{
i += 2;
break;
}

cc[i*C + j] = '.';
cc[(i + 1)*C + j] = '.';
free -= 2;
}

if (free <= 3)
break;
}

if (free > 0)
{
for (int k = 0; k < C; k++)
{
if (free <= 0)
break;

if (cc[i*C + k] == '*')
{
cc[i*C + k] = '.';
free--;
}
}
}

}
*/