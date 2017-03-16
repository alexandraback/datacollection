#include <iostream>
#include <vector>
using namespace std;

int R, C;
bool range(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C)
		return false;
	return true;
}

void floodfill(vector<vector<char> >& map, int r, int c, vector<vector<bool> >& seen) {
	if (!range(r, c))
		return;
	if (seen[r][c])
		return;
	seen[r][c] = true;
	for (int x = -1; x <= 1; ++x)
		for (int y = -1; y <= 1; ++y)
			if (range(r+y, c+x) && map[r+y][c+x] != '.')
				return;
	for (int x = -1; x <= 1; ++x)
		for (int y = -1; y <= 1; ++y)
			if (range(r+y, c+x))
				floodfill(map, r+y, c+x, seen);
}

bool solve() {
	int M;
	cin >> R >> C >> M;
	int N = R*C - M;

	vector<vector<char> > map(R, vector<char>(C, '*'));
	if (N == 1) {
	}
	else if (R == 1) {
		for (int i = 0; i < N; ++i) map[0][i] = '.';
	}
	else if (C == 1) {
		for (int i = 0; i < N; ++i) map[i][0] = '.';
	}
	else if (N == 2 || N == 3 || N == 5 || N == 7) {
		return false;
	}
	else if (N%2 == 1 && (R == 2 || C == 2)) {
		return false;
	}
	else {
		int r = 0;
		while (N > 3 && r+1 < R) {
			for (int c = 0; c < C; ++c) {
				if (N == 1) {
					map[r][c] = '.';
					N = 0;
					break;
				}
				map[r][c] = map[r+1][c] = '.';
				N -= 2;
				if (!N || (N == 3 && (c+2 == C || r == 0))) break;
			}
			r += 2;
		}
		for (int c = 0; c < N; ++c) {
			map[r][c] = '.';
		}
	}

	if (N%2 == 1) {
		for (int i = R-1; i-2 >= 0; --i) {
			if (map[i][C-1] == '.' && map[i-1][C-1] == '*' && map[i-2][C-1] == '*') {
				swap(map[i][C-1], map[i-2][C-1]);
				break;
			}
		}
	}

	vector<vector<bool> > seen(R, vector<bool>(C, false));
	floodfill(map, 0, 0, seen);
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j)
			if (map[i][j] == '.' && !seen[i][j]) cerr << '%';
	}

	map[0][0] = 'c';
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j)
			cout << map[i][j];
		cout << endl;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cout << "Case #" << i+1 << ":\n";
		bool r = solve();
		if (!r) {
			cout << "Impossible" << endl;
		}
	}
}
