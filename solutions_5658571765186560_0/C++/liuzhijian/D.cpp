#include <cstdio>
#include <algorithm>

using namespace std;

int x, r, c;

inline void solve() {
	scanf("%d%d%d", &x, &r, &c);

	if (r > c) {
		swap(r, c);
	}

	if (x == 1) {
		puts("GABRIEL");
		return;
	}
	if (x == 2) {
		if ((r * c) % 2 == 0) {
			puts("GABRIEL");
			return;
		} else {
			puts("RICHARD");
			return;
		}
	}
	if (x == 3) {
		if (c < 3) {
			puts("RICHARD");
			return;
		}
		if (c == 3) {
			if (r == 1) {
				puts("RICHARD");
				return;
			}
			if (r == 2) {
				puts("GABRIEL");
				return;
			}
			if (r == 3) {
				puts("GABRIEL");
				return;
			}
		}
		if (c == 4) {
			if (r == 1) {
				puts("RICHARD");
				return;
			}
			if (r == 2) {
				puts("RICHARD");
				return;
			}
			if (r == 3) {
				puts("GABRIEL");
				return;
			}
			if (r == 4) {
				puts("RICHARD");
				return;
			}
		}
	}
	if (x == 4) {
		if (c < 4) {
			puts("RICHARD");
			return;
		}
		if (r == 1) {
			puts("RICHARD");
			return;
		}
		if (r == 2) {
			puts("RICHARD");
			return;
		}
		if (r == 3) {
			puts("GABRIEL");
			return;
		}
		if (r == 4) {
			puts("GABRIEL");
			return;
		}
	}
}

int main() {
	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}