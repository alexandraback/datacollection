#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 11111;
int e, r, n, v[MaxN];
int result;

void search(int k, int e0, int sum) {
	if (k > n) {
		result = max(result, sum);
	} else {
		for (int i = 0; i <= e0; ++ i) {
			search(k + 1, min(e0 - i + r, e), sum + i * v[k]);
		}
	}
}

void solve() {
	scanf("%d%d%d", &e, &r, &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &v[i]);
	}
	result = 0;
	search(1, e, 0);
	printf("%d\n", result);
}

int main() {
	int test_cases;
	scanf("%d", &test_cases);
	for (int t = 1; t <= test_cases; ++ t) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}