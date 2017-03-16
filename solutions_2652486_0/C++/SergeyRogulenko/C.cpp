#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
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

const int NMAX = 20;
const int MMAX = 30;

int n, m, k, r, N;
map<int64, int> M;
vector<string> a;
bitset<MMAX> g[NMAX];
bitset<NMAX> u;

string t;

void go(int v, int l, int64 cur) {
	if (l > m) return;
	if (v == n) {
		a.pb(t);
		return;
	}
	go(v, l+1, cur);
	t += (char)(l + '0');
	go(v+1, l, cur * l);	
	t.erase(t.length()-1);
}

void solve_case() {
	u.reset();
	forn(i, NMAX)
		u[i] = 1;
	forn(i, k) {
		int64 x;
		cin >> x;
		int v = M[x];
		forn(j, NMAX)
			if (!g[j][v]) 
				u[j] = 0;
	}	
	vector<string> ans;
	forn(i, NMAX)
		if (u[i])	
			ans.pb(a[i]);
	random_shuffle(all(ans));
	cout << ans[0] << endl;
}

void solve() {
	cin >> r >> n >> m >> k;
	M.clear();
	t = "";
	forn(i, NMAX)
		g[i].reset();
	go(0, 2, 1LL);
	N = 0;
	forn(i, a.size()) {
		forn(j, 1 << n) {
			int64 cur = 1;
			forn(k, n)
				if (j & (1 << k))
					cur = cur * (a[i][k] - '0');		
			if (!M.count(cur)) {
				M[cur] = N;
				N++;
			}
			int v = M[cur];
			g[i][v] = 1;
		}
	}
	cerr << a.size() << " " << M.size() << endl;
	forn(i, r)
		solve_case();	
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d:\n", ii+1);
		solve();
	}
	return 0;
}
