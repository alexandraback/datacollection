#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 4;

void solve(int t) {
	int n;
	long long m;
	cin >> n >> m;
	cout << "Case #" << t << ": ";
	if (((long long)1 << (n - 2)) < m) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << "POSSIBLE\n";
	vector<vector<int> > g(n, vector<int> (n, 0));
	--m;
	g[0][n - 1] = 1;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			g[i][j] = 1;
		}
	}
	for (int i = 1; m > 0; m /= 2) {
		if (m % 2 == 1) {
			g[i][n - 1] = 1;
		}
		++i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << g[i][j];
		}
		cout << '\n';
	}
}


int main() {
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	return 0;
}