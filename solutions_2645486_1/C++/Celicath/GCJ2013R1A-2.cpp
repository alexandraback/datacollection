/* 2013.4.27 Yoshi-TS4 */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int V[30000];
int min[20000];
int max[20000];

int compare(const void* a, const void* b)
{
	const int* i1 = static_cast<const int*>(a);
	const int* i2 = static_cast<const int*>(b);

	return i2[0] - i1[0];
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;
	__int64 E, R, N;

	fscanf(fin, "%d", &T);

	for(int a = 1; a <= T; a++)
	{
		fscanf(fin, "%lld%lld%lld", &E, &R, &N);
		for(int i = 0; i < N; i++)
		{
			fscanf(fin, "%d", V + 2 * i);
			V[2*i+1] = i;
			min[i] = 0;
			max[i] = E;
		}

		qsort(V, N, 8, compare);

		__int64 sum = 0;

		for(int i = 0; i < N; i++)
		{
			int index = V[2*i+1];

			sum += (__int64)V[2*i] * (__int64)(max[index] - min[index]);
			int tmp = max[index];
			max[index] = min[index];
			for(int j = index - 1; j >= 0; j--)
			{
				tmp -= R;
				if(tmp <= 0) break;
				if(max[j] == min[j]) break;
				min[j] = tmp;
			}
			tmp = min[index];
			for(int j = index + 1; j < N; j++)
			{
				tmp += R;
				if(tmp >= E) break;
				if(max[j] == min[j]) break;
				max[j] = tmp;
			}
		}

		fprintf(fout, "Case #%d: %lld\n", a, sum);
	}

	return -0;
}
