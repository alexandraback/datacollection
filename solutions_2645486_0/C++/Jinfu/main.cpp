#include "stdio.h"
#include "string.h"
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dp[20][20];
int value[20];
void Process(){
}
void Solve(){
	memset(dp,0,sizeof(dp));
	memset(value,0,sizeof(value));
	int E,R,N;
	scanf("%d %d %d",&E,&R,&N);
	int ans=-1;
	for(int i=0;i<N;i++) scanf("%d",&value[i]);
	for(int i=1;i<=N;i++){
		for(int j=0;j<=E;j++){
			for(int k=max(0,j-R);k<=E;k++){
				dp[i][j]=max(dp[i][j],dp[i-1][k]+(min(k+R,E)-j)*value[i-1]);
				ans=max(ans,dp[i][j]);
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("D:\\Test\\in.txt","r",stdin);
	freopen("D:\\Test\\out.txt","w",stdout);
	Process();
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){			
		printf("Case #%d: ",t);
		Solve();
	}
    return 0;
}