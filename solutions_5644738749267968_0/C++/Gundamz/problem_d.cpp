#include <stdio.h>
#include <algorithm>

#define MAXSIZE 1000

double weightA[MAXSIZE];
double weightB[MAXSIZE];

int main()
{
	for (int m = 0; m < MAXSIZE; m++)
	{
			weightA[m] = 0.0;
			weightB[m] = 0.0;
	}
	int num_of_test;
	FILE *f = fopen("D-small-attempt0.in", "r");
	FILE *out = fopen("D-small-attempt0.out", "w");
	fscanf(f, "%d", &num_of_test);
	for (int i = 1; i <= num_of_test; i++)
	{
		int win_cheat = 0;
		int win_normal = 0;
		// read
		int N = 0;
		fscanf(f, "%d", &N);
		for (int m = 0; m < N; m++)
			fscanf(f, "%lf", &weightA[m]);
		for (int m = 0; m < N; m++)
			fscanf(f, "%lf", &weightB[m]);
		// War optimally
		// 不作弊情况下最优策略就是从最小出起
		std::sort(weightA, weightA+N);
		std::sort(weightB, weightB+N);
#if 0
		for (int m = 0; m < N; m++)
			printf("%lf  ", weightA[m]);
		printf("\n");
		for (int m = 0; m < N; m++)
			printf("%lf  ", weightB[m]);
		printf("\n");
#endif
		int index_A = 0;
		for (int m = 0; m < N; m++)
		{
			if (index_A < N)
			{
				if (weightB[m] > weightA[index_A])
					index_A++;
			}
		}
		win_normal = N - index_A;
		int index_B = 0;
		for (int m = 0; m < N; m++)
		{
			if (index_B < N)
			{
				if (weightA[m] > weightB[index_B])
				{
					win_cheat++;
					index_B++;
				}
			}
		}
		fprintf(out, "Case #%d: %d %d\n", i, win_cheat, win_normal);
	}
	fclose(f);
	fclose(out);
}