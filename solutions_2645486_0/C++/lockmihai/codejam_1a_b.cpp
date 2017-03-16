#include <stdio.h>
#include <string.h>

inline int max (int a, int b) {return a > b ? a : b;}
inline int min (int a, int b) {return a < b ? a : b;}

int n, e, r;
int v[15];
int d[15][15];

int main ()
{
	freopen ("input.in", "r", stdin);
	freopen ("output.out", "w", stdout);
	
	int tt, t, i, j, k;
	scanf ("%d", &tt);
	for (t = 1; t <= tt; t ++)
	{
		printf ("Case #%d: ", t);
		scanf ("%d %d %d", &e, &r, &n);
		if (r >= e)
			r = e;
		for (i = 1; i <= n; i ++)
			scanf ("%d", &v[i]);
		memset (d, 0, sizeof (d));
		
		d[0][e] = 0;
		for (i = 0; i < n; i ++)
			for (j = 0; j <= e; j ++)
				for (k = 0; k <= j; k ++)
				{
					d[i + 1][min (j - k + r, e)] = max (d[i + 1][min (j - k + r, e)], d[i][j] + v[i + 1] * k);
				}
		int sol = 0;
		for (i = 1; i <= n; i ++)
			for (j = 0; j <= e; j ++)
				if (d[i][j] > sol)
					sol = d[i][j];
		printf ("%d\n", sol);
	}
	return 0;
}
