#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll k,c,s; cin>>k>>c>>s;
		ll have = c*s;
		if (have<k) {
			cout << "Case #" << casenum << ": " << "IMPOSSIBLE" << endl;	
		}
		else {
			cout << "Case #" << casenum << ":";
			for (ll t=0;t<k;t+=c) {
				ll ans=0;
				for (ll x=t;x<min(k,t+c);x++) {
					ans*=k;
					ans+=x;
				}
				cout<< " " << ans+1;
			}
			cout<<endl;
		}
	}
}
