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
inline int64 nextInt64() { int64 x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;

bool valid(int x, int y) {
	return (0 <= x && x < 4) && (0 <= y && y < 4);
}

void solve() {
	string a[4];
	forn(i, 4)
		cin >> a[i];

	bool empty = false;
	bool wonX = false;
	bool wonO = false;
	forn(x, 4)
		forn(y, 4) {
			if (a[x][y] == '.') empty = true;
			for(int dx = -1; dx <= 1; dx++)
				for(int dy = -1; dy <= 1; dy++) {
					if (dx == 0 && dy == 0) continue;
					vector<pair<int, int> > p(1, mp(x, y));
					while (p.size() < 4) {
						pair<int, int> v = p.back();
						p.pb(mp(v.first + dx, v.second + dy));
					}

					bool v = true;
					string s = "";
					forn(i, p.size())
						if (!valid(p[i].first, p[i].second))
							v = false;
						else
							s += a[p[i].first][p[i].second];
					
					sort(all(s));
					if (s == "XXXX" || s == "TXXX") wonX = true;
					if (s == "OOOO" || s == "OOOT") wonO = true;
				}
		}

	if (wonX) {
		cout << "X won" << endl;
		return;
	}

	if (wonO) {
		cout << "O won" << endl;
		return;
	}

	if (empty) {
		cout << "Game has not completed" << endl;
		return;
	}

	cout << "Draw" << endl;
}

int main() {
#ifdef NALP_PROJECT
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
#endif

	srand(time(0));
	int tests = nextInt();
	forn(test, tests) {
		cerr << "Case #" << test + 1 << endl;
		cout << "Case #" << test + 1 << ": ";
		solve();
	}

	return 0;
}
