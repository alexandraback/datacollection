#include <cstdio>

const int MaxN = 1111;
int n, p[MaxN][2];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &p[i][0], &p[i][1]);
	}
	bool ok = true;
	int cnt = 0, result = 0, t[MaxN] = {0};
	while (ok) {
		ok = false;
		for (int i = 1; i <= n; ++ i) {
			if (p[i][1] <= cnt && t[i] < 2) {
				cnt += 2 - t[i];
				t[i] = 2;
				++ result;
				ok = true;
			}
		}
		if (ok) continue;
		int tmp;
		for (int i = 1; i <= n; ++ i) {
			if (p[i][0] <= cnt && t[i] < 1) {
				if (!ok || p[i][1] > p[tmp][1]) tmp = i;
				ok = true;
			}
		}
		if (ok) {
			cnt += 1;
			t[tmp] = 1;
			++ result;
			continue;
		}
		for (int i = 1; i <= n; ++ i) {
			if (t[i] < 2) ok = true;
		}
		if (ok) {
			printf("Too Bad\n");
			return;
		}
	}
	printf("%d\n", result);
}

int main() {
	int testCases;
	scanf("%d", &testCases);
	for (int t = 1; t <= testCases; ++ t) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
