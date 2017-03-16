#include<stdio.h>
int tcn,tc;
unsigned long long int r,t;
unsigned long long int ans;
unsigned long long int npnt(){
	unsigned long long ret;
	ret=(r*2+1)*ans+ans*(ans-1)*2;
	if(ret%1000000007!=((r*2+ans*2-1)%1000000007*(ans%1000000007))%1000000007)return t+1;
	return ret;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%llu%llu",&r,&t);
		ans=0;
		for(i=0;npnt()<=t;i++)ans=(1LL<<i);
		i--;
		for(;i>=0;i--){
			ans-=(1LL<<i);
			if(npnt()<=t)ans+=(1LL<<i);
		}
		ans+=3;
		if(npnt()>t)ans--;
		if(npnt()>t)ans--;
		if(npnt()>t)ans--;
		if(npnt()>t)ans--;
		if(npnt()>t)ans--;
		if(npnt()>t)ans--;
		printf("Case #%d: %llu\n",tc,ans);
	}
}