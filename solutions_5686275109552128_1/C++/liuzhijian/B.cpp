#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 11111;

int n;
int a[N];

inline void solve() {
	scanf("%d", &n);

	int bound = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		bound = max(bound, a[i]);
	}

	int ret = bound;
	for (int normal = 1; normal <= bound; ++normal) {
		int special = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > normal) {
				special += (a[i] - 1) / normal;
			}
		}
		ret = min(ret, normal + special);
	}

	printf("%d\n", ret);
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