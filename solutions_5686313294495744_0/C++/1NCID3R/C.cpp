#include <bits/stdc++.h>
using namespace std;

#define SOURCE 0
#define SINK 1
#define OFF1 2
#define OFF2 1002

map<string,int> mpos[2];
deque<int> graph[2005];
int res[2005][2005];
int vis[2005];

void connect(int u, int v, int x, int y)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
	res[u][v] = x;
	res[v][u] = y;
}

int getpos(int k, string str)
{
	auto it = mpos[k].find(str);
	if(it==mpos[k].end())
	{
		int s = mpos[k].size();
		mpos[k][str] = s;
		if(k==0)
		{
			graph[s+OFF1].clear();
			connect(SOURCE,s+OFF1,1,0);
		}
		else
		{
			graph[s+OFF2].clear();
			connect(s+OFF2,SINK,1,0);
		}

		return s;
	}

	return it->second;
}

bool dfs(int pos)
{
	if(pos==SINK)
		return true;

	for(int i=0; i<graph[pos].size(); i++)
	{
		int v = graph[pos][i];
		if(vis[v] || res[pos][v]==0)
			continue;

		vis[v] = true;
		if(dfs(v))
		{
			res[pos][v]--;
			res[v][pos]++;
			return true;
		}
	}

	return false;
}

int main()
{
	int t;
	cin >> t;

	for(int cn=1; cn<=t; cn++)
	{
		int n;
		cin >> n;

		graph[SOURCE].clear();
		graph[SINK].clear();

		for(int i=0; i<2; i++)
			mpos[i].clear();

		for(int i=0; i<n; i++)
		{
			string str;
			int pos[2];
			for(int j=0; j<2; j++)
			{
				cin >> str;
				pos[j] = getpos(j,str);
			}

			connect(pos[0]+OFF1,pos[1]+OFF2,1,0);
		}

		int mf = 0;
		while(1)
		{
			for(int i=0; i<2005; i++)
				vis[i] = false;
			vis[SOURCE] = true;
			if(dfs(SOURCE))
				mf++;
			else
				break;
		}

		for(int i=0; i<graph[SOURCE].size(); i++)
		{
			int v = graph[SOURCE][i];
			if(res[SOURCE][v])
				mf++;
		}

		for(int i=0; i<graph[SINK].size(); i++)
		{
			int v = graph[SINK][i];
			if(res[v][SINK])
				mf++;
		}

		printf("Case #%d: %d\n",cn,n-mf);
	}
}