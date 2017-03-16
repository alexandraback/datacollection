#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define psi pair<string, int>
#define F first
#define S second
#define N 50
using namespace std;

char buff[10];

int n, m;
string label[N];

set<int> g[N]; // adj list
int dfs_num[N], dfs_low[N], dfs_par[N]; // dfs stuff
bool art[N]; //holds the anwser

int root, root_ch;
int num;

// Find articulation points O(n)

void dfs(int v){
	dfs_num[v]=dfs_low[v]=num++;
	for(auto it = g[v].begin(); it != g[v].end();++it){
		int u = *it;
		if( dfs_num[u] == -1 ){
			if(v==root) ++root_ch;
			dfs_par[u]=v;
			dfs(u);
			dfs_low[v]=min(dfs_low[u],dfs_low[v]);
			art[v] |= dfs_low[u] >= dfs_num[v]; 
		}else if( dfs_par[v] != u )
			dfs_low[v]=min(dfs_num[u],dfs_low[v]);
	}
}

void find_art()
{
	for(int i=0;i<n;++i)
	{
		dfs_num[i] = dfs_par[i] = -1;
		art[i]=0;
	}
	// call dfs 		
	for(int i=0;i<n;++i)
		if( dfs_num[i] == -1 )
		{
			root=i; root_ch=0;
			dfs(i);
			art[i] = root_ch > 1;
		}
}

string ans;
bool vis[N];
set<string> ch[N];
map<string, int> lv;

void solve(int v, int prv)
{
	vis[v] = 1;
	ans += label[v];
	for(auto it = g[v].begin(); it != g[v].end();++it)
	{
		if(vis[*it])
			ch[*it].erase(label[v]);
		else
			ch[v].insert(label[*it]);
	}
	
	while(ch[v].size())
	{
		string q = *ch[v].begin();
		int u = lv[q];

		if(prv != -1 && ch[prv].size() && *ch[prv].begin() < q && !art[v])
		{
				for(auto it = g[v].begin(); it != g[v].end();++it)
					g[*it].erase(v);
				g[v].clear();
				find_art();
				return ;
		}
		ch[v].erase(q);
		solve(u, v);
	}

}

int main()
{
	int t;scanf("%d",&t);
	for(int cs=1; cs<=t;++cs)
	{
		scanf("%d%d",&n,&m);
		int s = 0;
		lv.clear();
		ans.clear();
		for(int i=0;i<n;++i)
		{
			scanf("%s", buff);
			label[i] = buff;
			lv[label[i]] = i;
			if(label[i] < label[s]) s = i;
			g[i].clear();
			ch[i].clear();
		}
		for(int i=0;i<m;++i)
		{
			int a,b; scanf("%d%d",&a,&b);--a,--b;
			g[a].insert(b);
			g[b].insert(a);
		}
		memset(vis, 0, sizeof vis);
		find_art();
		solve(s, -1);
		printf("Case #%d: %s\n", cs, ans.c_str());
	}
	return 0;
}
