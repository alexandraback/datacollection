#include <stdio.h>

int n, m, k;
int v[5];

int ok (int x, int y, int z)
{
	int i, a[5] = {0}, viz[10] = {0};
	a[0] = x;
	a[1] = y;
	a[2] = z;
	
	int st, lim = 7;
	for (st = 0; st <= lim; st ++)
	{
		int p = 1;
		for (i = 0; i < 3; i ++)
			if (st & (1 << i))
				p = p * a[i];
		for (i = 1; i <= k; i ++)
			if (p == v[i])
				viz[i] = 1;
	}
	for (i = 1; i <= k; i ++)
		if (viz[i] == 0)
			return 0;
	return 1;
}

int main ()
{
	freopen ("input.in", "r", stdin);
	freopen ("output.out", "w", stdout);
	
	int tt, t;
	scanf ("%d", &tt);
	for (t = 1; t <= tt; t ++)
		printf ("Case #%d:\n", t);
	
	scanf ("%d %d %d %d", &tt, &n, &m, &k);
	
	int i1, i2, i3, i;
	while (tt --)
	{
		for (i = 1; i <= k; i ++)
			scanf ("%d", &v[i]);
		for (i1 = 2; i1 <= 5; i1 ++)
			for (i2 = 2; i2 <= 5; i2 ++)
				for (i3 = 2; i3 <= 5; i3 ++)
					if (ok (i1, i2, i3))
					{
						printf ("%d%d%d\n", i1, i2, i3);
						i1 = i2 = i3 = 100;
						break;
					}
	}
	return 0;
}
