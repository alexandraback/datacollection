#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll MAXN=1000+4;
string as[MAXN],bs[MAXN];
ll a[MAXN],b[MAXN];
int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n; cin>>n;
		for (ll i=0;i<n;i++) {
			cin>>as[i]>>bs[i];
		}
		{
			set<string> sta,stb;
			for (ll i=0;i<n;i++) {
				sta.insert(as[i]);
				stb.insert(bs[i]);
			}
			map<string,ll> ma,mb;
			ll idx=0;
			for (auto &w:sta) {
				ma[w]=idx; idx++;
			}
			idx=0;
			for (auto &w:stb) {
				mb[w]=idx; idx++;
			}
			for (ll i=0;i<n;i++) {
				a[i]=ma[as[i]];
				b[i]=mb[bs[i]];
			}
		}
		ll final=0;
		ll zlim=1ULL<<n;
		for (ll z=0;z<zlim;z++) {
			ll x=0,y=0;
			for (ll i=0;i<n;i++) {
				if (z&(1ULL<<i)) {
					x|=1ULL<<a[i];
					y|=1ULL<<b[i];
				}
			}
			ll ans=0;
			for (ll i=0;i<n;i++) {
				if (!(z&(1ULL<<i))) {
					if ((x&(1ULL<<a[i]))&&(y&(1ULL<<b[i]))) {
						ans++;
					}
				}
			}
			final=max(final,ans);
		}
		cout << "Case #" << casenum << ": " << final << endl;
	}
}
