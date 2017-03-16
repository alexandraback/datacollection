#include <stdio.h>


int gao(int x, int r, int c)
{
	int t;
	if (x >= 7) return 0;
	if (r > c) {t = r, r = c, c = t;}
	if (r*c % x != 0)return 0;
	if (x == 1) return 1;
	if (x == 2) return 1;
	
	if (r == 1) return 0;
	
	if (x == 3)
	{
		return 1;
	}
	if (x == 4)
	{
		if (r == 2) return 0;
		return 1;
	}
	if (x == 5)
	{
		if (r <= 3) return 0;
		return 1;
	}
	
	if (x == 6)
	{
		if (r <= 3) return 0;
		return 1;
	}
}


int main()
{
	int T, cas, x, r, c;
	freopen ("D-large.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for(cas = 1; cas <= T; cas++)
	{
		scanf ("%d%d%d", &x, &r, &c);
		printf ("Case #%d: %s\n", cas, gao(x, r, c) ? "GABRIEL" : "RICHARD");
	}
	return 0;
}

