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

int n, m, b;
int n0, m0, sw;
char a[60][60];

void doswapnm() {
	swap(n, m);
	swap(n0, m0);
	sw ^= 1;
	forn(i, max(n0, m0))
		forn(j, max(n0, m0))
			if (i < j) {
				swap(a[i][j], a[j][i]);	
			}
}

void answer(bool success) {
	if (!success) {
		cout << "Impossible" << endl;
		return;
	}
	if (sw == 1) {
		doswapnm();
	}
	forn(i, n0) {
		forn(j, m0) {
			printf("%c", a[i][j]);
		}
		cout << endl;
	}
	return;
}

void go() {
	if (n > m) {
		doswapnm();
	}
	if (n * m == b + 1) {
		forn(i, n) 
			forn(j, m)
				a[i][j] = '*';
		a[0][0] = 'c';
		answer(true);
		return;
	}
	if (n == 1) {
		if (b == 0) {
			a[0][0] = 'c';
			answer(true);
			return;
		}
		a[0][m-1] = '*';
		m--;
		b--;
		go();
		return;
	}
	if (n == 2) {
		if (b == 0) {
			a[0][0] = 'c';
			answer(true);
			return;
		}
		if (b & 1) {
			answer(false);
			return;
		}
		if (b + 2 == n * m) {
			answer(false);
			return;
		}
		a[0][m-1] = a[1][m-1] = '*';
		m--;
		b -= 2;
		go();
		return;
	}
	if (b >= n) {
		forn(i, n)
			a[i][m-1] = '*';
		b -= n;
		m--;
		go();
		return;
	}
	if (b < n) {
		a[0][0] = 'c';
		for (int i = n - 1; i >= 2; i--) {
			if (b > 0) {
				a[i][m-1] = '*';
				b--;
			}
		}
		if (b == 1) {
			if (m == 3) {
				answer(false);
				return;
			}
			a[n-1][m-2] = '*';
		}
		answer(true);
		return;
	}
}

void solve() {
	cin >> n >> m >> b;
	//cout << n << " " << m << " " << b << endl;
	seta(a, '.');
	n0 = n;
	m0 = m;
	sw = 0;
	go();		
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d:\n", ii + 1);
		solve();
	}	
	return 0;
}
