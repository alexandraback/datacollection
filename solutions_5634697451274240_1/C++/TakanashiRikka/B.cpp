#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[110][2];
const int N=100;
int solve(int k1,int k2){
	if (dp[k1][k2]!=-1) return dp[k1][k2];
	if (k1==1){
		dp[k1][k2]=(k2==0); return dp[k1][k2];
	}
	int &ans=dp[k1][k2]; ans=1e9;
	for (int i=1;i<=k1;i++){
		int a=k1,b; 
		if ((i&1)&&i!=k1) a--;
		if (i&1) b=k2^1; else b=k2;
		ans=min(ans,solve(a,b)+1);
	}
	return ans;
}
char ch[110];
void solve(){
	scanf("%s",ch+1); int n=strlen(ch+1);
	int num=1;
	for (int i=2;i<=n;i++) if (ch[i]!=ch[i-1]) num++;
	int k1=0;
	if (ch[1]=='+') k1=1; else k1=0;
	printf("%d\n",dp[num][k1]);
}
int main(){
	freopen("large.in","r",stdin);
	freopen("large.out","w",stdout);
	memset(dp,0xff,sizeof dp);
	for (int i=1;i<=N;i++) solve(i,0),solve(i,1);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ",i); solve();
	}
	return 0;
}
