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
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int answer = 1; ; ++answer) {
		for (int special = 0; special < answer; ++special) {
			int normal = answer - special;

			int consume = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] > normal) {
					consume += (a[i] - 1) / normal;
				}
			}

			if (consume <= special) {
				printf("%d\n", answer);
				return;
			}
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