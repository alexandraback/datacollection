// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	cin>>t;
	for (int cs=0;cs<t;cs++)
	{
		int s;
		string str;
		cin>>s;
		cin>>str;
		int sum=0;
		int ans=0;
		for (int i=0;i<=s;i++)
			if (i<=sum)
				sum+=str[i]-'0';
			else
			{
				ans+=i-sum;
				sum=i+str[i]-'0';
			}
		cout<<"Case #"<<cs+1<<": "<<ans<<endl;
	}
	return 0;
}