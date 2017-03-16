#include <stdio.h>
#include <set>

long long isp(long long n) {
	if (n % 2 == 0) return isp(n / 2);
	return n; 
}

long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	int T;
	freopen("x.txt", "r", stdin); freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		long long p, q;
		scanf("%lld/%lld", &p, &q);
		long long div = gcd(p, q);
		p /= div;
		q /= div;
		if (isp(q) != 1) {
			printf("Case #%d: impossible\n", cas);
			continue;
		}
		int i = 0;
		while (p < q) {
			p *= 2;
			i++;
		}
		printf("Case #%d: %d\n", cas, i);
	}
}
