#include <cstdio>
typedef long long ll;
int main() {
	int T, k, c, s;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d:", C);
		ll p = 0, t = 1;
		int m = (c > 1)? (k+1)/2: k;
		for (int i = 1; i < c; i++) t *= k;
		if (c == 1) t = 0;
		if (s >= m)  {
			for (int x = 0; x < m; x++) {
				printf(" %lld", p+k-x);
				p += t;
			}
			puts("");
		} else puts(" IMPOSSIBLE");
	}
}
