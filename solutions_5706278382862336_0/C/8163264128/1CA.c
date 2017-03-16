#include <stdio.h>

long long int gcd(long long int P, long long int Q)
{
	long long int r;
	while (Q != 0)
	{
		r = P % Q;
		P = Q;
		Q = r;
	}
	return P;
}

int main(voids)
{
	int T, x, y, i;
	long long int P, Q, d, t;
	scanf("%d ", &T);
	for (x = 1; x <= T; x++)
	{
		scanf("%lld/%lld ", &P, &Q);
		d = gcd(P, Q);
		P /= d;
		Q /= d;
		y = 0;
		t = Q;
		while (t >>= 1) y++;
		if (Q == (1LL << y))
		{
			for (i = 1; i < y; i++)
				if (P >= (1LL << (y - i)))
					break;
			printf("Case #%d: %d\n", x, i);
		}
		else
			printf("Case #%d: impossible\n", x);
	}
	return 0;
}