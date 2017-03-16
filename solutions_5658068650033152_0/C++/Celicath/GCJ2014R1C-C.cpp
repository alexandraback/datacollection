/* 2014.5.11 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <stdint.h>

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N, M, K;

		fscanf(fin, "%d%d%d", &N, &M, &K);

		if (M > N)
		{
			int temp = M;
			M = N;
			N = temp;
		}
		int result = K;
		for (int i = 3; i <= M; i++)
		for (int j = i; j <= N; j++)
		{
			int maxfill = (i * j) - 4;
			if (K > maxfill)
			{
				int stones = 2 * (i + j - 4) + K - maxfill;
				result = std::min(result, stones);
			}
			else
			{
				int stone = 2 * j - 2;
				int fill = (i * i + 1) / 2 + i * (j - i);
				int next = i / 2;
				int pivot = (i % 2) ? 4 : 2;

				while (true)
				{
					if (K <= fill)
					{
						result = std::min(result, stone);
						break;
					}

					stone++;
					fill += next;
					if (--pivot == 0)
					{
						pivot = 4;
						next--;
					}
				}
			}
		}

		fprintf(fout, "Case #%d: %d\n", c_n, result);
		printf("Case #%d: %d\n", c_n, result);
	}
	return -0;
}
