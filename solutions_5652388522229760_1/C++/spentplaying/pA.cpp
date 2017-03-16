#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>

int a[11];
int main(){
	int n,T,k,i,cnt,ans,tmp,t=0;
	freopen("A-large.in","r",stdin);
	freopen("pAout.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		t++;
		printf("Case #%d: ",t);
		if(n==0){
			puts("INSOMNIA");
			continue;
		}
		cnt=0;
		memset(a,0,sizeof(a));
		ans=0;
		while(cnt!=10){
			ans+=n;
			tmp=ans;
			while(tmp){
				if(a[tmp%10]==0){
					cnt++;
					a[tmp%10]=1;
				}
				tmp/=10;
			}
		}
		printf("%d\n",ans);
	}
}
