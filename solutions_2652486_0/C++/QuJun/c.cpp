#include <cstdio>

using namespace std;

int test, r, n, m, k;
double maxp = 0;
int num[13];
int ans[13];
int prod[13];

int calc(int x, int pd, int res) {
	if (x == n + 1) {
		if (pd == res) {
			return 1;
		} else {
			return 0;
		}
	}
	return calc(x + 1, pd, res) + calc(x + 1, pd * num[x], res);
}

void dfs(int x) {
	if (x == n + 1) {
		double p = 1;
		for (int i = 0; i < k; i++) {
			double ways = calc(1, 1, prod[i]);
			ways /= (double) (1 << n);
			p *= ways;
		}
		if (p > maxp) {
			maxp = p;
			for (int i = 1; i <= n; i++) {
				ans[i] = num[i];
			}
		}
		return;
	}
	for (int i = 2; i <= m; i++) {
		num[x] = i;
		dfs(x + 1);
	}
}

int main() {

	scanf("%d", &test);
	scanf("%d%d%d%d", &r, &n, &m, &k);
	printf("Case #1:\n");
	for (int t = 1; t <= r; t++) {
		maxp = 0;
		for (int i = 0; i < k; i++) {
			scanf("%d", &prod[i]);
		}
		dfs(1);
		for (int i = 1; i <= n; i++) {
			printf("%d", ans[i]);
		}
		printf("\n");
	}
}