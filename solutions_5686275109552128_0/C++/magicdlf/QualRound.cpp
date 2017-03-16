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
		int d;
		cin>>d;
		vector<int> g(d);
		for(int i=0;i<d;i++)
			cin>>g[i];
		sort(g.begin(),g.end());
		int ans=g.back();
		for(int i=1;i<=1000;i++)
		{
			int cur=i;
			int s=0;
			for(int j=0;j<d;j++)
			{
				int t=g[j]/i;
				if(g[j]%i) t++;
				s+=t-1;
			}
			ans=min(ans,cur+s);
		}
		cout<<"Case #"<<tc+1<<":  "<<ans<<endl;
	}
	return 0;
}