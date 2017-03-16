#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int e,r,n;
long long int dp[11][6];
int v[11];
void update(long long int&x,long long int y){
	if(x==-1 || x<y)x=y;
}
int main(){
	int _,t;
	scanf("%d",&_);
	for(t=1; t<=_; t++){
		scanf("%d%d%d",&e,&r,&n);
		for(int i=0; i<n; i++)
			scanf("%d",&v[i]);
		memset(dp,-1,sizeof(dp));
		dp[0][e]=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<=e; j++)
				if(dp[i][j]!=-1)
					for(int k=0; k<=j; k++)
						update(dp[i+1][min(j-k+r,e)],dp[i][j]+k*v[i]);
		long long int res=-1;
		for(int j=0; j<=e; j++)
			update(res,dp[n][j]);
		printf("Case #%d: %d\n",t,res);
	}
	return 0;
}