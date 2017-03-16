/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<iostream>
using namespace std;

typedef __int64 ll;

ll a[110],b[110];
int A[110],B[110];
ll dp[110][110];
int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	int T,n,m,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%I64d%d",&a[i],&A[i]);
		for(int i=0;i<m;i++)
			scanf("%I64d%d",&b[i],&B[i]);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				//printf("%d %d\n",i,j);
				if(A[i]==B[j])
					dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+min(a[i],b[j]));
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);

				dp[i][j+1]=max(dp[i][j+1],dp[i][j]);

			}
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans=max(dp[i][j],ans);
		for(int j=0;j<m;j++)
			dp[n][j+1]=max(dp[n][j+1],dp[n][j]);
		printf("Case #%d: %I64d\n",ri++,ans);

	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<iostream>
using namespace std;

typedef __int64 ll;

ll a[110],b[110];
int A[110],B[110];
int n,m;
ll dfs(int si,ll k1,int sj,ll k2)
{
	if(si>=n||sj>=m)
		return 0;
	if(A[si]==B[sj]){
		if(k1>=k2){
			ll ans=0;
			ans=max(ans,k2+dfs(si,k1-k2,sj+1,b[sj+1]));
			ans=max(ans,k2+dfs(si+1,a[si+1],sj+1,b[sj+1]));
			return ans;
		}
		else{
			ll ans=0;
			ans=max(ans,k1+dfs(si+1,a[si+1],sj,k2-k1));
			ans=max(ans,k1+dfs(si+1,a[si+1],sj+1,b[sj+1]));
			return ans;
		}

	}
	ll ans=dfs(si,k1,sj+1,b[sj+1]);
	ans=max(ans,dfs(si+1,a[si+1],sj,k2));
	return ans;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%I64d%d",&a[i],&A[i]);
		for(int i=0;i<m;i++)
			scanf("%I64d%d",&b[i],&B[i]);
		ll ans=dfs(0,a[0],0,b[0]);
		printf("Case #%d: %I64d\n",ri++,ans);

	}
	return 0;
}

