#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
typedef vector<vector<int> > VVI;
typedef vector<int> VI;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool on_edge(const VVI& mat, int x, int y) {
	int R = mat.size();
	int C = mat[0].size();
	if (x == 0 || x + 1 == C) return true;
	if (y == 0 || y + 1 == R) return true;
	return false;
}
bool solve(const VVI& mat, int startx, int starty) {

	bool ok = true;
	for (int r = 0; r < mat.size(); r++) {
		if (mat[r][startx] > mat[starty][startx]) {
			ok = false;
			break;
		}
	}
	if (ok) return true;
	ok = true;
	for (int c = 0; c < mat[0].size(); c++) {
		if (mat[starty][c] > mat[starty][startx]) {
			ok = false;
			break;
		}
	}
	if (ok) return true;
	return false;
}

int main()
{
	int ntests;
	cin >> ntests;
	for (int tt = 0; tt < ntests; tt++) {
		int R, C;
		cin >> R >> C;
		vector<vector<int> > mat(R, vector<int>(C));
		for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
			cin >> mat[r][c];
		}
		bool ok = true;
		for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
			if (!solve(mat, c, r)) {
				ok = false;
				goto label;
			}
		}
		label:
		printf("Case #%d: %s\n", tt + 1, ok ? "YES" : "NO");

	}
	return 0;
}