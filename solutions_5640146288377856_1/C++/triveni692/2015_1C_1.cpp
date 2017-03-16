#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,m,r,c,w,dp[21][21],arr[21];
	cin>>t;
	for(i=0;i<21;i++){
		for(j=0;j<i;j++)
			dp[i][j]=0;
		dp[i][i]=i;
	}
	for(i=1;i<21;i++){
		for(j=i+1;j<21;j++){
			for(k=0;k<j;k++)arr[k]=i+1;
			for(k=0;k<j;k++)arr[k]=max(arr[k],1+dp[i][k]+dp[i][j-(k+1)]);
			dp[i][j]=j;
			for(k=0;k<j;k++)dp[i][j]=min(dp[i][j],arr[k]);
		}
	}
	for(te=0;te<t;te++){
		cin>>r>>c>>w;
		n=((c+w-1)/w);
		m=dp[w][c]+(r-1)*n;
		cout<<"Case #"<<(te+1)<<": "<<m<<"\n";
	}
}
