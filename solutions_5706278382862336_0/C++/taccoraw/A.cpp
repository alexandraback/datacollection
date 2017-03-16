#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b) {
	long long r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	int T = 0;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		long long P, Q;
		scanf("%lld/%lld", &P, &Q);
		long long d = gcd(P, Q);
		P /= d;
		Q /= d;
		printf("Case #%d: ", t+1);
		if ((Q & (Q-1)) != 0)
			printf("impossible\n");
		else {
			long long ans = 0;
			while (P < Q) {
				ans++;
				P <<= 1;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}

