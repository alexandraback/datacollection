#include <cstdlib>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <limits>
#include <exception>

#include <cmath>
#include <cstring>
#include <cassert>
#include <ctime>

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <list>

#define ALL(container) (container).begin(), (container).end()
#define MP std::make_pair
#define SZ(x) int((x).size())

#define X first
#define Y second

typedef long long i64;
typedef unsigned long long u64;

typedef std::pair<int, int> pii;

template<typename t>
inline t sqr(const t x) {
	return x * x;
}

template<typename A, typename B>
A convert(const B &x) {
	A res;
	std::stringstream ss;
	ss << x;
	ss >> res;
	return res;
}

#define FILE_NAME "test"
std::ifstream fin(FILE_NAME ".in");
std::ofstream fout(FILE_NAME ".out");

const int maxn = 55;

int dp[maxn][maxn][maxn * maxn];
char map[maxn][maxn];

bool Solve(int r, int c, int m) {
	if (r * c <= 4) {
		if (r == 2 && c == 2) {
			return m == 0 || m == 3;
		} else {
			assert(m + 1 <= r * c);
			return true;
		}
	}

	if (dp[r][c][m] != 0)
		return dp[r][c][m] == 1;

	if (m == 0) {
		dp[r][c][m] = 1;
		return true;
	}

	// Cut row.
	if (r > 2) {
		if (m < c) {
			if (m < c - 1) {
				dp[r][c][m] = 1;
				return true;
			} else {  // m == c - 1
				if (Solve(r - 1, c, 1)) {
					dp[r][c][m] = 1;
					return true;
				}
			}
		} else {
			if (Solve(r - 1, c, m - c)) {
				dp[r][c][m] = 1;
				return true;
			}
		}
	}

	// Cut column.
	if (c > 2) {
		if (m < r) {
			if (m < r - 1) {
				dp[r][c][m] = 1;
				return true;
			} else {  // m == r - 1
				if (Solve(r, c - 1, 1)) {
					dp[r][c][m] = 1;
					return true;
				}
			}
		} else {
			if (Solve(r, c - 1, m - r)) {
				dp[r][c][m] = 1;
				return true;
			}
		}
	}

	dp[r][c][m] = -1;
	return false;
}

bool Fill(int r, int c, int m) {
	if (r * c <= 4) {
		if (r == 2 && c == 2) {
			if (m == 0) {
				return true;
			} else if (m == 3) {
				map[0][1] = map[1][0] = map[1][1] = '*';
				return true;
			}
		} else {
			if (r > 1) {
				for (int i = r - 1; i >= r - m; --i)
					map[i][0] = '*';
			} else {
				for (int j = c - 1; j >= c - m; --j)
					map[0][j] = '*';
			}
			return true;
		}
	}

	//assert(dp[r][c][m] == 1);
	if (dp[r][c][m] == -1)
		return false;

	if (m == 0) {
		return true;
	}

	// Cut row.
	if (r > 2) {
		if (m < c) {
			if (m < c - 1) {
				for (int j = c - m; j < c; ++j)
					map[r - 1][j] = '*';
				return true;
			} else {  // m == c - 1
				if (Fill(r - 1, c, 1)) {
					for (int j = 2; j < c; ++j)
						map[r - 1][j] = '*';
					return true;
				}
			}
		} else {
			if (Fill(r - 1, c, m - c)) {
				for (int j = 0; j < c; ++j)
					map[r - 1][j] = '*';
				return true;
			}
		}
	}

	// Cut column.
	if (c > 2) {
		if (m < r) {
			if (m < r - 1) {
				for (int i = r - m; i < r; ++i)
					map[i][c - 1] = '*';
				return true;
			} else {  // m == r - 1
				if (Fill(r, c - 1, 1)) {
					for (int i = 2; i < r; ++i)
						map[i][c - 1] = '*';
					return true;
				}
			}
		} else {
			if (Fill(r, c - 1, m - r)) {
				for (int i = 0; i < r; ++i)
					map[i][c - 1] = '*';
				return true;
			}
		}
	}

	assert(false && "NOTREACHED");
	return false;
}

int main() {
	assert(fin && fout);
	std::ios_base::sync_with_stdio(false);

	int testsCnt;
	fin >> testsCnt;
	for (int testIdx = 1; testIdx <= testsCnt; ++testIdx) {
		int r, c, m;
		fin >> r >> c >> m;
		memset(map, '.', sizeof(map));
		map[0][0] = 'c';

		//if (testIdx != 22)
		//	continue;

		fout << "Case #" << testIdx << ":\n";
		if (Solve(r, c, m)) {
			bool test = Fill(r, c, m);
			assert(test);

			int mines = 0;
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					fout << map[i][j];
					if (map[i][j] == '*')
						++mines;
				}
				fout << '\n';
			}
			assert(mines == m);
		} else {
			fout << "Impossible\n";
		}
	}

	return 0;
}
