// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
vector< vector<int> > nblist;
bool v(int cur)
{
	if(visited[cur]==true)
		return true;
	else
	{
		visited[cur]=true;
		return false;
	}
}
bool find(int cur)
{
	int i = 1;
	bool f = v(cur);
	if(f)
	{
		return true;
	}
	for(;i<nblist[cur].size();i++)
	{
		f = find(nblist[cur][i]);
		if(f)
			return true;
	}
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("ai.in","r",stdin);
	freopen("ao.txt","w",stdout);
	int T;
	int N;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		cin>>N;
		vector<int> M(N+1);
		int j;
		nblist.resize(N+1);
		for(j=1;j<=N;j++)
		{
			
			int m;
			cin>>m;
			M[j] = m;
			int k;
			nblist[j].resize(M[j]+1);
			for(k=1;k<=M[j];k++)
			{
				cin>>nblist[j][k];
			}
		}

		//
		bool ff =false;
		for(j=1;j<=N;j++)
		{
			//visited.resize(M[j]);
			visited.clear();
			visited.resize(N+1);
			bool f = find(j);
			if(f)
			{
				cout<<"Case #"<<i+1<<": Yes"<<endl;
				ff = true;
				break;
			}
		}
		if(!ff)
		{
			cout<<"Case #"<<i+1<<": No"<<endl;
		}
	}
	return 0;
}

