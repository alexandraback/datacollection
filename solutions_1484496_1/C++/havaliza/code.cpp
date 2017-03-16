#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
#include <complex>
using namespace std;

#define double long double
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define FORE(i, a, n) for (i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
#define ll long long
#define pb push_back
#define error(x) cout << #x << " = " << (x) << endl;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define point complex<double>
//#define X real()
//#define Y imag()
#define X first
#define Y second
#define EPS 1e-12
//#define endl "\n"
#define pdd pair<double, double>
bool gt(double a, double b) { return a > b+EPS; }

const int MAXN = 512;

int n;
ll a[MAXN];
bool cur[MAXN];
map<ll, int> mp;

void init() {
	FOR(i, 0, n/2+2) cur[i] = 1;
}

void get_next() {
	for (int i = n-2; i >= 0; i--) if (cur[i] && !cur[i+1]) {
		cur[i] = 0;
		cur[i+1] = 1;
		int cnt = 0;
		FOR(j, i+2, n) if (cur[j]) cnt++, cur[j] = false;
		FOR(j, i+2, i+2+cnt) cur[j] = true;
		return;
	}
}

void print() {
	bool sp = false;
	FOR(i, 0, n) if (cur[i]) {
		if (sp) cout << " "; else sp = true;
		cout << a[i];
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	FOR(l, 1, t+1) {
		cerr << l << endl;
		cin >> n;
		FOR(i, 0, n) cin >> a[i];
		cout << "Case #" << l << ":" << endl;
		mp.clear();
		init();
		for (int mask = 0; ; mask++) {
			//FOR(i, 0, n) cout << cur[i]; cout << endl;
			ll sum = 0;
			FOR(i, 0, n) if (cur[i]) sum += a[i];
			if (mp.count(sum)) {
				init();
				int when = 0, to = mp[sum];
				while (when < to) when++, get_next();
				print();
				while (when < mask) when++, get_next();
				print();
				break;
			} else mp[sum] = mask;
			get_next();
		}
	}
	return 0;
}

