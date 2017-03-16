// http://gmplib.org/
#include <gmpxx.h>
#include <iostream>
#include <cmath>
using namespace std;
//typedef long long ll;
typedef mpz_class ll;
ll f(ll r, ll n) {
	return 2*r*n + 2*n*(n-1) + n;
}
int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		ll r,t;
		cin>>r>>t;
		ll low=0, hi=1e17;
		while(hi-low>1) {
			ll mid = (low+hi)/2;
			if (f(r, mid) > t) {
				hi = mid;
			} else {
				low = mid;
			}
		}
//		cout<<f(r,low)<<' '<<f(r,hi)<<'\n';
		cout<<"Case #"<<a<<": "<<low<<'\n';
	}
}
