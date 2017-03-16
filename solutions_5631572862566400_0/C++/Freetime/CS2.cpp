#include <stdio.h>

int main()
{
	FILE *fp_r, *fp_w;
	fp_r = fopen("C-small-attempt1.in", "r");
	fp_w = fopen("CS_output2.txt", "w");
	int ii, test, n, i, j, list[1001], sum, max, check[1001], prev, k;

	fscanf(fp_r, "%d", &test);
	for (ii = 1;ii <= test;ii++)
	{
		fprintf(fp_w, "Case #%d: ", ii);
		fscanf(fp_r, "%d", &n);
		for (i = 1;i <= n;i++)
			fscanf(fp_r, "%d", &list[i]);
		for (i = 1, max = 0;i <= n;i++)
		{
			for (j = 0;j < 1001;j++)
				check[j] = 0;
			j = i;
			sum = 1;
			check[j] = 1;
			while (check[list[j]] == 0)
			{
				sum++;
				prev = j;
				check[list[j]] = 1;
				j = list[j];
			}
			if (i == list[j])
			{
				if (sum > max)
					max = sum;
			}
			else if (prev == list[j])
			{
				while (1)
				{
					for (k = 1;k <= n;k++)
						if (list[k] == j && check[k] == 0)
							break;
					if (k <= n)
					{
						sum++;
						j = k;
					}
					else
						break;
				}
				if (sum > max)
					max = sum;
			}
		}
		fprintf(fp_w, "%d\n", max);
	}


	fclose(fp_r);
	fclose(fp_w);
	return 0;
}