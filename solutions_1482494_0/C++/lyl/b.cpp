#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1010;

int n, aa[maxn], bb[maxn], dp[maxn][maxn];
vector<int> idx[maxn], order[maxn];

bool cmp(int a, int b) {
	return aa[a] < aa[b];
}

void preprocess() {
	for (int i = 0; i < n; i++) {
		idx[i].clear();
		for (int j = i; j < n; j++)
			idx[i].push_back(j);
		sort(idx[i].begin(), idx[i].end(), cmp);

	}
}

int rank(int i, int x) {
	return 1 + (int) (lower_bound(idx[i].begin(), idx[i].end(), x, cmp) - idx[i].begin());
}

int nextj(int i, int j) {
	return idx[i][j];
}

int main() {
	int ca;
	cin >> ca;
	for (int tt = 1; tt <= ca; tt++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d %d\n", aa + i, bb + i);
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (bb[i] > bb[j]) {
					swap(aa[i], aa[j]);
					swap(bb[i], bb[j]);
				}
		preprocess();
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= n; j++) {
//				printf("%d %d %d\n", i, j, dp[i][j]);
				if (dp[i][j] == -1)
					continue;

				int score = i * 2 + j;
				if (score >= bb[i]) {
					if (rank(i, i) <= j) {
						dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j]);
					} else {
						dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
					}
				}

				int nx = nextj(i, j);
//				printf("next %d %d %d\n", i, j, nx);
				if (score >= aa[nx]) {
					dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
				} 
			}

		int ans = -1;
		for (int i = 0; i <= n; i++)
			ans = max(ans, dp[n][i]);
		if (ans == -1)
			printf("Case #%d: Too Bad\n", tt);
		else
			printf("Case #%d: %d\n", tt, n * 2 - ans);
	}
}
