#include<cstdio>
using namespace std;

int T, CN;

long long gcd(long long m, long long n) {
	return n?gcd(n, m%n):m;
}

int isPowerof2(long long n) {
	while(!(n%2)) n /= 2;
	if (n != 1) return 0;
	else return 1;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	scanf("%d", &T);
	for (CN=1; CN<=T; ++CN) {
		long long p, q;
		scanf("%lld/%lld", &p, &q);
		printf("Case #%d: ", CN);
		long long gcdpq = gcd(p, q);
		p = p/gcdpq, q = q/gcdpq;
		if (isPowerof2(q)) {
			int generation = 0;
			while (p<q) {
				++generation;
				p *= 2;
			}
			printf("%d\n", generation);
		} else
			printf("impossible\n");
	}
	return 0;
}