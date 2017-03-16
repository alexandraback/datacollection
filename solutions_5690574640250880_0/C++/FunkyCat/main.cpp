#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <limits>
#include <cstring>
using namespace std;

typedef long long li;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int,int> pt;


#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n - 1); i >= 0; i--)
#define pb push_back
#define mp make_pair
#define matrix(T,n,m,v) vector<vector<T> >(n, vector<T>(m, v))
#define ft first
#define sc second
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

template<class T> T sqr(const T& x) { return x * x; }
template<class T> T abs(const T& x) { return x < 0 ? -x : x; }

template<class T, class P>
ostream& operator << (ostream& out, std::pair<T, P> p) {
	return (out << '(' << p.first << ' ' << p.second << ')');
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-8;
const ld PI = 3.1415926535897932384626433832795;

const int N = 50 + 3;

int n, m, k;

bool read() {
	cin >> n >> m >> k;
	return true;
}

bool mine[N][N];

void gen1() {
	memset(mine, 0, sizeof(mine));
	int c = k;
	forn (i, n) {
		forn (j, m) {
			if (c) {
				mine[i][j] = true;
				c--;
			}
		}
	}
}

void gen2() {
	memset(mine, 0, sizeof(mine));
	int c = k;
	forn (j, m) {
		forn (i, n) {
			if (c) {
				mine[i][j] = true;
				c--;
			}
		}
	}
}

void gen3() {
	memset(mine, 0, sizeof(mine));
	int x = 0, y = 0;
	int c = k;
	while (c) {
		mine[x][y] = true;
		c--;
		if (x == n - 1 || y == 0) {
			y++;
			while (x > 0 && y < m - 1) {
				x--;
				y++;
		    }
		} else {
			x++;
			y--;
		}
	}
}

void gen4() {
	memset(mine, 0, sizeof(mine));
	int x = 0, y = 0;
	int c = k;
	while (c) {
		mine[x][y] = true;
		c--;
		if (x == 0 || y == m - 1) {
			y++;
			while (x < n - 1 && y > 0) {
				x++;
				y--;
		    }
		} else {
			x--;
			y++;
		}
	}
}

void gen5() {
	memset(mine, 0, sizeof(mine));
	int c = k;
	for (int d = 0; d < n + m - 1 && c; d++) {
		pt l = mp(0, d);
		pt r = mp(d, 0);
		while (l.y >= m) {
			l.x++, l.y--;
		}
		while (r.x >= n) {
			r.x--;
			r.y++;
		}
		
		for(;;) {
			mine[l.x][l.y] = true;
			c--;
			if (c == 0) {
				break;
			}
			if (l.x < r.x) {
				mine[r.x][r.y] = true;
				c--;
				if (c == 0) {
					break;
				}
				l.x++, l.y--;
				r.x--, r.y++;
				if (l.x > r.x) {
					break;
				}
			} else {
				break;
			}
		}
	}
}

void gen6() {
	memset(mine, 0, sizeof(mine));
	int c = k;
	for (int i = 0; c; i++) {
		for (int y = i; y < m; y++) {
			if (c) {
				mine[i][y] = true;
				c--;
			}
		}
		for (int x = i + 1; x < n; x++) {
			if (c) {
				mine[x][i] = true;
				c--;
			}
		}
	}
}

void gen7() {
	memset(mine, 0, sizeof(mine));
	int c = k;
	for (int i = 0; c; i++) {
		for (int x = i; x < n; x++) {
			if (c) {
				mine[x][i] = true;
				c--;
			}
		}
		for (int y = i + 1; y < m; y++) {
			if (c) {
				mine[i][y] = true;
				c--;
			}
		}
	}
}

int a[N][N];
bool used[N][N];
int head, tail;
pt q[N * N];
int ax, ay;

bool check() {
	forn (i, n) {
		forn (j, m) {
			a[i][j] = 0;
			for (int dx = -1; dx < 2; dx++) {
				for (int dy = -1; dy < 2; dy++) {
					int x = i + dx, y = j + dy;
					if (x < 0 || y < 0 || x >= n || y >= m) {
						continue;
					}
					if (mine[x][y]) {
						a[i][j]++;
					}
				}
			}
		}
	}
	forn (cx, n) {
		forn (cy, m) {
			if (mine[cx][cy] != 0) {
				continue;
			}
			memset(used, 0, sizeof(used));
			used[cx][cy] = true;
			head = tail = 0;
			q[head++] = mp(cx, cy);
			while (head != tail) {
				pt v = q[tail++];
				if (a[v.x][v.y] != 0) {
					continue;
				}
				for (int dx = -1; dx < 2; dx++) {
					for (int dy = -1; dy < 2; dy++) {
						int x = v.x + dx, y = v.y + dy;
						if (x < 0 || y < 0 || x >= n || y >= m) {
							continue;
						}
						if (!used[x][y]) {
							used[x][y] = true;
							q[head++] = mp(x, y);
						}
					}
				}
			}
			bool ok = true;
			forn (i, n) {
				forn (j, m) {
					if (!mine[i][j] && !used[i][j]) {
						ok = false;
					}
				}
			}
			if (ok) {
				ax = cx, ay = cy;
				return true;
			}
		}
	}            
	return false;
}

void write() {
	forn (i, n) {
		forn (j, m) {
			if (i == ax && j == ay) {
				cout << 'c';
			} else {
				cout << (mine[i][j] ? '*' : '.');
			}
		}
		cout << endl;
	}
}

void solve(int test) {
	cout << "Case #" << test << ":" << endl;
	gen1();
	if (check()) {
		write();
		return;
	}
	gen2();
	if (check()) {
		write();
		return;
	}
	gen3();
	if (check()) {
		write();
		return;
	}
	gen4();
	if (check()) {
		write();
		return;
	}
	gen5();
	if (check()) {
		write();
		return;
	}
	gen6();
	if (check()) {
		write();
		return;
	}
	gen7();
	if (check()) {
		write();
		return;
	}
	cout << "Impossible" << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int testCnt;
	cin >> testCnt;

	forn (test, testCnt) {
		read();
		solve(test + 1);
	}

	cerr << clock() << endl;
	
    return 0;
}