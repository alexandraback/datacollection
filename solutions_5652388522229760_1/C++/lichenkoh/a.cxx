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
		time_t start = clock();
		bool h[20];
		for (ll d=0;d<10;d++) h[d]=false;
		ll n; cin>>n;
		ll left=10;
		ll ans=-1;
		for (ll i=1;;i++) {
			if (i%100==0) {
				if (((clock()-start)/CLOCKS_PER_SEC) > 5.8) break;
			}
			ll x=n*i;
			if (x<0) break;
			string s=to_string(x);
			ll slen=s.length();
			for (ll j=0;j<slen;j++) {
				ll d=s[j]-'0';
				if (!h[d]) {
					h[d]=true;
					left--;
				}
			}
			if (left==0) {
				ans=x;
				break;
			}
		}
		if (ans==-1) {
			cout << "Case #" << casenum << ": " << "INSOMNIA" << endl;
		}
		else cout << "Case #" << casenum << ": " << ans << endl;
	}
}
