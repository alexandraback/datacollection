#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void dfs(const int h, const int n, const int m, vector<vector<int>>& dp, const vector<vector<int>>& c, const vector<vector<int>>& f, int ci, int cj, int ctime, bool cost)
{
	int shi[] = {0,0,-1,1}, shj[] = {-1,1,0,0};
	for (int i = 0; i < 4; ++i) {
		int ni = ci + shi[i], nj = cj + shj[i];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
			if (c[ni][nj] - f[ci][cj] >= 50 && c[ni][nj] - f[ni][nj] >= 50 && c[ci][cj] - f[ni][nj] >= 50) {
				int t = max(0, h - ctime - c[ni][nj] + 50);
				int g = h - ctime - t - f[ci][cj] >= 20 ? 10 : 100;
				int ndp = cost ? ctime + t + g : (t ? numeric_limits<int>::max() : 0);
				if (dp[ni][nj] > ndp) {
					dp[ni][nj] = ndp;
					dfs(h, n, m, dp, c, f, ni, nj, ndp, cost);
				}
			}
		}
	}
}

int main()
{
	cout.precision(20);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int h, n, m;
		cin >> h >> n >> m;
		vector<vector<int>> c(n, vector<int>(m, numeric_limits<int>::max())), f = c, dp = c;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			cin >> c[i][j];
		}
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			cin >> f[i][j];
		}
		dp[0][0] = 0;
		dfs(h, n, m, dp, c, f, 0, 0, 0, false);
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			if (dp[i][j] == 0) {
				dfs(h, n, m, dp, c, f, i, j, 0, true);
			}
		}
		cout << "Case #" << test << ": " << double(dp[n-1][m-1]) / 10 << endl;
	}
}
