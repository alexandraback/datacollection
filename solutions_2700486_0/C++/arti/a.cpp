#include <iostream>

#include <algorithm>
#include <functional>
#include <utility>

#include <cmath>
#include <numeric>
#include <complex>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

#include <iomanip>
#include <sstream>

#include <cctype>
#include <cstring>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef unsigned char uchar;
typedef short int sint;
typedef unsigned short int usint;
typedef unsigned int uint;
typedef long long i64;
typedef unsigned long long ui64;
typedef double dbl;
typedef long double ldbl;

#define pb push_back
#define mp make_pair

#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

const long double EPS = 1e-9;
const int iINF = INT_MAX;
const long double ldblINF = 1e100;

const int dd[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int dd2[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

const int cx = 10;

int a[21][21];

int X, Y;
int resultA, resultB;
bool f;

void solve(int n) {
	if (!n) {
		if (f) ++resultA;
		++resultB;
		return;
	}
	int y = 20;
	int x = cx;
	while (y > 0 && !a[x][y - 2]) --y;
	bool ff = f;
	if (y == 0) {
		if (X == x && Y == y) {
			f = true;
		}
		a[x][y] = 1;
		solve(n - 1);
		a[x][y] = 0;
		f = ff;
	} else {
		if (!a[x - 1][y - 1]) {
			int tx = x, ty = y;
			while (y > 0 && !a[x - 1][y - 1]) --x, --y;
			if (X == x && Y == y) {
				f = true;
			}
			a[x][y] = 1;
			solve(n - 1);
			a[x][y] = 0;
			f = ff;
			x = tx, y = ty;
		}
		if (!a[x + 1][y - 1]) {
			int tx = x, ty = y;
			while (y > 0 && !a[x + 1][y - 1]) ++x, --y;
			if (X == x && Y == y) {
				f = true;
			}
			a[x][y] = 1;
			solve(n - 1);
			a[x][y] = 0;
			f = ff;
			x = tx, y = ty;
		}
		if (a[x + 1][y - 1] && a[x - 1][y - 1]) {
			if (X == x && Y == y) {
				f = true;
			}
			a[x][y] = 1;
			solve(n - 1);
			a[x][y] = 0;
			f = ff;
		}
	}
}

int main() {
	int T; scanf("%d\n", &T);
	for (int tt = 1; tt <= T; ++tt) {
		int n, x, y;
		cin >> n >> x >> y;
		X = cx + x; Y = y;
		memset(a, 0, sizeof(a));
		resultA = 0, resultB = 0;
		f = false;
		solve(n);
		printf("Case #%d: %.10lf", tt, resultA / (double)resultB);
		putchar('\n');
	}
	return 0;
}
