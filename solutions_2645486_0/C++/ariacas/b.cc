#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
const int MAXN = 1<<16;
const int INF = 1<<30;

pair<int,int> t[4*MAXN];
 
pair<int,int> combine (pair<int,int> a, pair<int,int> b) {
	if (a.first > b.first)
		return a;
	if (b.first > a.first)
		return b;
	return make_pair (a.first, a.second);
}
 
void build (const vi & a, int v, int tl, int tr) {
	if (tl == tr)
		t[v] = make_pair (a[tl], tl);
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}
 
pair<int,int> get_max (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return make_pair (-INF, 0);
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return combine (
		get_max (v*2, tl, tm, l, min(r,tm)),
		get_max (v*2+1, tm+1, tr, max(l,tm+1), r)
	);
}
/* 
void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = make_pair (new_val, 1);
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}*/

vi v;
ll e,r;
int n;

ll f (int a, int b, ll x, ll y) {
    if (a >= b)
        return 0;
    assert(x+(b-a)*r>=y);
    pii ma = get_max(1, 0, n-1, a, b-1);
    int pos = ma.second;
    assert(v[pos] == ma.first);
//    for (int i = a; i < b; ++i)
//        assert(v[i] <= ma.first);
    ll maxe = min(e, (pos-a)*r + x);
    ll maxspent = maxe + min(0LL, (b-pos)*r - y);
    ll add1 = f(pos+1, b, maxe-maxspent+r, y);
    ll add2 = f(a, pos, x, maxe);
//    cerr << a << ' ' << b << ' ' << x << ' ' << y << endl;
//    cerr << pos << ' ' << ma.first << ' ' << maxe << ' ' << maxspent << endl;
//    cerr << add1 << ' ' << add2 << endl;
    return maxspent*ma.first + add1 + add2;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> e >> r >> n;
        v.resize(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
    	build(v, 1, 0, n-1);
        printf("Case #%d: %lld\n", test, f(0, n, e, 0));
    }
    return 0;
}
