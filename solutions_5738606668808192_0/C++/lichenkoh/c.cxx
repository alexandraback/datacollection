#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
ll fac[1000];
ll a[1000];
int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n,k;
		cin>>n>>k;
		cout<<"Case #1:"<<endl;
		n/=2;
		for (ll x=2;x<=10;x++) {
			ll f=1;
			for (ll i=0;i<n;i++) {
				f*=x;
			}
			f++;
			fac[x]=f;
		}
		for (ll z=0;z<k;z++) {
			a[0]=1; a[n-1]=1;
			for (ll i=0;i<n-2;i++) {
				if(z&(1ULL<<i)) {
					a[i+1]=1;
				}
				else a[i+1]=0;
			}
			for (ll t=0;t<2;t++) {
				for (ll i=n-1;i>=0;i--) {
					cout<<a[i];
				}
			}
			for (ll x=2;x<=10;x++) {
				cout << " " << fac[x];
			}
			cout<<endl;
		}
	}
}
