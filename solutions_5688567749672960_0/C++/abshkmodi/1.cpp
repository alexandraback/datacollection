#include<bits/stdc++.h>

using namespace std;

int dp[1000100];

int flip(int x){
	int ans=0,i=0,a[100],n;

	while(x){
		a[i++]=x%10;
		x/=10;
	}

	n=i;

	for(i=0;i<n;i++)
		ans=ans*10+a[i];
	return ans;
}

int main(){
	
	int t,n,ans=0;

	for(int i=1;i<=20;i++)
		dp[i]=i;

	for(int i=21;i<=1000000;i++){
		if(flip(i)<i && flip(flip(i))==i && (dp[flip(i)]+1)<dp[i-1]+1)
			dp[i]=dp[flip(i)]+1;
		else
			dp[i]=dp[i-1]+1;
	}

	cin>>t;
	for(int cnt=1;cnt<=t;cnt++){
		cin>>n;

		cout<<"Case #"<<cnt<<": "<<dp[n]<<endl;
	}

	return 0;
}
