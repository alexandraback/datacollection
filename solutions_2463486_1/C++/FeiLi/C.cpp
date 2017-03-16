#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,cas=0,flag;
typedef long long LL;
LL A,B,C,D,ans;
char c[18],d[18];
inline void solve(){
	ans=0;
	for(int j=1;j<=9999;++j){
		sprintf(c,"%d",j);
		int len=strlen(c);
		for(int i=0;i<len-1;++i)
			c[len*2-2-i]=c[i];
		C=0;
		for(int i=0;i<len*2-1;++i)
			C=C*10+c[i]-'0';
		D=C*C;
		sprintf(d,"%lld",D);flag=1;
		for(int i=0;i<((strlen(d)>>1));++i)
			if(d[i]!=d[strlen(d)-i-1]){flag=0;break;}
		if(flag&&D>=A&&D<=B) ans++;
		for(int i=0;i<len;++i)
			c[len*2-1-i]=c[i];
		C=0;
		for(int i=0;i<len*2;++i)
			C=C*10+c[i]-'0';
		D=C*C;
		sprintf(d,"%lld",D);flag=1;
		for(int i=0;i<((strlen(d)>>1));++i)
			if(d[i]!=d[strlen(d)-i-1]){flag=0;break;}
		if(flag&&D>=A&&D<=B) ans++;
	}
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		printf("Case #%d: ",++cas);
		scanf("%lld%lld",&A,&B);
		solve();
		printf("%lld\n",ans);
	}
	return 0;
}
