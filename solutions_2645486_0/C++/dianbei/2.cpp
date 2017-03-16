#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

typedef long long ll;
const int inf=1<<29;

int a[15];
int dp[12][6];
int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
    int T,E,r,n,ri=1;
    scanf("%d",&T);
    while(T--) {
    	scanf("%d%d%d",&E,&r,&n);
    	for(int i=0;i<n;i++)
    		scanf("%d",&a[i]);
    	for(int i=0;i<=n;i++)
    		fill(dp[i],dp[i]+E+1,-inf);
    	dp[0][E]=0;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<=E;j++){
    			if(dp[i][j]==-inf) continue;
    			for(int k=0;k<=j;k++){
    				dp[i+1][min(j-k+r,E)]=max(dp[i+1][min(j-k+r,E)],dp[i][j]+a[i]*k);
    				//printf("%d %d %d\n",i,a[i],k);
    			}
    		}
    	}
    	int ans=0;
    	for(int i=0;i<=E;i++)
    		ans=max(ans,dp[n][i]);
    	printf("Case #%d: %d\n",ri++,ans);
    }
    return 0;
}
