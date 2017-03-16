#include <stdio.h>
#include <math.h>

int sol[10000005];

int pali (long long x)
{
	long long cx, y = 0;
	cx = x;
	while (cx)
	{
		y = y * 10 + cx % 10;
		cx /= 10;
	}
	return x == y;
}

void precalc ()
{
	int i;
	for (i = 1; i <= 10000000; i ++)
	{
		if (pali (i))
			if (pali ((long long)i * i))
			{
				sol[i] = 1;
				//printf ("%d %lld\n", i, (long long)i * i);
			}
			
		sol[i] += sol[i - 1];
	}
}

int main ()
{
	freopen ("input.in", "r", stdin);
	freopen ("output.out", "w", stdout);
	
	int t, tt;
	long long st, dr, x;
	
	precalc ();
	scanf ("%d", &tt);
	for (t = 1; t <= tt; t ++)
	{
		scanf ("%lld %lld", &st, &dr);
		x = sqrt (st);
		if (x * x == st)
			st = x - 1;
		else
			st = x;
		dr = sqrt (dr);
		printf ("Case #%d: %d\n", t, sol[dr] - sol[st]);
	}
	return 0;
}
