#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve(int n, int m, const vector<vector<int>>& board)
{
	vector<int> v(n), h(m);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		v[i] = max(v[i], board[i][j]);
		h[j] = max(h[j], board[i][j]);
	}
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (board[i][j] != min(v[i], h[j])) {
			return false;
		}
	}
	return true;
}

int main()
{
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> board(n, vector<int>(m));
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
		cout << "Case #" << test + 1 << ": " << (solve(n, m, board) ? "YES" : "NO") << endl;
	}
}
