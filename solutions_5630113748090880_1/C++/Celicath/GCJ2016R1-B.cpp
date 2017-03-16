/* 2016.4.16 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>

int result[10000];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);


	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;
		fscanf(fin, "%d", &N);

		std::map<int, int> map;

		for (int i = 0; i < 2 * N - 1; i++)
			for (int j = 0; j < N; j++)
			{
				int tmp;
				fscanf(fin, "%d", &tmp);
				map[tmp]++;
			}

		int pointer = 0;
		for (auto p : map)
		{
			if (p.second % 2 == 1)
				result[pointer++] = p.first;
		}

		fprintf(fout, "Case #%d:", c_n);
		printf("Case #%d:", c_n);
		for (int i = 0; i < N; i++)
		{
			fprintf(fout, " %d", result[i]);
			printf(" %d", result[i]);
		}
		fprintf(fout, "\n");
		printf("\n");
	}
	return -0;
}
