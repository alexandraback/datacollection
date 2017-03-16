#include <stdio.h>

int adj[51][51];

void makeFull(int n)
{
	int i, j;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= n;j++)
			adj[i][j] = 0;
	for (i = 2;i <= n;i++)
		for (j = i + 1;j <= n;j++)
			adj[i][j] = 1;
}

int main()
{
	FILE *fpw, *fpr;
	fpw = fopen("BK_output.txt", "w");
	fpr = fopen("B-large.in", "r");

	int ii, test, index;
	int j, b, m, i, num;

	fscanf(fpr, "%d", &test);
	for (ii = 1;ii <= test;ii++)
	{
		fprintf(fpw, "Case #%d: ", ii);
		fscanf(fpr, "%d %d", &b, &m);
		if (b == 2 && m > 1)
		{
			fprintf(fpw, "IMPOSSIBLE\n");
			continue;
		}
		if (b == 2 && m == 1)
		{
			fprintf(fpw, "POSSIBLE\n");
			fprintf(fpw, "01\n00\n");
			continue;
		}
		for (i = 0, num = 1;i < b - 2;i++)
			num *= 2;

		if (m > num)
		{
			fprintf(fpw, "IMPOSSIBLE\n");
			continue;
		}
		fprintf(fpw, "POSSIBLE\n");
		makeFull(b);
		if (m == num)
		{
			for (i = 2;i <= b;i++)
				adj[1][i] = 1;
			for (i = 1;i <= b;i++)
			{
				for (j = 1;j <= b;j++)
					fprintf(fpw, "%d", adj[i][j]);
				fprintf(fpw, "\n");
			}
			continue;
		}
		index = 2;
		num /= 2;
		while (m > 0) // b>2
		{
			if (m >= num)
			{
				m -= num;
				adj[1][index] = 1;
			}
			num /= 2;
			index++;
		}
		for (i = 1;i <= b;i++)
		{
			for (j = 1;j <= b;j++)
				fprintf(fpw, "%d", adj[i][j]);
			fprintf(fpw, "\n");
		}
	}

	fclose(fpw);
	fclose(fpr);
	return 0;
}