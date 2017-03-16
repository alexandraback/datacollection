#include <cstdio>

using namespace std;

const int N = 1111;

int n;
char str[N];

inline bool check(int sum) {
	for (int i = 0; i <= n; ++i) {
		if (sum >= i) {
			sum += str[i] - '0';
		} else {
			return false;
		}
	}
	return true;
}

inline void solve() {
	scanf("%d%s", &n, str);
	for (int i = 0; i <= n; ++i) {
		if (check(i)) {
			printf("%d\n", i);
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