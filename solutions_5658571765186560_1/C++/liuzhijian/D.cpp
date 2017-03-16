#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

int x, r, c;

inline bool check(int x, int r, int c) {
	if (r > c) {
		swap(r, c);
	}

	if (x >= 7 || (r * c) % x != 0 || c < x) {
		return true;
	}

	if (x == 1) {
		return false;
	}

	if (x == 2) {
		return false;
	}

	if (x == 3) {
		if (c == 3) {
			if (r == 1) {
				return true;
			}
		}
		return false;
	}

	if (x == 4) {
		if (c == 4) {
			if (r == 1) {
				return true;
			}
			if (r == 2) {
				return true;
			}
		}
		return false;
	}

	if (x == 5) {
		if (c == 5) {
			if (r == 1) {
				return true;
			}
			if (r == 2) {
				return true;
			}
		}
		return false;
	}

	if (x == 6) {
		if (c == 6) {
			if (r == 1) {
				return true;
			}
			if (r == 2) {
				return true;
			}
			if (r == 3) {
				return true;
			}
		}
		return false;
	}

	assert(false);
}

inline void solve() {
	scanf("%d%d%d", &x, &r, &c);
	if (check(x, r, c)) {
		puts("RICHARD");
	} else {
		puts("GABRIEL");
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