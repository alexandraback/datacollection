#include <stdio.h>
#include <stdlib.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int N;
		scanf("%d",&N);
		char ss[10010];
		scanf("%s",ss);
		int sum=0;
		int ans=0;
		for(int i=0;i<=N;i++){
			if(ss[i]=='0')continue;
			if(sum<i)ans+=i-sum,sum=i;
			sum+=ss[i]-'0';
		}
		printf("Case #%d: %d\n",t,ans);
	}
}
