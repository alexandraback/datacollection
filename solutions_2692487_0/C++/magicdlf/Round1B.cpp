// Round1B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "string.h"
#include "stdio.h"

using namespace std;

int best=99999999;
int check(vector<int> &g, int A, int ans)
{
	for(int i=0;i<g.size();i++)
	{
		if(A>g[i])
		{
			A+=g[i];
		}
		else
		{
			best=min(best,(int)g.size()-i+ans);
			return A-1;
		}
	}
	return -1;
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		best=99999999;
		int A,N;
		cin>>A>>N;
		vector<int> g(N);
		for(int i=0;i<N;i++)
			cin>>g[i];
		int ans=0;
		while(1)
		{
			sort(g.begin(),g.end());
			int ret=check(g,A,ans);
			if(ret==-1)
			{
				best=min(best,ans);
				break;
			}
			if(ret==0) break;
			ans++;
			g.push_back(ret);
		}
		cout<<"Case #"<<tc+1<<": "<<best<<endl;
	}
	return 0;
}