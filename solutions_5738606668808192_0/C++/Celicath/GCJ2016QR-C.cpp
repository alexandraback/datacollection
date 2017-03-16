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
		int n, j;
		fscanf(fin, "%d %d", &n, &j);

		fprintf(fout, "Case #%d:\n", c_n);
		printf("Case #%d:\n", c_n);

		int tot = 0;
		int line[40];
		line[0] = line[n - 1] = 1;
		for (int m = 0; m < (1 << (n - 2)); m++)
		{
			for (int i = 1; i < n - 1; i++)
			{
				line[i] = 0;
			}
			int tm = m;
			for (int i = 1; tm > 0; i++)
			{
				line[i] = tm % 2;
				tm >>= 1;
			}

			for (int i = 2; i <= 10; i++)
			{
				bool done = false;
				for (int k = 3; k <= 200; k += 2)
				{
					int num = 0;
					int mult = 1;
					for (int l = 0; l < n; l++)
					{
						num += mult * line[l];
						mult = (mult * i) % k;
					}

					if (num % k == 0)
					{
						divs[i] = k;
						done = true;
						break;
					}
				}
				if (!done) goto hell;
			}
			tot++;
			printf("%d %d ", tot, j);

			for (int i = n - 1; i >= 0; i--)
			{
				printf("%d", line[i]);
				fprintf(fout, "%d", line[i]);
			}
			for (int i = 2; i <= 10; i++)
			{
				printf(" %d", divs[i]);
				fprintf(fout, " %d", divs[i]);
			}
			printf("\n");
			fprintf(fout, "\n");
			if (tot >= j)
				break;
		hell:;
		}
	}
	return -0;
}
