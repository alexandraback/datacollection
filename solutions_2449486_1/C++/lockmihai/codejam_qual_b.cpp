#include <stdio.h>
#include <string.h>

int n, m;
int v[105][105], mc[105], ml[105];

inline int max (int a, int b) {return a > b ? a : b;}

int main ()
{
	freopen ("input.in", "r", stdin);
	freopen ("output.out", "w", stdout);
	
	int t, tt;
	
	scanf  ("%d", &tt);
	for (t = 1; t <= tt; t ++)
	{
		memset (ml, 0, sizeof (ml));
		memset (mc, 0, sizeof (mc));
		
		scanf ("%d %d", &n, &m);
		
		int i, j;
		
		for (i = 1; i <= n; i ++)
			for (j = 1; j <= m; j ++)
			{
				scanf ("%d", &v[i][j]);
				ml[i] = max (ml[i], v[i][j]);
				mc[j] = max (mc[j], v[i][j]);
			}
		for (i = 1; i <= n; i ++)
			for (j = 1; j <= m; j ++)
				if (v[i][j] < ml[i] && v[i][j] < mc[j])
				{
					i = 10000;
					j = m + 2;
					printf ("Case #%d: NO\n", t);
					break;
				}
		if (i < 1000)
			printf ("Case #%d: YES\n", t);
	}
	return 0;
}
