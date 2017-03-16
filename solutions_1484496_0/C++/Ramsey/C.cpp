#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const char inFileName[] = "C-small.in";
const char outFileName[] = "C-small.out";

const int MaxN = 25;
const int MaxS = 2000100;

int T, n, x;
int s[MaxN];
int mark[MaxS];

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%d", &n);
		for (int i = 0; i < n; i++) fscanf(inFile, "%d", &s[i]);
		
		memset(mark, 0, sizeof(mark));

		int m1, m2;
		bool found = false;

		for (int bitMask = 1; bitMask < (1 << n) && !found; bitMask++)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
				if (bitMask & (1 << i)) sum += s[i];
			if (mark[sum] == 0)
				mark[sum] = bitMask;
			else
			{
				m1 = mark[sum];
				m2 = bitMask;
				found = true;
			}
		}

		fprintf(outFile, "Case #%d:\n", t + 1);
		if (found)
		{
			for (int i = 0; i < n; i++)
				if (m1 & (1 << i)) fprintf(outFile, "%d ", s[i]);
			fprintf(outFile, "\n");
			for (int i = 0; i < n; i++)
				if (m2 & (1 << i)) fprintf(outFile, "%d ", s[i]);
			fprintf(outFile, "\n");
		}
		else
		{
			fprintf(outFile, "Impossible\n");
		}

	}
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
