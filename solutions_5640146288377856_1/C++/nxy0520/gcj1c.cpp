// gcj1c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	cin>>t;
	for (int cs=1;cs<=t;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		int r,c,n;
		int ans=0;
		cin>>r>>c>>n;
		ans=c/n*r;
		if (c%n==0) ans+=n-1;
		else ans+=n;
		cout<<ans<<endl;
	}
	return 0;
}