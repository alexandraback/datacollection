#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 101
int main()
{
	int t,n,ans,last[MAX],dp[MAX][MAX];
	string s;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ans=0;
		cin>>s;
		cin>>n;
		int l=s.length();
		if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u')last[0]=0;
		else last[0]=1;
		for(int i=1;i<l;i++)
		{
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')last[i]=0;
			else last[i]=last[i-1]+1;
		}
		for(int i=0;i<l;i++)
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')dp[i][1]=0;
			else dp[i][1]=1;
		for(int j=2;j<=l;j++)
			for(int i=0;i<=l-j;i++)
			{
				dp[i][j]=max(dp[i][j-1],min(last[i+j-1],j));
			}
		for(int j=1;j<=l;j++)
			for(int i=0;i<=l-j;i++)
			{
				if(dp[i][j]>=n)
				{
			//		cout<<i<<" "<<j<<endl;
					ans++;
				}
			}
		cout<<"Case #"<<k<<": "<<ans<<"\n";
	}
	return 0;
}
