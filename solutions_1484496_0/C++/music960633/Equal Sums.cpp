#include<stdio.h>
int a[1001],p[2000001],dp[2000001];
main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	int T,n,c,all,sum,i,j,k;
	scanf("%d",&T);
	for(c=1;c<=T;c++){
		printf("Case #%d:\n",c);
		scanf("%d",&n);
		all=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			all+=a[i];
		}
		for(i=1;i<(1<<n);i++){
			sum=0;
			for(j=0;j<n;j++){
				if((i>>j)&1) sum+=a[j];
			}
			if(2*sum>all) continue;
			for(j=0;j<=sum;j++) dp[j]=0;
			dp[0]=1;
			for(j=0;j<n;j++){
				if((i>>j)&1) continue;
				for(k=sum;k>=a[j];k--){
					if(dp[k]==0&&dp[k-a[j]]==1){
						dp[k]=1;
						p[k]=k-a[j];
					}
				}
				if(dp[sum]) break;
			}
			if(dp[sum]){
				for(k=0;k<n;k++){
					if((i>>k)&1) printf("%d ",a[k]);
				}
				printf("\n");
				k=sum;
				while(k!=0){
					printf("%d ",k-p[k]);
					k=p[k];
				}
				printf("\n");
				break;
			}
		}
		if(i==(1<<n)) printf("Impossible\n");
	}
}
