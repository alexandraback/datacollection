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

const int MAXN = 110;

int n, s, p, a[MAXN], d[MAXN][MAXN];

void read() {
	cin >> n >> s >> p;
	forn(i, n)
		cin >> a[i];
}

int suprise(int a, int b, int c) {
	if (c - a > 2) return -1;
	if (c - a == 2) return 1;
	return 0;
}

int solve(int v, int s) {
	if (v == n && s == 0) return 0;
	if (v == n || s < 0) return -INF;

	int &ans = d[v][s];
	if (ans != -1) return ans;

	ans = -INF;
	for(int s3 = 0; s3 <= a[v]; s3++)
		for(int s2 = 0; s2 <= min(s3, a[v] - s3); s2++) {
			int s1 = a[v] - s2 - s3;
			if (s1 > s2) continue;

			int cost = 0, sup = suprise(s1, s2, s3);
			if (s3 >= p) cost++;

			if (sup != -1) ans = max(ans, solve(v + 1, s - sup) + cost);
		}

	return ans;
}

void solve() {
	memset(d, 255, sizeof d);
	cout << solve(0, s) << endl;
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
