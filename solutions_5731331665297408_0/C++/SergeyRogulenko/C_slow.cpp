#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n, m;
bool g[10][10];
string res;
bool u[10];
vector<string> cur;
vector<int> p;
string a[10];

void go(int v) {
	int V = v;
	u[v] = 1;
	cur.pb(a[v]);
	if (I cur.size() == n) {
		string t = "";
		forn(i, n)
			t += cur[i];
		if (res == "" || res > t)
			res = t;
	}
	vector<int> p1 = p;
	p.pb(v);
	while (p.size() > 0) {
		v = p.back();
		forn(i, n)
			if (g[v][i] && !u[i]) {
				go(i);
			}
		p.pop_back();		
	}
	p = p1;
	cur.pop_back();
	u[V] = 0;
}

void solve() {
	cin >> n >> m;
	seta(g, 0);
	forn(i, n)
		cin >> a[i];
	forn(i, m) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x][y] = g[y][x] = 1;
	}
	res = "";
	seta(u, 0);
	cur.clear();
	p.clear();
	forn(i, n)
		go(i);
	cout << res << endl;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn(ii, tt) {
		cerr << ii << endl;
		printf("Case #%d: ", ii + 1);
		solve();
	}	
	return 0;
}
