#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

vector<int>v[10];
int T,ts,n,m,i,j,st;
int p[20],u[20];
string ans,cur,a[20];
char str[20];
vector<int>w[10];

void dfs(int i)
{
	cur+=a[i];
	int j;
	for(j=0;j<w[i].size();j++)
		dfs(w[i][j]);
}

bool pr(int i,int j)
{
	return a[i]<a[j];
}
	

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",&str);
			a[i]=str;
			v[i].clear();
			p[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			i--;
			j--;
			v[i].push_back(j);
			v[j].push_back(i);
		}
		ans="a";
		st=0;
		for(i=0;i<n;i++)
			if(a[i]<a[st])
				st=i;
		p[st]=-1;
		while(1)
		{
			for(i=0;i<n;i++)
			{
				memset(u,0,sizeof(u));
				for(j=i;j!=st && !u[j];j=v[j][p[j]])
					u[j]=1;
				if(u[j])
					break;
			}
			if(i==n)
			{
				for(i=0;i<n;i++)
					w[i].clear();
				for(i=0;i<n;i++)
					if(i!=st)
						w[v[i][p[i]]].push_back(i);
				for(i=0;i<n;i++)
					sort(w[i].begin(),w[i].end(),pr);
				cur="";
				dfs(st);
				if(cur<ans)
					ans=cur;
			}
			for(j=n-1;j>=0;j--)
				if(j!=st && p[j]<v[j].size()-1)
					break;
			if(j==-1)
				break;
			p[j]++;
			for(j++;j<n;j++)
				if(j!=st)
					p[j]=0;
		}
		printf("Case #%d: %s\n",++ts,ans.c_str());
	}
	return 0;
}