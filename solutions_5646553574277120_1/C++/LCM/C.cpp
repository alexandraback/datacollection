#include<cstdio>

long long t, c, d, v, e, m, ans;

int main() {
	freopen("C_large.in", "r", stdin);
	freopen("C_large.out", "w", stdout);
	scanf("%I64d", &t);
	for (int zzz = 1 ; zzz <= t ; zzz++) {
		ans = 0;
		m = 0;
		scanf("%I64d %I64d %I64d", &c, &d, &v);
		for (int i = 0 ; i < d ; i++) {
			scanf("%I64d", &e);
			while (e > m + 1 && m < v) {
				ans++;
				m += c * (m + 1);
			}
			m += c * e;
		}
		while (v > m) {
			ans++;
			m += c * (m + 1);
		}
		printf("Case #%d: %I64d\n", zzz, ans);
	}
	scanf("\n");
	return 0;
}
