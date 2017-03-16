#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <utility>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define _with_file
#define TASK ""
#define forn(i, n) for(int i = 0; i < (int)n; ++i)

void quit(); 

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
#ifdef local
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair <int, int> PII;
typedef pair <i64, i64> PII64;
typedef pair <ld, ld> PLL;

const ld PI = acos(-1);
const ld EPS = 1e-10;
double __t;

bool g[64][64];

void build(int b, i64 m) {
	memset(g, 0, sizeof(g));
	for(int i = 1; i < b - 1; ++i) {
		g[0][i] = 1;	
	}
	for(int i = 1; i < b - 1; ++i) {
		for(int j = i + 1; j < b - 1; ++j) {
			g[i][j] = 1;
		}
	}
	if (m == (1ll << (b - 2))) {
		for(int i = 0; i < b - 1; ++i) {
			g[i][b - 1] = 1;
		}
		return;
	}
	for(int i = 1; i < b - 1; ++i) {
		if (m & (1ll << (i - 1)))
			g[i][b - 1] = 1;
	}
} 

i64 d[64];
bool w[64];

int B;

i64 cnt(int v) {
	if (w[v])
		return d[v];
	i64 s = 0;
	for(int i = 0; i < B; ++i) {
		if (g[i][v])
			s += cnt(i);
	}
	d[v] = s;
	w[v] = 1;
	return d[v];
}

void check(int t, int b, i64 m) {
	memset(w, 0, sizeof(w));
	memset(d, 0, sizeof(d));
	d[0] = 1;
	w[0] = 1;
	B = b;
	if (cnt(b - 1) != m) {
		cerr << t << ' ' << cnt(b - 1) << ' ' << m << endl;
	}
}

int main()
{
	#ifdef local
		__t = clock();
		#ifndef _with_files
			freopen("z.in", "rt", stdin);
			freopen("z.out", "wt", stdout);
		#endif
	#endif
	#ifdef _with_files
		freopen(TASK".in", "rt", stdin);
		freopen(TASK".out", "wt", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _T;
	cin >> _T;
	for(int _test = 1; _test <= _T; ++_test) {
		int b;
		i64 m;
		cin >> b >> m;
		cout << "Case #" << _test << ": ";
		if (m > (1ll << (b - 2))) {
			cout << "IMPOSSIBLE\n";
			continue;
		} else {
			cout << "POSSIBLE\n";
		}
		build(b, m);
		//check(_test, b, m);
		for(int i = 0; i < b; ++i) {
			cout << g[i][0];
			for(int j = 1; j < b; ++j) {
				cout << g[i][j];
			}
			cout << endl;
		}
	}
	quit();
}

void quit()
{
	#ifdef local
		cerr << "\nTOTAL TIME: "<< (clock() - __t)/1000.0 << " s\n";
	#endif
	exit(0);		
}