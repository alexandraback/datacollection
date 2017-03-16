#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int t, n, a, b;
vector <int> v[2005];
vector <int> st;
bool byl[10000];
bool odw[10000];
bool odw2[10000];
bool ok=0;
void dfs(int s)
{
	int x=s;
	odw[x]=1;
	odw2[x]=1;
	int kk=v[s].size();
	for(int i=0; i<kk; i++)
	{
		if(odw[v[s][i]]==1)
			ok=1;
		if(odw[v[s][i]]==0)
			dfs(v[s][i]);
	}
}
void dfs2()
{
	for(int i=0; i<st.size(); i++)
	{
		for(int j=0; j<=n; j++)odw[j]=0;
		dfs(st[i]);
	}
}
int main()
{
	scanf("%d", &t);
	for(int j=1; j<=t; j++)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a);
			while(a--)
			{
				scanf("%d", &b);
				byl[b]=1;
				v[i].push_back(b);
			}
		}
		for(int i=1; i<=n; i++)
			if(byl[i]==0)st.push_back(i);
		dfs2();
		if(ok==1)
			printf("Case #%d: Yes\n", j);
		else
			printf("Case #%d: No\n", j);
		for(int i=0; i<=n; i++){ok=0;v[i].clear();byl[i]=0;odw[i]=0;odw2[i]=0;}
	}
	return 0;
}
//
