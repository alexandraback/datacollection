// gcj1c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	int t;
	cin>>t;
	for (int cs=1;cs<=t;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		int c,d,v;
		int a[110];
		int dp[110]={};
		int ans=0;
		cin>>c>>d>>v;
		dp[0]=1;
		for (int i=1;i<=d;i++)
		{
			cin>>a[i];
			for (int j=v;j>=0;j--)
			{
				if (dp[j]==1) dp[j+a[i]]=1;
			}
		}
		for (int i=1;i<=v;i++)
		{
			if (dp[i]!=1)
			{
				ans++;
				for (int j=v;j>=0;j--)
				{
					if (dp[j]==1) dp[j+i]=1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}