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
	sprintf(filename[0], "%s", "B-large.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int T, N, M, a[100][100], b[100][100];
	fscanf(input, "%d\n", &T);
	for(int i = 1; i <= T; ++i)
	{
		memset(a, 100, sizeof(a));
		memset(b, 100, sizeof(b));
		fscanf(input, "%d %d\n", &N, &M);
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				fscanf(input, "%d", &a[r][c]);
			}
			fscanf(input, "\n");
		}
		bool valid = true;
		for (int r = 0; valid && r < N; ++r)
		{
			for (int c = 0; valid && c < M; ++c)
			{
				bool rV = true;
				for (int i = 0; i < N && (rV = a[r][c] >= a[i][c]); ++i);
				bool cV = true;
				for (int i = 0; i < M && (cV = a[r][c] >= a[r][i]); ++i);
				if ((valid = (rV || cV)))
				{
					if (rV)
					{
						for (int i = 0; i < N; ++i)
							b[i][c] = MIN(b[i][c], a[r][c]);
					}
					if (cV)
					{
						for (int i = 0; i < M; ++i)
							b[r][i] = MIN(b[r][i], a[r][c]);
					}
				}
			}
		}
		if (valid)
		{
			valid = (memcmp(a, b, sizeof(a)) == 0);
		}
		fprintf(output, "Case #%d: %s\n", i, valid ? "YES" : "NO");
	}

	fclose(output);
	fclose(input);

	return 0;
}