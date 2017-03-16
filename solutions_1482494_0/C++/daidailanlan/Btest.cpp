#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 1;
const int MAXM = 1 << 20;
const int INF = 1012345678;

int n, a[MAXN], b[MAXN], dp[MAXM];

int calc(int mask) {
	if (dp[mask] != -1) return dp[mask];
	int &res = dp[mask];
	int score = __builtin_popcount(mask);
	res = INF;
	for (int i = 0; i < n; i++) {
		if ((mask & (3 << (i << 1))) == 0) {
			if (a[i] <= score) {
				res = min(res, calc(mask | (1 << (i << 1))) + 1);
			}
			if (b[i] <= score) {
				res = min(res, calc(mask | (3 << (i << 1))) + 1);
			}
		} else if ((mask & (3 << (i << 1))) == (1 << (i << 1))) {
			if (b[i] <= score) {
				res = min(res, calc(mask | (2 << (i << 1))) + 1);
			}
		}
	}
	return res;
}

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 0; taskIdx < taskNumber; taskIdx++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i], &b[i]);
		}
		printf("Case #%d: ", taskIdx + 1);
		memset(dp, 0xFF, sizeof(dp));
		dp[(1 << (n << 1)) - 1] = 0;
		int res = calc(0);
		if (res == INF) puts("Too Bad");
		else printf("%d\n", res);
	}
	return 0;
}
