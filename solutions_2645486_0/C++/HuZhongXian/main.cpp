#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if(a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if(a < b) return a; else return b; }
template <class T> T ABS(T a) { if(a < 0) return -a; else return a; }

#define MAX_STR_NUM 256

int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "B-small-attempt0.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int T;
	int E, R, N, v[10001];
	long long dp[2][10], maxG;
	fscanf(input, "%d\n", &T);
	for (int i = 1; i <= T; ++i)
	{
		fscanf(input, "%d %d %d\n", &E, &R, &N);
		for (int j = 0; j < N; ++j)
		{
			fscanf(input, "%d", &v[j]);
		}
		fscanf(input, "\n");

		maxG = 0;
		memset(dp, -1, sizeof(dp));
		dp[1][E] = 0;
		for (int n = 0; n < N; ++n)
		{
			memcpy(dp[0], dp[1], sizeof(dp[1]));
			memset(dp[1], -1, sizeof(dp[1]));
			for (int e = 0; e <= E; ++e)
			{
				if (dp[0][e] >= 0)
				{
					for (int se = 0; se <= e; ++se)
					{
						int tE = MIN(E, e - se + R);
						dp[1][tE] = MAX(dp[1][tE], dp[0][e] + se * v[n]);
						maxG = MAX(maxG, dp[1][tE]);
					}
				}
			}
		}

		fprintf(output, "Case #%d: %lld\n", i, maxG);
	}

	fclose(output);
	fclose(input);

	//system("pause");
	return 0;
}