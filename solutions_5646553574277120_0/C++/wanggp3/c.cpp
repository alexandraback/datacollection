#include <bits/stdc++.h>
using namespace std;
int C,D,V;
bool dp[35][35];
int have[35];
bool ok(int v){
	memset(dp,0,sizeof dp);
	int n=v-1;
	int m = v;
	for(int i=0;i<=n;i++)dp[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j =1;j<=m;j++){
			if(!have[i])dp[i][j] = dp[i-1][j];
			else{
				dp[i][j] = dp[i-1][j] ;
				if(j>=i)dp[i][j] = dp[i][j] | dp[i-1][j-i];
			}
		}
	}
	return dp[n][m];
}
void solve(){
	scanf("%d%d%d",&C,&D,&V);
	memset(have,0,sizeof have);
	for(int i=0;i<D;i++){
		int x;
		scanf("%d",&x);
		have[x]=1;
	}
	int ans=0;
	for(int i=1;i<=V;i++){
		if(have[i]==0 && !ok(i)){
			//cout<<"need "<<i<<endl;
			have[i]=1;
			ans++;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		printf("Case #%d: ",cas+1);
		solve();
	}
	return 0;
}
