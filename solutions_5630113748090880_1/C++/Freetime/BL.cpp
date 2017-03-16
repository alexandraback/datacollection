#include <stdio.h>
#include <algorithm>

int main()
{
	FILE *fp_r, *fp_w;
	fp_r = fopen("B-large.in", "r");
	fp_w = fopen("BL_output.txt", "w");
	int ii, test, i, j, x, list[2501], n, ans[50], index;

	fscanf(fp_r, "%d", &test);
	for (ii = 1;ii <= test;ii++)
	{
		for (i = 0;i < 2501;i++)
			list[i] = 0;
		index = 0;
		fprintf(fp_w, "Case #%d:", ii);
		fscanf(fp_r, "%d", &n);
		for (i = 0;i < 2 * n - 1;i++)
			for (j = 0;j < n;j++)
			{
				fscanf(fp_r, "%d", &x);
				list[x]++;
			}
		for (i = 1;i < 2501;i++)
			if (list[i] % 2 == 1)
				ans[index++] = i;
		for (i = 0;i < index - 1;i++)
		{
			x = i;
			for (j = i + 1;j < index;j++)
				if (ans[j] < ans[x])
					x = j;
			j = ans[x];
			ans[x] = ans[i];
			ans[i] = j;
		}
		for (i = 0;i < index;i++)
			fprintf(fp_w, " %d", ans[i]);
		fprintf(fp_w, "\n");
	}


	fclose(fp_r);
	fclose(fp_w);
	return 0;
}