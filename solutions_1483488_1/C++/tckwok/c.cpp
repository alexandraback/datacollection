#include <cstdio>

#define N (1 << 21)

const int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int T, a, b, l, t, cnt, ans;
bool vis[N];

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d%d", &a, &b);
		t = b; l = 0; while (t) { t /= 10; ++l; }
		for (int i = a; i <= b; ++i) vis[i] = 0;
		ans = 0;
		for (int i = a; i <= b; ++i) if (!vis[i]) {
			t = i; cnt = 0;
			for (int j = 0; j < l; ++j) {
				t = (t*10 + t/p10[l - 1])%p10[l];
				if (a <= t && t <= b)
					if (vis[t]) break;
					else {
						vis[t] = 1; ++cnt;
					}
			}
			ans += cnt*(cnt - 1)/2;
		}
		printf("%d\n", ans);
	}
}
