#include <cstdio>

long long pgcd(long long a, long long b) {
	if (a < b)
		return pgcd(b, a);
	if (b == 0)
		return a;
	return pgcd(b, a%b);
}

int generations(long long p, long long q) {
	if (q == 1)
		return 1-p;
	if (2*p > q)
		return 1;
	return 1 + generations(p, q/2);
}

bool estPuissance(long long k) {
	if (k == 1)
		return true;
	if (k%2)
		return false;
	return estPuissance(k/2);
}

int main(void) {
	int nbTests;
	scanf("%d", &nbTests);
	for (int test = 1; test <= nbTests; test++) {
		long long p, q, k;
		scanf("%lld", &p);
		getchar();
		scanf("%lld", &q);
		k = pgcd(p, q);
		p /= k;
		q /= k;
		if (!estPuissance(q))
			printf("Case #%d: impossible\n", test);
		else
			printf("Case #%d: %d\n", test, generations(p, q));
	}	
	return 0;
}
