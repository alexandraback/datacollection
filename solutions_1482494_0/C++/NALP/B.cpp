#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <memory.h>

#include <iostream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define y1 YYYYYYYYYYYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Abs(x) (((x) >= 0) ? (x) : (-(x)))

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 1100;

int n, a[MAXN], b[MAXN], used[MAXN];

void read() {
	cin >> n;
	forn(i, n)
		cin >> a[i] >> b[i];
}

void solve() {
	int ans = INF;
	forn(mask, 1 << n) {
		vector<pair<int, int> > cur;
		forn(i, n) {
			cur.pb(mp(b[i], 2));
			if ((mask & (1 << i)) != 0) {
				cur.back().second = 1;
				cur.pb(mp(a[i], 1));
			}
		}

		int sum = 0;
		bool ok = true;
		sort(all(cur));
		forn(i, cur.size()) {
			if (cur[i].first > sum) ok = false;
			sum += cur[i].second;
		}

		if (ok) ans = min(ans, (int)cur.size());
	}

	if (ans == INF)
		cout << "Too Bad" << endl;
	else
		cout << ans << endl;
}

int main() {
#ifdef NALP_PROJECT
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
#endif

	cout.precision(9);
	cout.setf(ios::fixed);

	cerr.precision(3);
	cerr.setf(ios::fixed);

	int tests;
	cin >> tests;
	forn(i, tests) {
		cerr << "Test #" << i + 1 << endl;
		time_t curTime = clock();

		cout << "Case #" << i + 1 << ": ";
		read();
		solve();

		cerr << "calced : " << (clock() - curTime + 0.0) / CLOCKS_PER_SEC << endl << endl;
	}
	
	return 0;
}
