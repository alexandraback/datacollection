/*
 * b-small.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {}

string solve(int tx, int ty) {
	int n = 500;
	vector<vector<string> > grid(n, vector<string> (n));
	vector<vector<string> > accu(n, vector<string> (n));
	int sx = 250, sy = 250;
	int dx = tx + 250, dy = ty + 250;
	grid[sx+1][sy] = "E";
	grid[sx-1][sy] = "W";
	grid[sx][sy+1] = "N";
	grid[sx][sy-1] = "S";
	for (int k = 2; k <= 500; ++k) {
		accu.assign(n, vector<string>(n));
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				if (not grid[x][y].empty()) {
					if (x == dx && y == dy)
						return grid[x][y];
					if (x + k < n)
						accu[x+k][y] = grid[x][y] + "E";
					if (y + k < n)
						accu[x][y+k] = grid[x][y] + "N";
					if (x - k >= 0)
						accu[x-k][y] = grid[x][y] + "W";
					if (y - k >= 0)
						accu[x][y-k] = grid[x][y] + "S";
				}
			}
		}
		swap(accu, grid);
	}
	return "";
}

int main(void) {
	int ncase; cin >> ncase;
	forn(t, ncase) {
		int x, y; cin >> x >> y;
		string ans = solve(x, y);
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}
	return 0;
}
