// GCJ2012Qual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stdio.h"

using namespace std;

int used[2000005]={};
int check(int n, int a, int b)
{
	int cnt=0;
	vector<int> g;
	while(n)
	{
		g.push_back(n%10);
		n/=10;
	}
	reverse(g.begin(),g.end());
	int sz=g.size();
	int ans=0;
	for(int i=0;i<sz;i++)
	{
		if(g[i]==0) continue;
		int cur=0;
		for(int j=0;j<sz;j++)
		{
			cur*=10;
			cur+=g[(i+j)%sz];
		}
		if(used[cur]==0 && cur>=a && cur<=b)
		{
			ans++;
			used[cur]=1;
		}
	}
	return ans;
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int A,B;
		cin>>A>>B;
		memset(used,0,sizeof(used));
		long long ans=0;
		for(int i=A;i<=B;i++)
		{
			if(used[i]) continue;
			int t=check(i,A,B);
			ans+=t*(t-1)/2;
		}
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}