#include <cstdio>

int T, n, t, ans;
char s[1024];

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		scanf("%d%s", &n, s);
		ans = 0;
		t = 0;
		for (int i = 0; i <= n; ++i) {
			t += s[i] - '1';
			if (t < ans)
				ans = t;
		}
		printf("Case #%d: %d\n", r, -ans);
	}
	return 0;
}
