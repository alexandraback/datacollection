#include <stdio.h>

int n, m, k, merge;
int st[15];
int v[15];

int ok ()
{
	int i, a[15] = {0}, viz[15] = {0};
	
	int stare, lim = (1 << n) - 1;
	for (stare = 0; stare <= lim; stare ++)
	{
		int p = 1;
		for (i = 0; i < n; i ++)
			if (stare & (1 << i))
				p = p * st[i + 1];
		for (i = 1; i <= k; i ++)
			if (p == v[i])
				viz[i] = 1;
	}
	for (i = 1; i <= k; i ++)
		if (viz[i] == 0)
			return 0;
	for (i = 1; i <= n; i ++)
		printf ("%d", st[i]);
	printf ("\n");
	return 1;
}

void comb (int k)
{
	if (merge)
		return;
	if (k == 5)
	{
		merge = ok ();
		return;
	}
	int i;
	for (i = st[k - 1]; i <= m; i ++)
	{
		st[k] = i;
		comb (k + 1);
	}
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
	
	int i;
	st[0] = 2;
	st[5] = 2;
	st[6] = 2;
	st[7] = 3;
	st[8] = 4;
	st[9] = 5;
	st[10] = 6;
	st[11] = 7;
	st[12] = 8;
	int nr = 0;
	while (tt --)
	{
		merge = 0;
		for (i = 1; i <= k; i ++)
			scanf ("%lld", &v[i]);
		if (nr <= 2000)
			comb (1);
		if (merge == 0)
		{
			for (i = 1; i <= n; i ++)
				printf ("0");
			printf ("\n");
		}
		else
			nr ++;
	}
	return 0;
}
