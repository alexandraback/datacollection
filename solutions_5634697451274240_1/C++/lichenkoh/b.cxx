#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll INF = 1LL<<60LL;
const ll MAXN = 1008;
ll f[MAXN],g[MAXN];
int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll x=0;x<MAXN;x++) {
		f[x]=INF;
		g[x]=INF;
	}
	f[1]=0;
	for (ll x=1;x<MAXN;x++) {
		for (ll i=0;i<4;i++) {
			chkmin(g[x],f[x-1]+1);
			chkmin(f[x],g[x-1]+1);
			chkmin(g[x],f[x]+1);
			chkmin(f[x],g[x]+1);
		}
	}
	for (ll casenum = 1; casenum <= cases; casenum++) {
		string s;
		cin >> s;
		ll n=s.length();
		ll cnt=1;
		for (ll i=1;i<n;i++) {
			if (s[i]!=s[i-1]) cnt++;
		}
		ll ans;
		if (s[0]=='+') ans=f[cnt];
		else ans=g[cnt];
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
