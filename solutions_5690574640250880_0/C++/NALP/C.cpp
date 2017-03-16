#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

#ifdef _WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;

int xs, ys;

int DFS(int x, int y, const vector<vector<int> > &c, vector<vector<bool> > &used) {
	if (y < 0 || y >= int(c[0].size())) return 0;
	if (x < 0 || x >= int(c.size())) return 0;
	if (used[x][y]) return 0;

	int ans = 1;
	used[x][y] = true;
	if (c[x][y] == 0) {
		for(int dx = -1; dx <= 1; dx++) {
			for(int dy = -1; dy <= 1; dy++) {
				ans += DFS(x + dx, y + dy, c, used);
			}
		}
	}

	return ans;
}

bool check(const vector<string> &a) {
	xs = ys = -1;
	int n = int(a.size()), m = int(a[0].size()), f = 0;
	vector<vector<int> > c(n, vector<int>(m, 0));
	forn(x, n) {
		forn(y, m) {
			for(int dx = -1; dx <= 1; dx++) {
				for(int dy = -1; dy <= 1; dy++) {
					int nx = x + dx, ny = y + dy;
					if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == '*') {
						c[x][y]++;
					}
				}
			}

			if (a[x][y] == '*') {
				c[x][y] = -1;
			} else {
				f++;
			}

			if (a[x][y] == 'c') {
				xs = x;
				ys = y;
			}
		}
	}

	forn(x, n) {
		forn(y, m) {
			if (xs == -1 && ys == -1 && c[x][y] == 0) {
				xs = x;
				ys = y;
			}
		}
	}

	forn(x, n) {
		forn(y, m) {
			if (xs == -1 && ys == -1 && c[x][y] != -1) {
				xs = x;
				ys = y;
			}
		}
	}

	vector<vector<bool> > used(n, vector<bool>(m, false));
	bool ans = DFS(xs, ys, c, used) == f;
	return ans;
}

bool gen(int x, int y, int n, int m, int c, vector<string> &a) {
	if (x == n) {
		return c == 0 && check(a);
	}

	if (y == m) {
		return gen(x + 1, 0, n, m, c, a);
	}

	if (gen(x, y + 1, n, m, c, a)) {
		return true;
	}

	if (c > 0) {
		a[x][y] = '*';
		if (gen(x, y + 1, n, m, c - 1, a)) {
			return true;
		}
		a[x][y] = '.';
	}

	return false;
}

int n, m, c;

bool stupid() {
    vector<string> a(n, string(m, '.'));
	return gen(0, 0, n, m, c, a);
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        n = nextInt();
		m = nextInt();
		c = nextInt();
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        // generate test.
    }

	bool rev = false;
	if (n < m) {
		rev = true;
		swap(n, m);
	}

    vector<string> a(n, string(m, '*'));
	int f = n * m - c;
	if (f >= 2 * m) {
	    a = vector<string>(n, string(m, '.'));
		forn(i, n) {
			forn(j, m) {
				if (i*m + j >= f) {
					a[i][j] = '*';
				}
			}
		}
	} else {
		int c1 = (f + 1) / 2, c2 = f - c1;
		forn(i, c1) a[0][i] = '.';
		forn(i, c2) a[1][i] = '.';
	}
	a[0][0] = 'c';

    a = vector<string>(n, string(m, '.'));
	bool ans = gen(0, 0, n, m, c, a);
	if (!ans) {
		cout << "\nImpossible" << endl;
	} else {
		a[xs][ys] = 'c';
		cout << endl;
		if (!rev) {
			forn(i, n) {
				forn(j, m) cout << a[i][j];
				cout << endl;
			}
		} else {
			forn(i, m) {
				forn(j, n) cout << a[j][i];
				cout << endl;
			}
		}
	}

    cerr << "\tclever answer is '" << ans << "'." << endl;
    if (n * m <= 28) {
        bool stupidAnswer = stupid();
        cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
        assert(ans == stupidAnswer);
    }
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
    //freopen("input.txt", "rt", stdin);
  //freopen("output.txt", "wt", stdout);
#else
#endif

    int minTest = 1, maxTest = INF;
    if (argc == 3) {
        minTest = atoi(argv[1]);
        maxTest = atoi(argv[2]);
    }

    cout.precision(10);
    cout.setf(ios::fixed);

    cerr.precision(10);
    cerr.setf(ios::fixed);

    srand((unsigned int)time(0));
    int tests = nextInt();
    clock_t totalStartTime = clock();
    for(int test = 1; test <= tests; test++) {
        clock_t startTime = clock();
        cerr << "Case #" << test << endl;
        bool skipThisTest = (test < minTest || test > maxTest);
        if (!skipThisTest) cout << "Case #" << test << ":";
        solve(skipThisTest);

        char formattedTime[100];
        clock_t time = clock() - startTime;
        sprintf(formattedTime, "%d.%03d", int(time / CLOCKS_PER_SEC), int(time % CLOCKS_PER_SEC));
        cerr << "time for test is " << formattedTime << " s." << endl << endl;
    }

    char formattedTime[100];
    clock_t totalTime = clock() - totalStartTime;
    sprintf(formattedTime, "%d.%03d", int(totalTime / CLOCKS_PER_SEC), int(totalTime % CLOCKS_PER_SEC));
    cerr << string(20, '=') << endl;
    cerr << "TOTAL TIME IS " << formattedTime << " s." << endl;

    return 0;
}
