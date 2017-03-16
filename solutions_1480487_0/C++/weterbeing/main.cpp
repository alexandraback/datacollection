#include <stdio.h>
#include <math.h>
int main()
{
	FILE *fin, *fout;
	fin = fopen("A-small-attempt2.in", "r");
	fout = fopen("out.txt","w");
	int T, i;

	fscanf(fin, "%d", &T);
	for (i = 0; i < T; i++)
	{
		int N, j, X = 0, p, min, pre, num;
		int s[200];
		bool d[200];
		double left = 1, piao[200];
		fscanf(fin, "%d", &N);
		for (j = 0; j < N; j++)
		{
			d[j] = false;
			piao[j] = 0;
		}

		for (j = 0; j < N; j++)
		{
			fscanf(fin, " %d", &s[j]);
			X += s[j];
		}
		min = 2147483647;
		for (j = 0; j < N; j++)
		{
			if (s[j] <= min) 
			{
				p = j;
				min = s[j];
			}
		}
		pre = s[p];
		d[p] = true;
		num = 1;
		while ((num < N) && (left > 1e-8))
		{
			int q;
			min = 2147483647;
			for (j = 0; j < N; j++)
			{
				if ((s[j] <= min) && (d[j] == false))
				{
					q = j;
					min = s[j];
				}
			}
			if ((s[q] - s[p])/(double)X*num < left)
			{
				for (j = 0; j < N; j++)
					if (d[j] == true) 
						piao[j] += (s[q] - s[p])/(double)X;
				left -= (s[q] - s[p])/(double)X*num;
			}
			else {
				for (j = 0; j < N; j++)
					if (d[j] == true) piao[j] += left / num;
				left = 0;
			}
			d[q] = true;
			p = q;
			num++;			
		}
		if (num == N)
			for (j = 0; j < N; j++)
				piao[j] += left / N;		
		fprintf(fout, "Case #%d:", i + 1); 
		for (j = 0; j < N; j++)
			fprintf(fout, " %f", piao[j] * 100);
		fprintf(fout, "\n");
	}

	fclose(fin);
	fclose(fout);
	return 0;
}