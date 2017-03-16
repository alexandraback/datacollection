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

int n;
int a[1050], b[1050];

int read() {
	double x;
	scanf("%lf", &x);
	return (int)(x * 1e5 + 0.5);
}

int calc1() {
	int l1, r1, l2, r2;
	l1 = l2 = 0;
	r1 = r2 = n - 1;
	int res = 0;
	while (l1 <= r1) {
		if (a[l1] < b[l2]) {
			l1 ++;
			r2 --;
		} else {
			l1 ++;
			l2 ++;
			res ++;
		}
	}
	return res;
}

int calc2() {
	int l1, r1, l2, r2;
	l1 = l2 = 0;
	r1 = r2 = n - 1;
	int res = n;
	while (l1 <= r1 && l2 <= r2) {
		if (a[l1] < b[l2]) {
			l1 ++;
			l2 ++;
			res --;
		} else {
			l2 ++;
		}
	}
	return res;
}

void solve() {
	cin >> n;
	forn(i, n) {
		a[i] = read();
	}
	forn(i, n) {
		b[i] = read();
	}
	sort(a, a + n);
	sort(b, b + n);
	cout << calc1() << " " << calc2() << endl;
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
