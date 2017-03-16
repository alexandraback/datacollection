#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;++z){
		ll n,x;
		scanf("%lld",&n);
		printf("Case #%d: ",z);
		if(n==0) {printf("INSOMNIA\n");continue;}
		int msk=0;
		x=0;
		while(true){
			x+=n;
			ll t=x;
			while(t){
				msk|=(1<<(t%10));
				t/=10;
			}
			if(msk==(1<<10)-1) break;
		}
		printf("%lld\n",x);
	}
}