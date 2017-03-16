#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

ll r, t;
ld r1, t1;

bool test (ll m) {
	ld m1 = m;
	ll s = m * (r * 2 + m * 2 - 1);
	ld s1 = m1 * (r1 * 2 + m1 * 2 - 1);
	if (s1 > t1 * 1.1l) {
		return 0;
	}
	if (s > t) {
		return 0;
	}
	return 1;
}

void solve () {
	cin >> r >> t;
	r1 = r;
	t1 = t;
	ll lb = 0, rb = ll(1e15l);
	while (lb < rb) {
		ll m = (lb + rb + 1) / 2;
		if (test(m)) {
			lb = m;
		} else {
			rb = m - 1;
		}
	}
	cout << lb << endl;
}

int main () {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);	
	int t;
	cin >> t;
	forn (i, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}
