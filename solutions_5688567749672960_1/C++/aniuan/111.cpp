#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll rev(ll x){
	ll ret=0;
	for(;x;x/=10) ret=ret*10+x%10;
	return ret;
}
const int maxN=1e6+10;
ll f[maxN];
int main(){
	int T,kase,i,t,n;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	for(i=0;i<=20;i++) f[i]=i;
	for(;i<maxN;i++){
		f[i]=f[i-1]+1;
		if(i%10!=0&&(t=rev(i))<i)
			if(f[t]+1<f[i]) f[i]=f[t]+1;
	}
//	for(i=1;i<=maxN;i=i*10) cout<<i<<'\t'<<f[i]<<endl;
	scanf("%d",&T);
	for(kase=1;kase<=T;kase++){
		scanf("%d",&n);
		printf("Case #%d: %d\n",kase,f[n]);
	}
	return 0;
}
