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
#include <unordered_map>
#include <unordered_set>

using namespace std;

map<string,int>mp,np;
struct TT
{
	int a,c,i,o;
}t,tt;
vector<TT>v[2016];
int a[2000],b[2000],m;
bool u[2016];

void make_edge(int i,int j)
{
	TT t;
	t.i=j;
	t.a=1;
	t.c=0;
	t.o=v[j].size();
	v[i].push_back(t);
	t.i=i;
	t.a=0;
	t.o=v[i].size()-1;
	v[j].push_back(t);
}

bool dfs(int i)
{
	if(i==m-1)return true;
	int j;
	TT t;
	u[i]=1;
	for(j=0;j<v[i].size();j++)
	{
		t=v[i][j];
		if(!u[t.i] && t.a>t.c && dfs(t.i))
		{
			v[i][j].c++;
			v[t.i][t.o].c--;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T,i,ts,n;
	char s[30],st[30];
	scanf("%d",&T);
	for(ts=1;ts<=T;ts++)
	{
		scanf("%d",&n);
		mp.clear();
		np.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s%s",&s,&st);
			if(mp.find(s)==mp.end())
			{
				m=mp.size();
				mp[s]=m;
			}
			if(np.find(st)==np.end())
			{
				m=np.size();
				np[st]=m;
			}
			a[i]=mp[s];
			b[i]=np[st];
		}
		for(i=0;i<mp.size()+np.size()+2;i++)
			v[i].clear();
		for(i=0;i<n;i++)
			make_edge(a[i],b[i]+mp.size());
		m=mp.size()+np.size();
		for(i=0;i<mp.size();i++)
			make_edge(m,i);
		for(i=0;i<np.size();i++)
			make_edge(i+mp.size(),m+1);
		memset(u,0,sizeof(u));
		m+=2;
		n-=mp.size()+np.size();
		while(dfs(m-2))
		{
			n++;
			memset(u,0,sizeof(u));
		}
		printf("Case #%d: %d\n",ts,n);
	}
	return 0;
}