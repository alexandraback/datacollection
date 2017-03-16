#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int T;scanf("%d",&T);
	for(int tc=1;tc<=T;tc++){
		int R,C,W; scanf("%d%d%d",&R,&C,&W);
		static int dp[1<<20]; // length, mask possible -> cost
		dp[0]=-1e9;
		for(int msk=1;msk<(1<<(C-W+1));msk++){
			if(__builtin_popcount(msk)==1)dp[msk]=W;else{
				dp[msk]=1e9;
				for(int i=0;i<C;i++){
					int msk1=msk,msk2=msk;
					for(int j=0;j<C;j++){
						if(j+W-1>=i && j<=i)msk1&=~(1<<j);else msk2&=~(1<<j);
					}
					dp[msk]=min(dp[msk],max(1+dp[msk1],dp[msk2]));
				}
			}
		}
		printf("Case #%d: %d\n",tc,dp[(1<<(C-W+1))-1]+(R-1)*(C/W));
	}
}
