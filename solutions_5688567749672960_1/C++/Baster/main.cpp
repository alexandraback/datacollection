#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

typedef pair<ld, ld> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

li n;

bool read() {
	cin >> n;
    return true;
}

map<li, int> dp;

const int N = 1000 * 1000 + 500;
int ans[N];

li rev(li x) {
	
	if (x == 0)
		return 0;

	vector<int> v;
	while(x) {
		v.pb(x % 10);
		x /= 10;
	}
	
	forn (i, v.size()) {
		x *= 10;
		x += v[i];
	}
	return x;
}

int len(li x) {
	int res = 0;
	while(x) {
		res++;
		x /= 10;
	}
	return res;
}

int zc(li x) {
	return (len(x) - 1) / 2;
}

li d10[25];

li gr(li x) {
	if (x == 0)
		return 0;
	int cur = zc(x);
	li nt = x / d10[cur + 1];
	nt *= d10[cur + 1];
	nt++;
	if (nt > x) {
		nt -= d10[cur + 1];
		if (len(nt) < len(nt + d10[cur + 1]))
			nt = x + 1;
	}
	li to = rev(nt);
	if (to != nt && nt <= x) {
		return gr(to) + x - nt + 1;
	} else {
		int l = len(x);
		to = 0;
		forn (i, l - 1)
			to *= 10, to += 9;
		return gr(to) + x - to;
	}
}

void solve() {
	
	d10[0] = 1;
	forn (i, 20)
		d10[i + 1] = d10[i] * 10;

	cout << gr(n) << endl;

 }

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	

	int tc;
	cin >> tc;

	forn (i, tc) {
		read();
		cout << "Case #" << i + 1 << ": ";
        solve();
	}
    
    return 0;
}