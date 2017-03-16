#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int a[105],dp[10][105],mk[105],ans,t,n;
void go(int r){
	int i,j;
	if(r>=ans) return;
	for(i=0;i<=t;i++)
		if(!dp[n+r-1][i]) break;
	if(i>t){
		ans=r;
		return;
	}
	for(i=1;i<=t;i++){
		if(!mk[i]){
			mk[i]=1;
			for(j=0;j<=t;j++) 
				dp[n+r][j]=(j>=i?(dp[n+r-1][j]||dp[n+r-1][j-i]?1:0):dp[n+r-1][j]);
			go(r+1);
			mk[i]=0;
		}
	}
	return;
}
int main(){
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	int nn,r=1,f,i,j;
	scanf("%d",&nn);
	while(nn--){
		cin>>f>>n>>t;
		memset(dp,0,sizeof(dp));
		memset(mk,0,sizeof(mk));
		for(i=0;i<n;i++){
			cin>>a[i];
			mk[a[i]]=1;
		}
		dp[0][0]=dp[0][a[0]]=1;
		for(i=1;i<n;i++)
			for(j=0;j<=t;j++)
				dp[i][j]=(j>=a[i]? (dp[i-1][j]||dp[i-1][j-a[i]]?1:0) : dp[i-1][j]);
		ans=100;
		go(0);
		cout<<"Case #"<<r<<": "<<ans<<endl;
		r++;
	}
	return 0;
}
/*
2
1
8
2
9 7
*/
