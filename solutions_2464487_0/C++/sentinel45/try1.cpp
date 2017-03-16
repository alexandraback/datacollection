#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
ll r,t;
ll HALF = (ll)1e9;
ll lIM=(ll)1e18;
int ok(ll k){
	ll num = 2*r+2*k-1;
	if((double)t/k >= num) return 1;	
	else return 0;
}
int main(){
	freopen("F:\\input.in","r",stdin);
	freopen("F:\\output.txt","w",stdout);
	//cout<<"ready";
	int T;
	scanf("%d",&T);
	for(int I=1;I<=T;I++) {		
		cin>>r>>t;
		ll lo = 1, hi = (ll)1e18;
		ll ans = lo;
		while(lo <= hi){
			ll mid = lo + hi >> 1;
			if(ok(mid)) {
				ans = mid;
				lo = mid + 1;
			} 
			else hi = mid - 1;
		}
		printf("Case #%d: %lld\n",I,ans);
	}
	return 0;
}
