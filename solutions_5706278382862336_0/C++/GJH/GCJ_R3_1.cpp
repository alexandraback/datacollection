#include <stdio.h>
#include <stdlib.h>

long long gcd(long long m, long long n)
{
	while(m % n != 0)
	{
		long long p = n;
		n = m % n;
		m = p;
	}
	return n;
}

int main(void)
{
	freopen("A-small-attempt1.in", "rb", stdin);
	freopen("q1s.txt", "wb", stdout);
	int t, k = 0;
	scanf("%d", &t);
	while(k++ < t) {
		long long m, n;
		scanf("%lld/%lld", &m, &n);
		long long g = gcd(m, n);
		m /= g;
		n /= g;
		long long p = n & (n-1);
		if(p != 0)
			printf("Case #%d: impossible\n", k);
		else {
			int count = 1;
			while(m * 2 < n)
				n /= 2, ++count;
			printf("Case #%d: %d\n", k, count);
		}
	}
	return 0;
}