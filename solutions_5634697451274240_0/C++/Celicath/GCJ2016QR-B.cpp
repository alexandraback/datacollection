/* 2016.4.9 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>

char line[105];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int n;
		fscanf(fin, "%s", line);

		char prev = line[0];
		int tot = 0;
		for (int i = 1; line[i]; i++)
		{
			if (line[i] != prev)
			{
				tot++;
				prev = line[i];
			}
		}
		if (prev == '-')
			tot++;

		fprintf(fout, "Case #%d: %d\n", c_n, tot);
		printf("Case #%d: %d\n", c_n, tot);
	}
	return -0;
}
