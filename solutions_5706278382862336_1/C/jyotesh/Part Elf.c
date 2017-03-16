/*Part Elf*/

#include<stdio.h>

long long gcd(long long, long long);

int main()
{
	int level, t, T;
	long long g, P, power, Q;
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%lld/%lld", &P, &Q);
		g = gcd(P, Q);
		P /= g;
		Q /= g;
		if ((P == 1) && (Q == 1))
		{
			printf("Case #%d: 0\n", t);
			continue;
		}
		if ((Q & 1) || (Q & (Q - 1)))
		{
			printf("Case #%d: impossible\n", t);
			continue;
		}
		level = 0;
		power = 1;
		while (Q > P * power)
		{
			level++;
			power <<= 1;
		}
		printf("Case #%d: %d\n", t, level);
	}
	return 0;
}

long long gcd(long long a, long long b)
{
	long long r;
	do
	{
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}