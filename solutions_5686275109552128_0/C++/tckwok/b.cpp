#include <cstdio>

#define N 1024

int T, n, d[N], ans, t;

bool ok(int y, int x) {
	int t = 0;
	for (int i = 0; i < n; ++i)
		t += (d[i] - 1) / y;
	return t <= x;
}

int f(int x) {
	int lo = 0, md, hi = N;
	while (lo + 1 < hi) {
		md = lo + hi >> 1;
		if (ok(md, x)) hi = md;
		else lo = md;
	}
	return hi;
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", d + i);
		ans = N;
		for (int i = 0; i < N; ++i) {
			t = f(i) + i;
			if (t < ans)
				ans = t;
		}
		printf("Case #%d: %d\n", r, ans);
	}
	return 0;
}
