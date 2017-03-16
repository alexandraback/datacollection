/* 2016.4.9 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>

bool done[10];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int n;
		fscanf(fin, "%d", &n);

		if (n == 0)
		{
			fprintf(fout, "Case #%d: INSOMNIA\n", c_n);
			printf("Case #%d: INSOMNIA\n", c_n);
		}
		else
		{
			long long k = n;

			for (int i = 0; i < 10; i++)
				done[i] = false;
			int tot = 0;

			for (;;)
			{
				long long s = k;
				while (s > 0)
				{
					if (!done[s % 10])
					{
						done[s % 10] = true;
						tot += (s % 10) + 1;
					}
					s /= 10;
				}
				if (tot == 55) break;
				k += n;
			}
			fprintf(fout, "Case #%d: %lld\n", c_n, k);
			printf("Case #%d: %lld\n", c_n, k);
		}
	}
	return -0;
}
