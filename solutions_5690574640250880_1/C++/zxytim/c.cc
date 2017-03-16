/*
 * $File: c.cc
 * $Date: Sun Apr 13 02:15:10 2014 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <cassert>
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

typedef vector<int> board_t;
typedef tuple<int, int, int> triple;


map<triple, pair<int, board_t>> mem[2][2];  // (r, c, m) -> (win, board)

struct Conf {
	bool right_dirty;
	bool down_dirty;
};

vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

inline bool in_range(int x, int y, int r, int c) {
	return x >= 0 && x < r && y >= 0 && y < c;
}

int grid_val(board_t &board, int r, int c, int p, bool right_dirty, bool down_dirty) {
	int val = 0;
	int i = p / c,
		j = p % c;
	for (auto &d: dirs) {
		int x = i + d.first,
			y = j + d.second;
		int q = x * c + y;
		if (in_range(x, y, r, c)) {
			if (board[q] == 1)
				val ++;
		} else if (right_dirty && y == c) {
			val ++;
		} else if (down_dirty && x == r) {
			val ++;
		}
	}
	return val;
}

int get_nr_mine(board_t &board) {
	int ret = 0;
	for (auto &v: board)
		ret += (v == 1);
	return ret;
}

bool try_click(board_t &board, int r, int c, int p, bool right_dirty, bool down_dirty) {
	int n = r * c;
	assert(n == (int)board.size());
	vector<bool> hash(n);
	queue<int> que;
	hash[p] = true;
	que.push(p);
	int nr_reveal = 1;
	while (!que.empty()) {
		int p = que.front(); que.pop();
		int i = p / c,
			j = p % c;
		for (auto &d: dirs) {
			int x = i + d.first,
				y = j + d.second;
			int q = x * c + y;
			if (in_range(x, y, r, c) && board[q] == 0 && !hash[q]) {
				hash[q] = true;
				nr_reveal ++;
				if (grid_val(board, r, c, q, right_dirty, down_dirty) == 0)
					que.push(q);
			}
		}
	}
	return nr_reveal + get_nr_mine(board) == n;
}


bool valid(board_t &board, int r, int c, bool right_dirty, bool down_dirty) {
	int nr_mine = 0;
	int space = -1;
	for (int i = 0, p = 0; i < r; i ++)
		for (int j = 0; j < c; j ++, p ++) {
			if (board[p] != 0) {
				nr_mine ++;
				continue;
			}
			space = p;
			if (grid_val(board, r, c, p, right_dirty, down_dirty) != 0)
				continue;
			if (try_click(board, r, c, p, right_dirty, down_dirty)) {
				board[p] = 2;
				return true;
			} else {
				return false;
			}
			// must return
			assert(0);
		}
	if (nr_mine + 1 == r * c) {
		board[space] = 2;
		return true;
	}
	return false;
}

bool do_search(board_t &board, int r, int c, int cur, int m, bool right_dirty, bool down_dirty) {
	if (m == 0)
		return valid(board, r, c, right_dirty, down_dirty);
	int n = r * c;
	for (int i = cur; i < n; i ++) {
		board[i] = 1;
		if (do_search(board, r, c, i + 1, m - 1, right_dirty, down_dirty))
			return true;
		board[i] = 0;
	}
	return false;
}

pair<int, board_t> search(int r, int c, int m, bool right_dirty, bool down_dirty) {
	int n = r * c;
	board_t board(n);
	bool rst = do_search(board, r, c, 0, m, right_dirty, down_dirty);
	return make_pair(rst, board);
}

pair<int, board_t> get_ans(int r, int c, int m, bool right_dirty, bool down_dirty) {
	auto &rem = mem[right_dirty][down_dirty];
	auto tri = triple(r, c, m);
	if (rem.count(tri))
		return rem[tri];

	return rem[tri] = search(r, c, m, right_dirty, down_dirty);
}

void print_board(board_t &board, int r, int c) {
	for (int i = 0, p = 0; i < r; i ++) {
		for (int j = 0; j < c; j ++, p ++) {
			int v = board[p];
			printf("%c", v == 0 ? '.' : (v == 1 ? '*' : 'c'));
		}
		printf("\n");
	}
	fflush(stdout);
}

void print_result(pair<int, board_t> &&result, int r, int c) {
	if (result.first == 0) {
		printf("Impossible\n");
		fflush(stdout);
	} else {
		print_board(result.second, r, c);

		board_t board = result.second;
		for (int i = 0; i < r * c; i ++)
			if (board[i] == 2)
				board[i] = 0;
		assert(valid(board, r, c, 0, 0));
	}
}

void fill_width_first(board_t &board, int r, int c, int h, int w, int n) {
	assert(n <= h * w);
	int x_s = r - h,
		y_s = c - w;
	for (int i = r - 1; i >= x_s && n; i --)
		for (int j = c - 1; j >= y_s && n; j --, n --) {
			int p = i * c + j;
			board[p] = 1;
		}
}

void solve(int r, int c, int m) {
	int min_width = 3;
	if (r <= min_width && c <= min_width)
		print_result(get_ans(r, c, m, 0, 0), r, c);
	else {
		board_t board(r * c);
		int n = r * c;
		bool rst = false;
		if (r == 1 || c == 1) { // another one > 3
			for (int i = 0; i < max(r, c); i ++)
				board[i] = (i == max(r, c) - 1 ? 2 : (i < m ? 1 : 0));
			rst = 1;
		} else if (r == 2) { // c > 3
			for (int j = 0; j < c && m; j ++)
				for (int i = 0; i < 2 && m; i ++, m --)
					board[i * c + j] = 1;
			rst = valid(board, r, c, 0, 0);
		} else if (c == 2) { // r > 3
			for (int i = 0; i < m; i ++)
				board[i] = 1;
			rst = valid(board, r, c, 0, 0);
		} else { // r, c >= 3
			if (m <= (r - 2) * (c - 2)) {
				fill_width_first(board, r, c, r - 2, c - 2, m);
				board[0] = 2;
				rst = true;
			} else {
				int nr_ones = (r - 2) * (c - 2);
				int nr_twos = (r - 2) + (c - 2);
				if ((m - nr_ones) % 2 == 0 && (m - nr_ones) / 2 <= nr_twos) {
					fill_width_first(board, r, c, r - 2, c - 2, nr_ones);
					int n2 = (m - nr_ones) / 2;
					for (int i = r - 1; i >= 2 && n2; i --, n2 --)
						board[i * c] = board[i * c + 1] = 1;
					for (int j = c - 1; j >= 2 && n2; j --, n2 --)
						board[j] = board[c + j] = 1;
					board[0] = 2;
					rst = true;
				} else {
					nr_ones = (r - 2) * (c - 2) - 1;
					nr_twos = (r - 3) + (c - 3);
					fill_width_first(board, r, c, r - 2, c - 2, nr_ones);
					int n2 = min(nr_twos, (m - nr_ones) / 2);
					int nr_remain = m - nr_ones - n2 * 2;

					for (int i = r - 1; i >= 3 && n2; i --, n2 --)
						board[i * c] = board[i * c + 1] = 1;
					for (int j = c - 1; j >= 3 && n2; j --, n2 --)
						board[j] = board[c + j] = 1;
					board[0] = 2;

					if ((m - nr_ones) % 2 == 0 && (m - nr_ones) / 2 <= nr_twos) {
						rst = true;
					} else { // remain 3x3
						auto a = get_ans(3, 3, nr_remain, c > 3, r > 3);
						rst = a.first;
						for (int i = 0; i < 3; i ++)
							for (int j = 0; j < 3; j ++) {
								int p = i * c + j;
								int q = i * 3 + j;
								board[p] = a.second[q];
							}
					}
				}
			}
		}

		print_result(make_pair(rst, board), r, c);
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++) {
		printf("Case #%d:\n", i);
//        fprintf(stderr, "Case #%d:\n", i);
		int r, c, m;
		cin >> r >> c >> m;
		solve(r, c, m);
	}
	return 0;
}

/*
 * vim: syntax=cpp11.doxygen foldmethod=marker
 */

