#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int ilog2fll(long long a)
{
    int i;

    for (i = 0; (1LL << i) <= a; i++)
        ;

    return i - 1;
}

void do_test(int t)
{
	long long p, q, pq_gcd;

	scanf("%lld/%lld", &p, &q);

	pq_gcd = gcd(p, q);
	p /= pq_gcd;
	q /= pq_gcd;

	//fprintf(stderr, "Reduced fraction: %lld/%lld\n", p, q);

	if (q & (q - 1))
	{
		printf("Case #%d: impossible\n", t + 1);
		return;
	}

	p *= (1LL << 40) / q;

	printf("Case #%d: %d\n", t + 1, 40 - ilog2fll(p));
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
