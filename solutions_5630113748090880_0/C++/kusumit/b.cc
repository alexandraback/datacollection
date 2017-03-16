#define DEBUG 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int grid[50][50];
string gg[100];

int missing, n;

void dfs(int cur) 
{
	if (cur == n) {
		;
	}

	bool works = true;
	for (int j = 0; j < cur; ++j) {
		if (gg[cur * 2][j] != grid[cur][j]) {
			works = false;
			break;
		}
	}
	if (works) {
		for (int j = cur; j < n; ++j) {
			grid[cur][j] = gg[cur * 2][j];
		}
		if (dfs(cur + 1)) {
			return true;
		}
	} 

	works = true;
	for (int j = 0; j < cur; ++j) {
		if (gg[cur * 2][j] != grid[cur][j]) {
			works = false;
			break;
		}
	}
	if (works) {
		for (int j = cur; j < n; ++j) {
			grid[cur][j] = gg[cur * 2][j];
		}
		if (dfs(cur + 1)) {
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << fixed << setprecision(0);

	if (!DEBUG) {
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	}

	int _c, _start = static_cast<int>(clock());
	cin >> _c;

	for(int _cc = 1; _cc <= _c; ++_cc) {
		int _t = static_cast<int>(clock());
		cout << "Case #" << _cc << ": ";

		cin >> n;

		for (int i = 0; i < 2 * n - 1; ++i) {
			gg[i] = "";
			for (int j = 0; j < n; ++j) {
				int k;
				cin >> k;
				gg[i] += k;
			}
		}

		sort(gg, gg + 2 * n - 1);

		missing = -1;
		for (int i = 1; i < 2 * n - 1; i += 2) {
			if (gg[i] != gg[i - 1]) {
				missing = i - 1;
				break;
			}
		}
		if (missing == -1) {
			missing = 2 * n - 2;
		}

		memset(grid, 0, sizeof(grid));
		dfs(0);

		cerr << "[Case #" << _cc << " complete, " << static_cast<int>(clock() - _t) << " ms, " << 100. * _cc / _c << "%]" << endl;
	}

	cerr << "Total time: " << static_cast<int>(clock() - _start) << " ms" << endl;

	return 0;
}

