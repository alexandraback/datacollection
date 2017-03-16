/* CGJ 2012 R1c */

#include <stdio.h>
#include <string.h>

#define MAX 1005

int vis[MAX];
int kid[MAX];
int m[MAX][11];

int f;

void rec (int n, int x)
{
	int i;
	for (i=0; !f && m[n][i]; ++i)
	{
		if (vis[m[n][i]] == x)
			f = 1;
		else
			vis[m[n][i]] = x;
		rec(m[n][i], x);
	}
}

int
main ()
{
	int cases, cases_r=0, N, i, j, k;

	scanf("%d", &cases);

	while (cases_r++<cases)
	{
		for (i=0; i<MAX; ++i)
		{
			vis[i] = kid[i] = 0;
			for (j=0; j<11; ++j)
				m[i][j] = 0;
		}

		scanf("%d", &N);

		for (i=1; i<=N; ++i)
		{
			scanf("%d", &k);
			for (j=0; j<k; ++j)
			{
				scanf("%d", &m[i][j]);
				kid[m[i][j]]++;
			}
		}

		f = 0;

		for (i=1; !f && i<=N; ++i)
			if (!kid[i])
				rec(i,i);
		printf("Case #%d: %s\n", cases_r, f ? "Yes" : "No");
	}

	return 0;
}

