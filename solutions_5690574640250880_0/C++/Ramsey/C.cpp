#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "C-small.in";
const char outFileName[] = "C-small.out";

const int MaxN = 100;

int T, r, c, m;
char a[MaxN][MaxN];

void output(FILE* outFile, int t)
{
	fprintf(outFile, "Case #%d:\n", t + 1);
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			fprintf(outFile, "%c", a[i][j]);
		fprintf(outFile, "\n");
	}
}

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%d%d%d", &r, &c, &m);
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				a[i][j] = '*';

		int x = r * c - m;
		a[1][1] = 'c';

		if (x == 1)
		{
			output(outFile, t);
			continue;
		}

		if (r == 1)
		{
			for (int i = 2; i <= x; i++) a[1][i] = '.';
			output(outFile, t);
			continue;
		}
		if (c == 1)
		{
			for (int i = 2; i <= x; i++) a[i][1] = '.';
			output(outFile, t);
			continue;
		}

		if (x == 2 || x == 3 || x == 5 || x == 7)
		{
			fprintf(outFile, "Case #%d:\nImpossible\n", t + 1);
			continue;
		}

		if (r == 2)
		{
			if (x % 2 == 0)
			{
				for (int i = 1; i <= x / 2; i++) a[1][i] = a[2][i] = '.';
				a[1][1] = 'c';
				output(outFile, t);
			}
			else
			{
				fprintf(outFile, "Case #%d:\nImpossible\n", t + 1);
			}
			continue;
		}

		if (c == 2)
		{
			if (x % 2 == 0)
			{
				for (int i = 1; i <= x / 2; i++) a[i][1] = a[i][2] = '.';
				a[1][1] = 'c';
				output(outFile, t);
			}
			else
			{
				fprintf(outFile, "Case #%d:\nImpossible\n", t + 1);
			}
			continue;
		}
		
		int half = x / 2;
		for (int i = 1; i <= min(r, half); i++)
		{
			a[i][1] = a[i][2] = '.';
			x = x - 2;
		}

		int ind = 0;
		for (int j = 3; j <= c && x > 0; j++)
		{
			for (int i = 1; i <= r && x > 0; i++)
			{
				a[i][j] = '.';
				x--;
				if (x == 0 && ind == 0) ind = j;
			}
		}

		a[1][1] = 'c';
		if (ind <= c && a[1][ind] == '.' && a[2][ind] == '*')
		{
			if (ind == 3)
			{
				a[2][ind] = '.';
				a[3][ind] = '.';
				a[min(r, half)][1] = '*';
				a[min(r, half)][2] = '*';
			}
			else
			{
				a[2][ind] = '.';
				a[min(r, half)][ind - 1] = '*';
			}
		}

		output(outFile, t);
	}	
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
