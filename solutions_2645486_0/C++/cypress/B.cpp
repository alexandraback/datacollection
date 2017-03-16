#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int oo=1000000000;

int E,R,N;

int dp[15][10];
int v[15];

void solve(){
	memset(dp,0,sizeof(dp));
	scanf("%d%d%d",&E,&R,&N);
	if (R>E) R=E;
	for (int i=1;i<=N;i++) scanf("%d",&v[i]);
	for (int i=0;i<E;i++) dp[0][i]=-oo;
	dp[0][E]=0;
	for (int i=1;i<=N;i++)
		for (int j=R;j<=E;j++) {
			dp[i][j]=0;
			for (int k=j-R;k<=E;k++) {
				int tmp=k-(j-R);
				if (tmp<0) continue;
				dp[i][j]=max(dp[i][j],dp[i-1][k]+v[i]*tmp);
			}
		}
	int ans=0;
	for (int i=R;i<=E;i++) ans=max(ans,dp[N][i]);
	cout<<ans<<"\n";
}

int main(){
	
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for (int cs=1;cs<=T;cs++) {
		cout<<"Case #"<<cs<<": ";
		solve();
	} 
	
	
	return 0;
}
