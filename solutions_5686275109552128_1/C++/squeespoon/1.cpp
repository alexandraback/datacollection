#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <queue>

using namespace std;

const int maxn = 1001;

int p[maxn];

int dp[maxn][maxn];

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	
	for(int i=2;i<maxn;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=1000;
			for(int k=1;k<i;k++){
				dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
			}
			//cout<<"dp "<<i<<" "<<j<<" = "<<dp[i][j]<<endl;
		}
		
	}
	
	
	int t;
	cin>>t;
	
	for(int cas=1;cas<=t;cas++){
		int d;
		cin>>d;
		int MAX=0;
		for(int i=1;i<=d;i++){
			scanf("%d",&p[i]);
			MAX=max(MAX,p[i]);
		}
		
		int ans=MAX;
		for(int test=1;test<=MAX;test++){
			int tmp=0;
			for(int i=1;i<=d;i++){
				tmp+=dp[p[i]][test];
			}
			tmp+=test;
			ans=min(ans,tmp);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}



