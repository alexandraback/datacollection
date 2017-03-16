#pragma comment (linker, "/STACK:200000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;


typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-12;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 1000;


int n, s[MAXN], sum;


void read() {
	cin >> n;
	forn(i,n)
		scanf ("%d", &s[i]);
}


bool good (int idx, double y) {
	double myval = s[idx] + y * sum;
	double sum_y = y;
	forn(i,n)
		if (i != idx) {
			double need_y = (myval - s[i]) / sum;
			if (need_y < 0)
				need_y = 0;
			sum_y += need_y;
		}
	return sum_y > 1;
}


void solve() {
	sum = 0;
	forn(i,n)
		sum += s[i];

	forn(cur,n) {
		double l = 0,
			r = 1;
		forn(it,100) {
			double mid = (l + r) / 2;
			if (good (cur, mid))
				r = mid;
			else
				l = mid;
		}

		printf (" %.10lf", (l+r)/2 * 100);
	}
	puts("");
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	
	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		printf ("Case #%d:", tt+1);
		solve();
	}

}