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

typedef long long ll;
typedef long double ld;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

void solve ();

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

ll e, r, n;
ll v[10010];
ll d[10010], p[10010];

set<ll> gap;

void solve () {
	cin >> e >> r >> n;
	forn (i, n) {
		cin >> v[i + 1];
	}
	gap.clear();
	gap.insert(0);
	gap.insert(n + 1);
	d[0] = p[0] = e;
	d[n + 1] = p[n + 1] = 0;
	vector<pair<ll, ll> > v1;
	forn (i, n) {
		v1.pb(mp(v[i + 1], i + 1));
	}
	sort(all(v1));
	ll ans = 0;
	ford (i, n) {
		ll x = v1[i].sc;
		ll y = *(--gap.upper_bound(x));
		ll z = *(gap.upper_bound(x));
		d[x] = min(p[y] + (x - y) * r, e);
		p[x] = max(d[z] - (z - x) * r, 0ll);
		ans += (d[x] - p[x]) * v1[i].fs;
		gap.insert(x);
	}
	cout << ans << endl;
}
