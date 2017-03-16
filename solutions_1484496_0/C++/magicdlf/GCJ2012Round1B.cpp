// GCJ2012Round1B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "string.h"
#include "stdio.h"
#include "vector"
#include "queue";
#include "algorithm"

using namespace std;

vector<int> s;
vector<int> a,b;
int dfs(int cur, int N, int sum, int mask)
{
	if(sum==0 && mask==3)
		return 1;
	if(cur==N)
	{
		return 0;
	}
	else
	{
		if(dfs(cur+1,N,sum,mask))
		{
			return 1;
		}
		if(dfs(cur+1,N,sum+s[cur],mask|1))
		{
			a.push_back(s[cur]);
			return 1;
		}
		if(dfs(cur+1,N,sum-s[cur],mask|2))
		{
			b.push_back(s[cur]);
			return 1;
		}
	}
}

int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		s.clear();
		for(int i=0;i<N;i++)
		{
			int t;
			cin>>t;
			s.push_back(t);
		}
		cout<<"Case #"<<tc+1<<":"<<endl;;
		a.clear();
		b.clear();
		if(dfs(0,N,0,0)==0)
			cout<<"Impossible"<<endl;
		else
		{
			for(int i=0;i<a.size();i++)
			{
				if(i) cout<<" ";
				cout<<a[i];
			}
			cout<<endl;
			for(int i=0;i<b.size();i++)
			{
				if(i) cout<<" ";
				cout<<b[i];
			}
			cout<<endl;
		}
	}
	return 0;
}