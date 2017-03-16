#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

void dfs(ll i, ll C, vl &comp, vvl &adj) {
	if (comp[i] >= 0) return;
	comp[i] = C;
	for (ll j: adj[i]) dfs(j,C,comp,adj);
}

ll dfs2(ll i, vl &a, vvl &adj) {
	ll res = 0;
	for (ll j: adj[i]) if (j != a[i]) res = max(res,1+dfs2(j,a,adj));
	return res;
}

int main() {
	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {
		cout << "Case #" << tc << ": ";
		ll n; cin >> n;
		
		vl a(n), comp(n,-1);
		vvl adj(n);
		ll C = 0;
		FOR(i,0,n) cin >> a[i], a[i]--;
		FOR(i,0,n) adj[i].pb(a[i]), adj[a[i]].pb(i);
		FOR(i,0,n) if (comp[i] < 0) dfs(i,C++,comp,adj);
		
		vl indeg(n);
		FOR(i,0,n) indeg[a[i]]++;
		
		queue<ll> q;
		FOR(i,0,n) if (!indeg[i]) q.push(i);

		while (sz(q)) {
			ll i = q.front(); q.pop();
			if (!--indeg[a[i]]) q.push(a[i]);
		}
		
		vl cycsz(C);
		FOR(i,0,n) if (indeg[i]) cycsz[comp[i]]++;
		
		ll res1 = 0;
		FOR(c,0,C) if (cycsz[c] == 2) {
			FOR(i,0,n) if (comp[i] == c && indeg[i]) res1 += 1 + dfs2(i,a,adj); 
		}
		ll res2 = 0;
		FOR(i,0,C) res2 = max(res2,cycsz[i]);
		
		cout << max(res1,res2) << endl;

	}


}

