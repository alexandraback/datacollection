// lamphanviet@gmail.com
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uiint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 5111222333444555666LL
#define EPS 1e-7
#define MAX 100111
#define MOD 1000000007

int n;
string a, b;
int64 minDiff, minA, minB;

void rec(int i, int64 diff, int64 da, int64 db, int64 mul) {
	//cout << i << ": " << diff << " " << da << " " << db << " " << mul << endl;
	if (i >= n) {
		diff = abs(diff);
		if (diff < minDiff) {
			minDiff = diff;
			minA = da; minB = db;
		} else if (diff == minDiff) {
			if (da < minA) {
				minA = da; minB = db;
			} else if (da == minA) {
				if (db < minB) minB = db;
			}
		}
		return;
	}

	if (a[i] != '?' && b[i] != '?') {
		int64 aa = mul * (a[i] - '0');
		int64 bb = mul * (b[i] - '0');
		int64 dd = diff + (aa - bb);

		rec(i + 1, dd, da + aa, db + bb, mul / 10);
		return;
	}

	rep(x, 10) rep(y, 10) {
		if (a[i] != '?' && x != a[i] - '0') continue;
		if (b[i] != '?' && y != b[i] - '0') continue;

		int64 aa = mul * x;
		int64 bb = mul * y;
		int64 dd = diff + (aa - bb);

		rec(i + 1, dd, da + aa, db + bb, mul / 10);
	}
}

void print(int64 x) {
	int cnt = 0;
	int64 y = x;
	do {
		y /= 10;
		cnt++;
	} while (y > 0);
	while (cnt++ < n) putchar('0');
	cout << x;
}

void solve() {
	n = a.length();
	int64 mul = 1;
	rep(i, n - 1) mul *= 10;
	minDiff = minA = minB = INF;

	rec(0, 0, 0, 0, mul);

	print(minA);
	putchar(' ');
	print(minB);
}

int main() {
	//ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("bsmall.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		cin >> a >> b;
		printf("Case #%d: ", ++caseNo);
		solve();
		puts("");
	}
	return 0;
}

