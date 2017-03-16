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
	sprintf(filename[0], "%s", "A-small-attempt1.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int T;
	int A, N, motes[100];
	fscanf(input, "%d\n", &T);
	for (int i = 1; i <= T; ++i)
	{
		fscanf(input, "%d %d\n", &A, &N);
		for (int j = 0; j < N; ++j)
		{
			fscanf(input, "%d", &motes[j]);
		}
		fscanf(input, "\n");

		if (A == 1)
		{
			fprintf(output, "Case #%d: %d\n", i, N);
		}
		else
		{
			//int tA = A;
			int ret = N;
			std::sort(motes, motes + N);
			int t = 0;
			for (int j = 0; j < N;)
			{
				ret = MIN(ret, t + (N - j));
				if (A > motes[j])
				{
					A += motes[j];
					++j;
				}
				else
				{
					A += A - 1;
					++t;
				}
			}
			ret = MIN(ret, t);
			fprintf(output, "Case #%d: %d\n", i, ret);
			/*
			printf("%d:%d\n", tA, ret);
			for (int j = 0; j < N; ++j)
			{
				printf("%d ", motes[j]);
			}
			printf("\n");
			*/
		}
		
	}

	fclose(output);
	fclose(input);

	//system("pause");
	return 0;
}