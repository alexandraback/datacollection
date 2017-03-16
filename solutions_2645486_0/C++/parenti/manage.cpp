#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int E, R, N;
int a[11];

int dp[11][6];

int solve(int idx, int rem) {
	if (idx == N) {
		return 0;
	}
	int &ret = dp[idx][rem];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 0; i <= rem; i++) {
		ret = max(ret, i * a[idx] + solve(idx + 1, min(rem - i + R, E)));
	}
	return ret;
}

void read() {
	scanf("%d %d %d", &E, &R, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
}

void process() {
	memset(dp, -1, sizeof dp);
	printf("%d\n", solve(0, E));
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		read();
		printf("Case #%d: ", i);
		process();
	}
	return 0;
}