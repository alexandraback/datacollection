#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>
typedef long long lnt;
int main(){
	lnt t=0,T,k,i,n,c,s,ans,cnt,g;
	freopen("D-large.in","r",stdin);
	freopen("pDout.txt","w",stdout);
	scanf("%lld",&T);
	while(T--){
		t++;
		scanf("%lld%lld%lld",&n,&c,&s);
		printf("Case #%lld: ",t);
		if(c*s<n){
			puts("IMPOSSIBLE");
			continue;
		}
		ans=0;cnt=0;g=1;
		for(k=1;k<=n;k++){
			 ans+=g*(k-1);
			 cnt++;
			 g*=n;
			 if(cnt==c||k==n){
			 	printf("%lld ",ans+1);
			 	cnt=0;ans=0;g=1;
			 	continue;
			 }
		}
		puts("");	 	
	}
}
