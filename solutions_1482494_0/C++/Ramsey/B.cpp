#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const char inFileName[] = "B-small.in";
const char outFileName[] = "B-small.out";

const int MaxN = 1020;

struct Level
{
	int a, b;
};

bool cmp(const Level& A, const Level& B)
{
	return A.b < B.b;
}

int T, n,s, p;
Level levels[MaxN];
bool mark[MaxN];

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%d", &n);
		for (int i = 0; i < n; i++) fscanf(inFile, "%d%d", &levels[i].a, &levels[i].b);
		sort(levels, levels + n, cmp);
		memset(mark, false, sizeof(mark));
		
		int currPoints = 0;
		int sol = n;
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			while (levels[i].b > currPoints)
			{
				int j = n - 1;
				while (j >= i && (mark[j] || levels[j].a > currPoints)) j--;
				if (j < i)
				{
					ok = false;
					break;
				}
				sol++;
				currPoints++;
				mark[j] = true;
			}

			if (ok)
			{
				currPoints += (mark[i] ? 1 : 2);
			}
			else break;
		}

		if (ok)
			fprintf(outFile, "Case #%d: %d\n", t + 1, sol);
		else
			fprintf(outFile, "Case #%d: Too Bad\n", t + 1);
	}
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
