// Round1C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "string"
#include "string.h"
#include "stdio.h"

using namespace std;
long long MOD=1000000007;
int visited[105]={};
vector<string> g;
int n;
long long ans=0;
int dfs(int cur, string path)
{
	if(cur==n)
	{
		int used[250]={};
		used[path[0]]++;
		for(int i=1;i<path.size();i++)
		{
			if(path[i]!=path[i-1])
			{
				used[path[i]]++;
				if(used[path[i]]>1) return 0;
			}
		}
		ans++;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]) continue;
		visited[i]=1;
		dfs(cur+1,path+g[i]);
		visited[i]=0;
	}
	return 0;
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		g.clear();
		cin>>n;
		int isgood=1;
		for(int i=0;i<n;i++)
		{
			string str;
			cin>>str;
			string q;
			q.push_back(str[0]);
			for(int j=1;j<str.size();j++)
			{
				if(str[j]!=str[j-1])
				{
					q.push_back(str[j]);
				}
			}
			g.push_back(q);
		}
		int cur=0;
		memset(visited,0,sizeof(visited));
		ans=0;
		dfs(0,"");

		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}