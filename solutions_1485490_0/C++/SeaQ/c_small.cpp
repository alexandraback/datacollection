#include <stdio.h>
#include <string.h>
#define N 110

struct ss
{
	long long num, type;
} a[N], b[N];

long long c[N][N];

long long max, sum, n, m;

void find(int i, int k)
{
	int j, l;
	if ( i > n )
	{
		if ( sum > max )
			max = sum;
		return;
	}

	for (j = k; j <= m; j++)
	{
		for (l = k; l <= j; l++)
			if ( a[i].type == b[l].type )
			{
				if ( a[i].num > b[l].num )
				{
					sum += b[l].num;
					c[i][l] = b[l].num;
					a[i].num -= b[l].num;
					b[l].num = 0;					
				}
				else
				{
					sum += a[i].num;
					c[i][l] = a[i].num;
					b[l].num -= a[i].num;
					a[i].num = 0;
				}
			}
		find(i+1, j);
		for (l = k; l <= j; l++)
			if ( a[i].type == b[l].type )
			{
				sum -= c[i][l];
				a[i].num += c[i][l];
				b[l].num += c[i][l];
			}
	}
}
		

int main()
{
	int i, j, t;
	FILE * fin = fopen("C-small-attempt1.in", "r");
	FILE * fout = fopen("C-small-attempt1.out", "w");
	
	fscanf(fin,"%d", &t);
	for (j = 1; j <= t; j++)
	{
		fscanf(fin,"%lld%lld", &n, &m);
		
		for (i = 1; i <= n; i++)
			fscanf(fin,"%lld%lld", &a[i].num, &a[i].type);
		for (i = 1; i <= m; i++)
			fscanf(fin,"%lld%lld", &b[i].num, &b[i].type);

		max = 0;
		sum = 0;
		memset(c, 0, sizeof(c));
		find(1, 1);
		
		fprintf(fout,"Case #%d: %lld\n", j, max);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
