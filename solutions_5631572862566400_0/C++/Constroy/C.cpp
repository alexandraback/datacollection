#include <cstdio>

int T, n, f[1009], d[1009], s[1009];
int l, r, q[1009];
int ans, cnt;
bool u[1009];

int main() {
	scanf("%d", &T);
	for (int iT = 1; iT <= T; ++iT) {
		printf("Case #%d: ", iT);
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			d[i] = 0;
			s[i] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", f + i);
			++d[f[i]];
		}
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) u[j] = false;
			int len = 0 ,j;
			for (j = i; !u[j]; j = f[j]) {
				u[j] = true;
				++len;
			}
			if (j == i && ans < len) ans = len;
		}
		r = 0;
		for (int i = 1; i <= n; ++i) if (!d[i]) q[r++] = i;
		for (l = 0; l < r; ++l) {
			int i = q[l];
			if (s[f[i]] <= s[i])
				s[f[i]] = s[i] + 1;
			if (!--d[f[i]]) q[r++] = f[i];
		}
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (d[i] && f[f[i]] == i) {
					cnt += s[i] + s[f[i]];
			}
		}
		cnt >>= 1;
		if (ans < cnt) ans = cnt;
		printf("%d\n", ans);
	}
	return 0;
}
