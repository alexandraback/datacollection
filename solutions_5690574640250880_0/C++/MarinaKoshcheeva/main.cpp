#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 60;
const int dx[9] = {0, 0, 1, 1, 1, -1, -1, -1, 0};
const int dy[9] = {1, -1, -1, 0, 1, -1, 0, 1, 0};

const int px[4] = {0, 0, 1, -1};
const int py[4] = {1, -1, 0, 0};

int num[MAXN][MAXN];
char board[MAXN][MAXN];
bool used[MAXN][MAXN];
int c, r, m;
bool invert;

bool in_board(int x, int y) {
	return (0 <= x && x < r && 0 <= y && y < c);
}

int number_adj_mines(int x, int y) {
	if (board[x][y] == '*')
		return -1;

	int res = 0;
	for (int k = 0; k < 8; ++k) {
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (in_board(xx, yy) && board[xx][yy] == '*')
			res++;
	}

	return res;
}

bool is_adj_zero(int x, int y) {
	if (num[x][y] == 0)
		return true;
	for (int k = 0; k < 8; ++k) {
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (in_board(xx, yy) && num[xx][yy] == 0)
			return true;
	}
	return false;
}

int dfs(int x, int y) {
	used[x][y] = true;
	int res = (num[x][y] >= 0);
	if (num[x][y] == 0) {
		for (int k = 0; k < 8; ++k) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (in_board(xx, yy) && num[xx][yy] >= 0 && !used[xx][yy])
				res += dfs(xx, yy);
		}
	}
	return res;
}

bool is_correct_board() {
	memset(num, -1, sizeof(num));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (board[i][j] != '*')
				num[i][j] = number_adj_mines(i, j);

	int nums = 0;
	int adjz = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			if (num[i][j] >= 0)
				nums++;
			if (num[i][j] >= 0 && is_adj_zero(i, j))
				adjz++;
		}

	if (nums == 1) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (num[i][j] >= 0) {
					board[i][j] = 'c';
					return true;
				}
	}

	if (nums != adjz)
		return false;

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (num[i][j] == 0) {
				memset(used, 0, sizeof(used));
				if (dfs(i, j) == nums) {
					board[i][j] = 'c';
					return true;
				}
			}

	return false;
}

bool fill_horizon() {
	if (m > c * (r - 2) || m == c * (r - 2) - 1)
		return false;
	
	memset(board, 0, sizeof(board));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			board[i][j] = '.';

	int left = m;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c && left > 0; ++j, left--)
			board[i][j] = '*';

	for (int i = 0; i < r; ++i)
		if (c >= 2 && m == (i + 1) * c - 1) {
			board[i][c - 2] = '.';
			board[i + 1][0] = '*';
			break;
		}

	return true;
}

bool fill_center(int cx, int cy) {
	if (m == r * c)
		return false;

	memset(board, 0, sizeof(board));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			board[i][j] = '*';

	if (m == r * c - 1) {
		board[r - 1][c - 1] = 'c';
		return true;
	}

	vector< pair<int, int> > dist;
	queue< pair<int, int> > q;
	bool visited[MAXN][MAXN];

	memset(visited, 0, sizeof(visited));
	q.push(make_pair(cx, cy));
	dist.push_back(make_pair(cx, cy));
	visited[cx][cy] = true;

	while (dist.size() < 2 * (r * c - m) && !q.empty()) {
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int xx = sx + px[k];
			int yy = sy + py[k];
			if (in_board(xx, yy) && !visited[xx][yy]) {
				q.push(make_pair(xx, yy));
				dist.push_back(make_pair(xx, yy));
				visited[xx][yy] = true;
			}
		}
	}

	int next = 0;
	int curm = r * c;
	while (curm > m) {
		int sx = dist[next].first;
		int sy = dist[next].second;
		next++;
		for (int k = 0; k < 9; ++k) {
			int xx = sx + dx[k];
			int yy = sy + dy[k];
			if (in_board(xx, yy) && board[xx][yy] == '*') {
				board[xx][yy] = '.';
				curm--;
			}
		}
	}

	return (curm == m);
}

void print_board() {
	if (invert) {
		for (int i = 0; i < c; ++i) {
			for (int j = 0; j < r; ++j)
				cout << board[j][i];
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j)
				cout << board[i][j];
			cout << endl;
		}
	}
}

void solve(int test_id) {
	cout << "Case #" << test_id << ":" << endl;
	invert = false;
	cin >> r >> c >> m;

	if (fill_horizon()) {
		if (is_correct_board()) {
			print_board();
			return;
		}
	}

	invert = true;
	swap(r, c);
	if (fill_horizon()) {
		if (is_correct_board()) {
			print_board();
			return;
		}
	}
	
	swap(r, c);
	invert = false;
	if (fill_center(r / 2, c / 2)) {
		if (is_correct_board()) {
			print_board();
			return;
		}
	}

	if (fill_center(r - 1, c - 1)) {
		if (is_correct_board()) {
			print_board();
			return;
		}
	}

	cout << "Impossible" << endl;
}

void solve2(int test_id) {
	cout << "Case #" << test_id << ":" << endl;;
	invert = false;
	cin >> r >> c >> m;

	for (int mask = 0; mask < (1 << (r * c)); ++mask) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				board[i][j] = '.';

		int mines = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (mask & (1 << (i * c + j))) {
					mines++;
					board[i][j] = '*';
				}

		if (mines == m) {
			if (is_correct_board()) {
				print_board();
				return;
			}
		}
	}

	cout << "Impossible" << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve2(test_id);
	return 0;
}
