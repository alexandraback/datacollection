/* 2016.4.9 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>

char line[105];
int divs[11];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int K, C, S;
		fscanf(fin, "%d%d%d", &K, &C, &S);

		if (C*S >= K)
		{
			fprintf(fout, "Case #%d:", c_n);
			printf("Case #%d:", c_n);
			int until = 0;
			for (int i = 0; i < S; i++)
			{
				long long num = 0;

				long long mult = 1;
				for (int j = 0; j < C; j++)
				{
					if (until < K)
					{
						num += until * mult;
						until++;
						mult *= K;
					}
				}

				printf(" %lld", num + 1);
				fprintf(fout, " %lld", num + 1);
				if (until >= K)
					break;
			}
			printf("\n");
			fprintf(fout, "\n");
		}
		else
		{
			fprintf(fout, "Case #%d: IMPOSSIBLE\n", c_n);
			printf("Case #%d: IMPOSSIBLE\n", c_n);
		}

	}
	return -0;
}
