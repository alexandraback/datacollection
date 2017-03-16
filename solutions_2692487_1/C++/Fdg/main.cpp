#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;

int arr[102];
int dp[2][1000002];

void update(int & res,int v) {
	res=res==-1 ? v : min(v,res);
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;++test) {
		printf("Case #%d: ",test);
		int a,n=1;
		scanf("%d%d",&a,&n);
		for(int i=0;i<n;++i)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		int last=arr[n-1]+1;
		memset(dp,-1,sizeof(dp));
		a=min(a,last); dp[0][a]=0;
		int cur=0,next=1;
		for(int i=0;i<n;++i) {
			for(int j=0;j<=last;++j)
				if (dp[cur][j]!=-1) {
					update(dp[next][j],dp[cur][j]+1);
					update(dp[cur][min(j+j-1,last)],dp[cur][j]+1);
					if (arr[i]<j) update(dp[next][min(j+arr[i],last)],dp[cur][j]);
				}
			cur^=1,next^=1;
			memset(dp[next],-1,sizeof(dp[next]));
		}
		int ans=-1;
		for(int j=0;j<=last;++j)
			if (dp[cur][j]!=-1) update(ans,dp[cur][j]);
		printf("%d",ans);
		printf("\n");
	}
	return 0;
}