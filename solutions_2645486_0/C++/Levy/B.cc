#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10010;

int E, R, N;
int v[MAXN];

int maxGain = 0;

void dfs(int act, int eng, int gain) {
	if (act == N) {
		if (gain > maxGain) maxGain = gain;
		return;
	}
	for (int i = 0; i <= eng; ++i) {
		dfs(act + 1, min(E, eng - i + R), gain + i * v[act]);
	}
}

int solve() {
	maxGain = 0;
	dfs(0, E, 0);
	return maxGain;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 0; i < N; ++i) scanf("%d", v + i);
		printf("Case #%d: %d\n", c, solve());
	}
}