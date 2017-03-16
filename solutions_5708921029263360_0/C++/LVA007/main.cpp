#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 4;

int u[3][10][10];

void solve(int t) {
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	memset(u, 0, sizeof u);
	vector<vector<int> > ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int p = 0; p < k; ++p) {
				if (u[0][i][j] < w && u[1][j][p] < w && u[2][i][p] < w) {
					++u[0][i][j];
					++u[1][j][p];
					++u[2][i][p];
					ans.push_back(vector<int> (3));
					ans.back()[0] = i;
					ans.back()[1] = j;
					ans.back()[2] = p;
				}
			}
		}
	}
	cout << "Case #" << t << ": " << (int)ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << ++ans[i][j] << ' ';
		}
		cout << endl;
	}
}


int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	return 0;
}