#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef long long ll;

bool can(ll ce, vector<ll>& p, int n, int i, ll x, ll e, ll r)
{
	if(x > ce) return false;
	ce -= x;
	ce = min(e, ce + r);
	FORN(j, i + 1, n){
		if(ce == e) break;
		if(ce < p[j]) return false;
		ce = min(e, ce - p[j] + r);
	}
	return true;
}

ll maxput(ll ce, vector<ll>& p, int n, int i, ll e, ll r)
{
	ll ub = ce;
	ll lb = 0;
	while(lb < ub){
		ll m = (ub - lb + 1) / 2 + lb;
		if(can(ce, p, n, i, m, e, r)){
			lb = m;
		}else{
			ub = m - 1;
		}
	}
	return lb;
}
int main(){
	ios::sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	FORN(tc, 0, ntc){
		ll e, r;
		int n;
		cin >> e >> r >> n;
		vector<ll> v(n);
		FORN(i, 0, n) cin >> v[i];
		vector<ll> p(n);
		vector<ll> vds(n);
		FORN(i, 0, n) vds[i] = v[i];
		sort(ALL(vds));
		vds.resize(unique(ALL(vds)) - vds.begin());
		int nd = vds.size();
		reverse(ALL(vds));
		FORN(id, 0, nd){
			ll ce = e;
			FORN(i, 0, n){
				if(v[i] == vds[id]){
					p[i] = maxput(ce, p, n, i, e, r);
				}
				ce = min(e, ce - p[i] + r);
			}
		}

		ll sol = 0;
		FORN(i, 0, n) sol += v[i] * p[i];
		cout << "Case #" << (tc + 1) << ": " << sol << endl;

	}
}
