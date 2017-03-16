#include <stdio.h>
#include <string.h>
#define N 1010

struct ss
{
	int i;
	ss * point;
} *v[N];

bool f[N];
bool y;

void dfs(int i)
{
	ss * p;
	p = v[i];	

	while ( p )
	{
		if ( !f[p->i] )
		{
			f[p->i] = true;
			dfs(p->i);
		}
		else
		{
			y = true;
			return;
		}
		if ( y )
			return;
		p = p->point;
	}
}

int main()
{
	FILE * fin = fopen("A-large.in", "r");
	FILE * fout = fopen("A-large.out", "w");
	int i, j, k, l, n, t;
	ss * p;
	

	fscanf(fin,"%d", &t);
	for (j = 1; j <= t; j++)
	{
		fscanf(fin,"%d", &n);
		memset(v, 0, sizeof(v));
		for (i = 0; i < n; i++)
		{
			fscanf(fin,"%d", &k);
			for (; k > 0; k--)
			{
				fscanf(fin,"%d", &l);
				p = new ss;
				p->i = l-1;
				p->point = v[i];
				v[i] = p;
			}
		}

		y = false;

		for (i = 0; i < n; i++)
		{
			memset(f, 0, sizeof(f));
			f[i] = true;
			dfs(i);
			if ( y )
				break;
		}

		if ( !y )
			fprintf(fout,"Case #%d: No\n", j);
		else
			fprintf(fout,"Case #%d: Yes\n", j);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}