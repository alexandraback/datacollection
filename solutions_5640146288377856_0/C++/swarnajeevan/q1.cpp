#include<stdio.h>
#include<math.h>
#define ll long long

using namespace std;

int main(){
	ll tt;
	scanf("%lld",&tt);
	for(ll lv=1;lv<=tt;lv++){
		printf("Case #%lld: ",lv);
		ll r,c,w;
		scanf("%lld %lld %lld",&r,&c,&w);
		ll ans=((r*(c-1))/w)+w;
		printf("%lld\n",ans);
	}
	return 0;
}