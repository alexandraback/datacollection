// QualRound.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int s;
		string shy;
		cin>>s>>shy;
		int cur=0;
		int ans=0;
		for(int i=0;i<=s;i++)
		{
			int ss=shy[i]-'0';
			if(cur>=i)
			{
				cur+=ss;
			}
			else
			{
				ans+=i-cur;
				cur=i+ss;
			}
		}
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}