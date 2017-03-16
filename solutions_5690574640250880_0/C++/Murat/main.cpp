#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
  
#include <iostream>
  
#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>
  
using namespace std;
  
template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }
  
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
  
typedef long long li;
typedef double ld;
typedef pair<int, int> pt;
  
const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 145;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

char field[N][N];

bool one_corner(int h, int w, int m) {
	int w_max = w - 2;
	int h_max = h - 2;
	if (w_max * h_max < m)
		return false;
	forn (i, h_max) {
		forn (j, w_max) {
			if (m <= 0)
				break;
			field[i][j] = '*';
			--m;
		}
		if (m <= 0)
				break;
	}
	field[h - 1][w - 1] = 'c';
	return true;
}

bool one_stripe(int h, int w, int m) {
	if (m < h)
		return false;
	int f = h * w - m;
	int gap = f / h;
	if (gap < 2)
		return false;
	int rem = f % h;
	int lf = m, rg = 0;
	if (rem == 1) {
		/* one mine to move */
		if (h <= 2)
			return false;
		if (gap <= 3)
			return false;
		--lf;
		++rg;
	}
	forn (j, w) {
		forn (i, h) {
			--lf;
			if (lf < 0)
				break;
			field[i][j] = '*';
		}
		if (lf <= 0)
			break;
	}
	for (int j = w - 1; j >= 0; --j) {
		for (int i = h - 1; i >= 0; --i) {
			--rg;
			if (rg < 0)
				break;
			field[i][j] = '*';
		}
		if (rg <= 0)
			break;
	}
	field[0][w - 1] = 'c';
	return true;
}

bool two_stripes(int h, int w, int m) {
	if (m < h)
		return false;
	int f = h * w - m;
	int gap = f / h;
	if (gap < 3)
		return false;
	int rem = f % h;
	int lf = h, rg = m - h;
	if (rem == 1) {
		/* one mine should be moved */
		if (h <= 2)
			return false;
		if (gap == 3)
			return false;
		++lf;
		--rg;
	}
	forn (j, w) {
		forn (i, h) {
			--lf;
			if (lf < 0)
				break;
			field[i][j] = '*';
		}
		if (lf <= 0)
			break;
	}
	for (int j = w - 1; j >= 0; --j) {
		forn (i, h) {
			--rg;
			if (rg < 0)
				break;
			field[i][j] = '*';
		}
		if (rg <= 0) {
			field[0][j - 2] = 'c';
			break;
		}
	}
	return true;
}

bool free_corner(int h, int w, int m) {
	if (w < 3 || h < 3 || m < h + w - 1)
		return false;
	int f = h * w - m;
	int min_w = 2;
	int min_h = 2;
	if (f < min_w * min_h)
		return false;
	int max_w = w - 1;
	for (int u = min_w; u <= max_w; ++u) {
		int v = f / u;
		if (v < min_h)
			continue;
		int rem = f % u;
		if (rem)
			rem = u - rem;
		int ow_max, oh_max;
		if (rem > 0) {
			++v;
			ow_max = u - 2;
			oh_max = v - 2;
			if (ow_max * oh_max < rem)
				continue;
		}
		int oi = h - v;
		int oj = w - u;
		forn (i, oi)
			forn (j, w)
				field[i][j] = '*';
		for (int i = oi; i < h; ++i)
			forn (j, oj)
				field[i][j] = '*';
		if (rem > 0) {
			forn (i, oh_max) {
				forn (j, ow_max) {
					if (rem <= 0)
						break;
					field[oi + i][oj + j] = '*';
					--rem;
				}
				if (rem <= 0)
					break;
			}
		}
		return true;
	}
	return false;
}

bool c_shaped(int h, int w, int m) {
	if (w < 3 || m < h + 2 * w - 2)
		return false;
	/* TODO */
	return false;
}

bool rec(int h, int w, int m, int prev, int row) {
	if (m <= 0) {
		if (row < h - 1)
			return true;
		return false;
	}
	if (row == h - 2) {
		if (m & 1)
			return false;
		int half = m / 2;
		if (half > prev)
			return false;
		forn (i, 2)
			forn (j, half)
				field[row + i][j] = '*';
		return true;
	}
	int cap = (h - row) * prev;
	if (cap < m)
		return false;
	/*
	if (cap == m) {
		printf("cap == m\n");
		for (int i = row; i < h; ++i)
			forn (j, m)
				field[i][j] = '*';
		return true;
	}
	*/
	for (int p = min(m, prev); p > 0; --p) {
		if (rec(h, w, m - p, p, row + 1)) {
			//printf("row #%d: %d\n", row, p);
			forn (j, p)
				field[row][j] = '*';
			return true;
		}
	}
	return false;
}

