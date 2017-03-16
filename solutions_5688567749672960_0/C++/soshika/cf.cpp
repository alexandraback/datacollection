
#include <bits/stdc++.h>

using namespace std;

#define fer(i, s, e) for(int i = (s) ; i < (e) ; ++i)
#define rep(i, n)  fer(i, 0, n)
#define clr(a, val)  memset(a, val, sizeof a)

#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define pb  push_back
#define fx(x) fixed << setprecision(x)
#define mkp	make_pair

#define fi first
#define se second

typedef long long ll ;

const int MAX = 1000001;

ll dep[MAX], n ;
set < pair<int,ll> > q;

ll toInt(string x) {
	ll ret=0;
	rep(i, sz(x)) ret=ret*10+(x[i]-48);
	return ret;
}

string toStr(ll x) {
	string ret; 
	while(x) {
		ret.push_back(x % 10 + 48) ;
		x /= 10;
	}
	while(ret[sz(ret)-1] == '0') ret.erase(ret.end()-1);
	return ret;
}

int dijkstra(ll s,ll e) {
		q.insert(mkp(1, s));
		dep[s] = 1;
		while(!q.empty()) {
			s = q.begin()->second ;
			q.erase(q.begin());
			if(s == e) return dep[s];

			if(dep[s] + 1 < dep[s+1]) {
				dep[s+1] = dep[s] + 1;
				if(s+1ll == e) return dep[s+1ll];
				q.insert(mkp(dep[s+1], s+1));
			}
			ll tmp = toInt(toStr(s));
			if(tmp > n) continue;
			if(dep[s] + 1 < dep[tmp]) {
				dep[tmp] = dep[s] + 1;
				if(tmp == e) return dep[tmp];
				q.insert(mkp(dep[tmp], tmp));
			}
		}
}

int main() {
	int t, __case=1;
	cin >> t;
	while(t--) {
		cin >> n;
		rep(i, MAX) dep[i] = (1ll << 40);
		printf("Case #%d: %d\n",__case++, dijkstra(1ll,n));
		q.clear() ;
	}
	return 0;
}