#include<iostream>
#include<cstdio>

using namespace std;

int T,n,c,s,tmp;
long long ans;

int main(){
	freopen("fractile.in","r",stdin);
	freopen("fractile.out","w",stdout);
	
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d%d",&n,&c,&s);
		if ((n-c+1)>s) printf("Case #%d: IMPOSSIBLE\n",i);
		else {
			if (c>=n) c=n;
			printf("Case #%d:",i);
			for(int j=c+1;j<=n;j++) printf(" %d",j);
			ans=2;
			for(int j=3;j<=c;j++) ans=(ans-1)*n+j;
			if (c>1){
				printf(" %lld\n",ans);
			}	
			else printf(" 1\n");
		}
	}
	
	return 0;
}
