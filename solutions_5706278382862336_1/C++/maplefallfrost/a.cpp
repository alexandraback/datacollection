#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int cas; scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ca++) {
		long long p, q;
		scanf("%lld/%lld", &p, &q);
		long long gcd = __gcd(p, q);
		p /= gcd; q /= gcd;
		printf("Case #%d: ", ca);
		if ((q & (q - 1)) != 0) {
			printf("impossible\n");
		} else {
			long long cur = 1;
			int ans = 0;
			while (p*cur < q) {
				cur <<= 1;
				ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