bool alternative(int h, int w, int m) {
	int fulls = min(m / w, h - 2);
	for (int f = 0; f <= fulls; ++f) {
		if (rec(h, w, m - f * w, w - 2, f)) {
			//printf("good for f %d\n", f);
			forn (i, f)
				forn (j, w)
					field[i][j] = '*';
			return true;
		}
	}
	return false;
}

void transpose(int h, int w) {
	int n = max(h, w);
	forn (i, n)
		forn(j, i)
			swap(field[i][j], field[j][i]);
}

bool good_for_start(int r, int c, int x, int y) {
	if (field[x][y] != '.')
		return false;
	forn (i, 8) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!(0 <= nx && nx < r && 0 <= ny && ny < c))
			continue;
		if (field[nx][ny] == '*')
			return false;
	}
	return true;
}

void make_sure_start_present(int r, int c) {
	forn (i, r)
		forn (j, c)
			if (field[i][j] == 'c') {
				if (good_for_start(r, c, i, j))
					return;
				field[i][j] = '.';
			}   
	forn (i, r)
		forn (j, c)
			if (good_for_start(r, c, i, j)) {
				field[i][j] = 'c';
				return;
			}
	puts("Error: start point couldn't be placed");
}

bool used[N][N];

inline bool correct(int r, int c, const pt &p) {
	return 0 <= p.first && p.first < r &&
			0 <= p.second && p.second < c &&
			 !used[p.first][p.second];
}

void check(int r, int c, int m) {
	int count = 0;
	pt start(-1, -1);
	forn (i, r)
		forn (j, c)
			if (field[i][j] == 'c') {
				if (start.first != -1) {
					puts("Error: more than one start point");
					return;
				}
				start = mp(i, j);
			} else if (field[i][j] == '*')
				++count;
	if (count != m) {
		printf("Error: %d mine(s) instead of %d\n", count, m);
		return;
	}
	if (start.first == -1) {
		puts("Error: start point not found");
		return;
	}
	queue<pt> q;
	q.push(start);
	int revealed = 1;
	memset(used, 0, sizeof used);
	used[start.first][start.second] = true;
	while (!q.empty()) {
		pt fm = q.front();
		q.pop();
		bool is_zero = true;
		forn (i, 8) {
			pt to = mp(fm.first + dx[i], fm.second + dy[i]);
			if (!correct(r, c, to))
				continue;
			if (field[to.first][to.second] == '*') {
				is_zero = false;
				break;
			}
		}
		if (!is_zero)
			continue;
		forn (i, 8) {
			pt to = mp(fm.first + dx[i], fm.second + dy[i]);
			if (!correct(r, c, to))
				continue;
			q.push(to);
			++revealed;
			used[to.first][to.second] = true;
		}
	}
	if (revealed + m != r * c) {
		puts("Error: not all free cells could be revealed");
		printf("revealed %d\n", revealed);
		return;
	}
	//puts("Check: OK");
}

int main() {
	int tests;
	scanf("%d", &tests);
	for1(it, tests) {
		int r, c, m;
		scanf("%d%d%d", &r, &c, &m);
		memset(field, '.', sizeof field);
		bool ok = m == 0;
		if (m + 1 == r * c) {
			ok = true;
			forn (i, r)
				forn (j, c)
					field[i][j] = '*';
			field[r - 1][c - 1] = 'c';
		}
		if (!ok)
			ok = alternative(r, c, m);
		if (!ok)
			ok = free_corner(r, c, m);
		if (!ok)
			ok = one_corner(r, c, m);
		if (!ok)
			ok = two_stripes(r, c, m);
		if (!ok) {
			ok = two_stripes(c, r, m);
			if (ok)
				transpose(r, c);
		}
		if (!ok)
			ok = one_stripe(r, c, m);
		if (!ok) {
			ok = one_stripe(c, r, m);
			if (ok)
				transpose(r, c);
		}
		printf("Case #%d:\n", it);
		if (!ok)
			puts("Impossible");
		else {
			if (m + 1 != r * c)
				make_sure_start_present(r, c);
			check(r, c, m);
			forn (i, r) {
				field[i][c] = 0;
				puts(field[i]);
			}
		}
	}  
    return 0;
}
