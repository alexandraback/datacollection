#include <stdio.h>
#include <string.h>

int dp[1005];

int main()
{
	int cas;
	int n;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("pb1.out","w",stdout);
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		int ans=0;
		int mmax;
		for(int i=0; i<n; i++){
			int p;
			scanf("%d",&p);
			if(ans<p)
				ans=p;
			dp[p]++;
		}
		mmax=ans;
		for(int i=ans-1; i>0; i--){
			int tmp=i;
			for(int j=i+1; j<=mmax; j++){
				if(dp[j]==0)
					continue;
				tmp+=(j/i-(j%i==0))*dp[j];
			}
			if(ans>tmp)
				ans=tmp;
		}
		printf("Case #%d: %d\n",T,ans);
	}
	return 0;
}
