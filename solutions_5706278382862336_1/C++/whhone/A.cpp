#include <cstdio>
int T;
long long P, Q;

long long gcd(long long p, long long q) {
	return p ? gcd(q % p, p) : q;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%lld/%lld", &P, &Q);
		int ans = 1;
		long long d = gcd(P, Q);
		P /= d;
		Q /= d;
		bool ok = (Q == (Q & - Q));
		while (ok && P * 2 < Q) {
			if (Q % 2 != 0) {
				ok = false;
			} else {
				Q /= 2;
			}
			ans++;
		}
		
		printf("Case #%d: ", tc);
		if (ok && ans <= 40) {
			printf("%d", ans);
		} else {
			printf("impossible");
		}
		puts("");
	}
	return 0;
}