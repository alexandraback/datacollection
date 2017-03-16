#include <cstdio>

bool ok(int x, int r, int c) {
	if (x == 1) return 1;
	if (x == 2) return (r*c%2 == 0);
	if (x == 3) {
		if (r == 1) return 0;
		return (r*c%3 == 0);
	}
	if (x == 4) {
		if (r <= 2) return 0;
		return (r*c%4 == 0);
	}
	if (x == 5) {
		if (r <= 2) return 0;
		if (r == 3 && c == 5) return 0;
		return (r*c%5 == 0);
	}
	if (x == 6) {
		if (r <= 3) return 0;
		return (r*c%6 == 0);
	}
	return 0;
}

int T, x, n, m, t;

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d%d%d", &x, &n, &m);
		if (m < n) {
			t = m; m = n; n = t;
		}
		if (ok(x, n, m)) puts("GABRIEL");
		else puts("RICHARD");
	}
	return 0;
}
