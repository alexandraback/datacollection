#include <cstdio>

int n,m;
int a[128][128];

bool 
can_horizontal_cut (int x, int h)
{
	for (int i = 0; i < m; i ++)
		if (a[x][i] > h)
			return false;
	return true;
}

bool
can_vertical_cut (int y, int h)
{
	for (int i = 0; i < n; i ++)
		if (a[i][y] > h)
			return false;
	return true;
}

int
main ()
{
	freopen ("Bs.in","r",stdin);
	freopen ("Bs.out","w", stdout);
	int t;
	scanf ("%d", &t);
	for (int tc = 1; tc <= t; tc ++){
		scanf ("%d %d", &n, &m);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				scanf ("%d", &a[i][j]);

		bool good = true;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				if (!can_horizontal_cut (i,a[i][j]) && !can_vertical_cut (j,a[i][j]))
					good = false;
		printf ("Case #%d: %s\n", tc, good ? "YES" : "NO");
	}
	return 0;
}