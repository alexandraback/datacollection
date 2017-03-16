#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define MAX 1000005

string s;
lld dp[MAX][2];

lld cnt(int i,int j)
{
	if(i<0)return 0;
	
	if(dp[i][j]!=-1)return dp[i][j];
	
	if(j==0){
		if(s[i]=='+')
			dp[i][j] = min(cnt(i-1,j),cnt(i-1,j^1)+2);
		else
			dp[i][j] = cnt(i-1,j^1)+1;
	}
	else
	{
		if(s[i]=='-')
			dp[i][j] = min(cnt(i-1,j),cnt(i-1,j^1)+2);
		else
			dp[i][j] = cnt(i-1,j^1)+1;
	}
	return dp[i][j];
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	int t,n;
	cin>>t;

	for(int tst=1;tst<=t;tst++)
	{
		cin>>s;
		
		memset(dp,-1,sizeof(dp));
		
		cout<<"Case #"<<tst<<": "<<cnt(s.size()-1,0)<<endl;		
	}
	
	return 0;
}
