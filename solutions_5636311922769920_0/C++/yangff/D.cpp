#include <cstdio>

int main(){
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		int k, c, s; scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d:", cas);
		if (c * s < k) {
			puts(" IMPOSSIBLE"); continue;
		}
		int p = 0;
		for (; p < k;) {
			long long ans = 0;
			for (int i = 0; i < c; i++) {
				ans = ans * k + (p++);
				if (p >= k) break;
			}
			printf(" %lld", ans + 1);
		}
		puts("");
	}
}