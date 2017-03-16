#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

bool dp[1<<20];
int ans[25];
int own[205];
int cur[25][205];
int need[205];
vector<int> inside[205];
int n, k;

void Clear() {
	memset(dp, 0, sizeof dp);
	memset(own, 0, sizeof own);
	memset(ans, 0, sizeof ans);
	memset(need, 0, sizeof need);
	for (int i = 0; i < 205; ++i) {
		inside[i].clear();
	}
}

void DFS(int state, int lev = 0) {
	if (dp[state]) {
		return;
	}
	if (lev == n) {
		throw "Success";
	}
	dp[state] = true;
	memcpy(cur[lev], own, sizeof cur[lev]);
	for (int i = 0; i < n; ++i) {
		if (!(state & (1 << i))) {
			continue;
		}
		--cur[lev][need[i]];
		for (int j = 0; j < inside[i].size(); ++j) {
			++cur[lev][inside[i][j]];
		}
	}
	for (int i = 0; i < n; ++i) {
		if ((state & (1 << i)) || cur[lev][need[i]] == 0) {
			continue;
		}
		ans[lev] = i + 1;
		DFS(state | (1 << i), lev + 1);
	}
}

int main() {
	freopen("d_easy.in", "r", stdin);
	freopen("d_easy.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		Clear();
		printf("Case #%d: ", I + 1);
		scanf("%d%d", &k, &n);
		for (int i = 0; i < k; ++i) {
			int x;
			scanf("%d", &x);
			++own[x];
		}
		for (int i = 0; i < n; ++i) {
			int q;
			scanf("%d%d", &need[i], &q);
			for (int j = 0; j < q; ++j) {
				int x;
				scanf("%d", &x);
				inside[i].push_back(x);
			}
		}
		bool solved = false;
		try {
			DFS(0);
		} catch (const char * ex) {
			solved = true;
			for (int i = 0; i < n; ++i) {
				printf("%d ", ans[i]);
			}
			puts("");
		}
		if (!solved) {
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}