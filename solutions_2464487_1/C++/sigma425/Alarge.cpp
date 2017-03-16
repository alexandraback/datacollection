#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin >> n;
	for(ll i=1;i<=n;i++){
		ll r,t;
		cin >> r >> t;
		double lt;
		lt=log(t);
		ll lb=1,ub=10000000000;
		while(ub-lb>16){
			ll mid=(ub+lb)/2;
			if(log(2*r+2*mid-1)+log(mid)<=lt){
				lb=mid;
			}else{
				ub=mid;
			}
		}
		ll fuga=1;
		ll hoge=max(fuga,lb-16);
		for(ll d=hoge;d<ub+16;d++){
			if((2*r+2*d-1)*d>t){
				cout << "Case #" << i << ": " << d-1 << endl;
				break;
			}
		}
	}
	return 0;
}