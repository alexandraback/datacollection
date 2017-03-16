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

bool ok(int64 x) {
	vector<int> q;
	while (x) {
		q.pb(x % 10);
		x /= 10;
	}
	forn(i, q.size())
		if (q[i] != q[q.size()-i-1])
			return 0;
	return 1;
}

int a[10005000];

void solve() {
	int64 l, r;
	cin >> l >> r;
	int64 l1 = I sqrt(l + 0.5);
	int64 r1 = I sqrt(r + 0.5);
	if (l1 * l1 < l)
		l1++;
	cout << a[r1] - a[l1-1] << endl;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta(a, 0);
	for (int64 i = 1; i <= 10000000; i++)
		if (ok(i) && ok(i * i))
			a[i] = 1;
	forn(i, 10000000)
		a[i+1] += a[i];
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d: ", ii + 1);
		solve();
	}
	cerr << clock() << endl;
	return 0;
}
