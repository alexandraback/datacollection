/*
*	By manrajsingh
*	Do not copy -_-
*	Question:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x)
#define debug(x){cout<<#x<<" = "<<x<< endl;}
//int read_i(){char c=gc();while(c<'0' || c>'9'){c = gc();}int ret = 0;while(c>='0' && c<='9'){ret=10*ret+c-48;c=gc();}return ret;}

int dp[1000005] = {0};

int rev(int n){
	int num = 0;
	while(n){
		num=num*10+n%10;
		n=n/10;
	}
	return num;
}

int main(){
	int t;
	int n;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<11;i++){
		dp[i]=dp[i-1]+1;
	}
	for(int i=11;i<=1000000;i++){
		int r=rev(i);
		if((r!=i)&&(dp[r]!=-1)&&(i%10!=0)){
			dp[i]=min(dp[i-1]+1,dp[r]+1);
		}
		else{
			dp[i]=dp[i-1]+1;
		}
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		printf("Case #%d: %d\n",i,dp[n]);
	}
	return 0;
}
