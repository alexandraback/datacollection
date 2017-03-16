#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;
//#define double long double
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i, n)  for (int i = 0; i < int(n); ++i)
#define ford(i, n)  for (int i=int(n) - 1; i >= 0; --i)
#define fore(i, l, r)  for (int i = int(l); i < int(r); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 55;


int r, c, cnt;


void read() {
	cin >> r >> c >> cnt;
}


char ans[MAXN][MAXN];
bool u[MAXN][MAXN];

void dfs(int x, int y) {
	if (u[x][y] || ans[x][y] == '*')
		return;
	u[x][y] = true;

	bool zero = true;
	for (int dx = -1; dx <= 1; ++dx)
		for (int dy = -1; dy <= 1; ++dy)
			if (dx || dy) {
				int nx = x + dx;
				int ny = y + dy;
				if (0 <= nx && nx < r && 0 <= ny && ny < c)
					if (ans[nx][ny] == '*')
						zero = false;
			}

	if (zero)
		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy)
				if (dx || dy) {
					int nx = x + dx;
					int ny = y + dy;
					if (0 <= nx && nx < r && 0 <= ny && ny < c)
						dfs(nx, ny);
				}
}

void validate() {
	int starts = 0, bombs = 0;
	int start_x, start_y;
	forn(x, r)
		forn(y, c)	
			if (ans[x][y] == 'c') {
				++starts;
				start_x = x;
				start_y = y;
			}
			else if (ans[x][y] == '*')
				++bombs;
			else if (ans[x][y] != '.')
				throw;
	if (starts != 1)
		throw;
	if (bombs != cnt)
		throw;

	memset(u, 0, sizeof u);
	dfs(start_x, start_y);
	forn(x, r)
		forn(y, c)
			if (ans[x][y] != '*' && !u[x][y])
				throw;
}

void solve() {
	bool swapped = false;
	if (r < c) {
		swap(r, c);
		swapped = true;
	}

	memset(ans, '.', sizeof ans);
	ans[0][0] = 'c';

	if (cnt == r * c - 1) {
		forn(x, r)
			forn(y, c)
				if (x + y > 0)
					ans[x][y] = '*';
	} else if (c == 1) {
		forn(x, cnt)
			ans[r - 1 - x][0] = '*';
	} else if (c == 2) {
		if (cnt % 2 == 1 || cnt > r * c - 4) {
			puts("Impossible");
			return;
		}
		forn(i, cnt / 2)
			ans[r - 1 - i][0] = ans[r - 1 - i][1] = '*';
	} else {
		int fill = min(cnt, (r - 3) * c);
		forn(i, fill) {
			int x = r - 1 - i / c;
			int y = c - 1 - i % c;
			if (i == fill - 1 && fill % c == c - 1) {
				--x;
				y = c - 1;
			}
			ans[x][y] = '*';
		}
		int left = cnt - fill;
		if (left % 3 <= 1 && left > 3 * c - 6 || left == 3 * c - 7) {
			puts("Impossible");
			return;
		}
		forn(i, left) {
			int x = 2 - i % 3;
			int y = c - 1 - i / 3;
			if (i == left - 1 && left % 3 == 2) {
				++x;
				--y;
			}
			if (x < 0 || y < 0 || x >= 3 || y >= c)
				throw;
			ans[x][y] = '*';
		}
	}

	if (swapped) {
		forn(x, r)
			forn(y, x)
				swap(ans[x][y], ans[y][x]);
		swap(r, c);
	}
	forn(x, r)
		ans[x][c] = 0;

	validate();

	forn(x, r)
		puts(ans[x]);
}


int main(int argc, char *argv[]) {
	int test_to_execute = (argc == 2) ? atoi(argv[1]) : -1;

	if (test_to_execute == -1) {
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	}

	int tests;
	cin >> tests;
	
	if (test_to_execute != -1 && !(1 <= test_to_execute && test_to_execute <= tests)) {
		cerr << "Requested test doesn't exist!" << endl;
		throw std::exception("Requested test doesn't exist!");
	}

	for (int test = 1; test <= tests; ++test) {
		time_t start_time = clock();
		read();
		if (!cin)
			throw;
		if (test_to_execute != -1 && test != test_to_execute)
			continue;
		printf("Case #%d:\n", test);
		solve();
		cerr << "Test #" << test << " done! [" << (clock() - start_time) / CLOCKS_PER_SEC << " sec]" << endl;
	}
}
