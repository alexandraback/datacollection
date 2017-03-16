#include <cstdio>

int n, v[11];

bool check(int x_1, int x_2, int x_3) {
	bool visit[133] = {0};
	visit[1] = true;
	visit[x_1] = true;
	visit[x_2] = true;
	visit[x_3] = true;
	visit[x_1 * x_2] = true;
	visit[x_1 * x_3] = true;
	visit[x_2 * x_3] = true;
	visit[x_1 * x_2 * x_3] = true;
	for (int i = 0; i < n; ++ i) {
		if (!visit[v[i]]) return false;
	}
	return true;
}

void solve() {
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &v[i]);
	}
	bool no = true;
	for (int i = 2; no && i <= 5; ++ i) {
		for (int j = 2; no && j <= 5; ++ j) {
			for (int k = 2; no && k <= 5; ++ k) {
				if (check(i, j, k)) {
					no = false;
					printf("%d%d%d\n", i, j, k);
				}
			}
		}
	}
}

int main() {
	int test_cases, r;
	scanf("%d", &test_cases);
	for (int t = 1; t <= test_cases; ++ t) {
		printf("Case #%d:\n", t);
		scanf("%d%*d%*d%d", &r, &n);
		while (r --) {
			solve();
		}
	}
	return 0;
}
