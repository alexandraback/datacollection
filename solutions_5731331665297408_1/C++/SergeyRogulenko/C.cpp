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
string a[100];
vector<int> g[100];
string res = "";
vector<int> p;
bool u[100];
bool u2[100];
int step;
int now;
bool G[100][100];
int S;

void go(int v) {
	u2[v] = 1;
	forn(i, g[v].size())
		if (!u2[g[v][i]])
			go(g[v][i]);	
}

string calc(int ind) {
	forn(i, n)
		u2[i] = u[i];
	forn(i, ind+1)
		go(p[i]);
	forn(i, n)
		if (!u2[i])
			return "z";			
	string res = "999999";
	int v = p[ind];
	forn(i, g[v].size())
		if (!u[g[v][i]])
			res = min(res, a[g[v][i]]);
	if (res == "999999") return "z";
	return res;
}

void dfs(int v) {
	if (!u[v])
		res += a[v];
	u[v] = 1;
	p.pb(v);
/*	if (now == step) {
		now = -1534634;
		if (G[v][S]) {
			dfs(S);			
			return;
		}
	}
	now++;
*/	int wv = p.size() - 1;
	string best = calc(wv);
	ford(i, p.size()) {
		string w = calc(i);
		if (w == "z") continue;
		if (w < best) {
			wv = i;
			best = w;
		}
	}
	if (best == "z") return;
	wv ++;
	while (I p.size() > wv)
		p.pop_back();
	v = p.back();
	int j = -1;
	forn(i, g[v].size())
		if (!u[g[v][i]])
			if (j == -1 || a[g[v][i]] < a[g[v][j]])
				j = i;
	v = g[v][j];
	assert(a[v] == best);
	dfs(v);
}

void solve() {
	cin >> n >> m;
	forn(i, n)
		g[i].clear();
	forn(i, n)
		cin >> a[i];
		seta(G, 0);
	forn(i, m) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		G[x][y] = G[y][x] = 1;
		g[x].pb(y);
		g[y].pb(x);
	}
	int s = 0;
	forn(i, n)
		if (a[i] < a[s])
			s = i;
	S = s;
	string ans = "";
	for (step = 0; step <= 0; step ++) {
		res = "";
		seta(u, 0);
		now = 0;
		p.clear();
		dfs(s);
		if (res < ans || ans == "")
			ans = res;
		assert(res.length() == 5 * n);
	}
	cout << ans << endl;
	assert(ans.length() == 5 * n);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d: ", ii + 1);
		solve();
	}	
	return 0;
}
