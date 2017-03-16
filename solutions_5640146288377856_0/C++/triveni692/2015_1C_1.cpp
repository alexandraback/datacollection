#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,r,c,w,dp[11][11],arr[11];
	cin>>t;
	for(i=0;i<11;i++){
		for(j=0;j<i;j++)
			dp[i][j]=0;
		dp[i][i]=i;
	}
	for(i=1;i<11;i++){
		for(j=i+1;j<11;j++){
			for(k=0;k<j;k++)arr[k]=i+1;
			for(k=0;k<j;k++)arr[k]=max(arr[k],1+dp[i][k]+dp[i][j-(k+1)]);
			dp[i][j]=j;
			for(k=0;k<j;k++)dp[i][j]=min(dp[i][j],arr[k]);
		}
	}
	for(te=0;te<t;te++){
		cin>>r>>c>>w;
		m=dp[w][c];
		if(w==c)m=w;
		cout<<"Case #"<<(te+1)<<": "<<m<<"\n";
	}
}
