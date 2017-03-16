#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[20][20];
int t[20][20];
int vs[20][20];
int ttl;
int ans = 1e9;
int dj[] = {0, 1, 0, -1}, dk[] = {-1, 0, 1, 0};
int N, M, K;

int dfs(int j, int k) {
	if (a[j][k])
		return 0;
	if (vs[j][k])
		return t[j][k];
	vs[j][k] = 1;
	if (j == 0 || j == N - 1 || k == 0 || k == M - 1)
		return t[j][k] = -1;
	int s = 0;
	for (int d = 0; d < 4; ++d)
		if (dfs(j + dj[d], k + dk[d]) == -1)
			t[j][k] = -1;
	return t[j][k];
}

int solve() {
	scanf("%d%d%d", &N, &M, &K);
	ans = 1e9;
	for (int i = 0; i < 1 << N * M; ++i) {
		int cnt = 0;
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < M; ++k)
				vs[j][k] = t[j][k] = 0;
		for (int j = 0; j < N * M; ++j)
			if (i & 1 << j)
				a[j / M][j % M] = 1, ++cnt;
			else
				a[j / M][j % M] = 0;
		ttl = 0;
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < M; ++k)
				dfs(j, k);
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < M; ++k)
				if (t[j][k] != -1)
					++ttl;
		if (ttl >= K)
			ans = min(ans, cnt);
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
		printf("Case #%d: %d\n", i, solve());
}
