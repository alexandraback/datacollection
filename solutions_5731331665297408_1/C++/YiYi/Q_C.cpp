#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cmath> 
#include<cstring> 
#include<map> 
#include<set>
#include<algorithm>

using namespace std;

int ans[64];
int zip[64];
int ord[64];
bool con[64][64];
int n, m;

bool cmp(int a, int b)
{
	return zip[a] < zip[b];
}

bool isCon(int a, int b)
{
	return con[ord[a]][ord[b]];
}

bool Used[64];
int path[64], plen;
int vpath[64];

bool vis[64];

void visit(int v)
{
	int i;
	vis[v] = true;
	for(i = 0; i < n; i ++)
	{
		if(!Used[i] && !vis[i] && isCon(i, v))
		{
			visit(i);
		}
	}
}

bool check(int ps)
{
	int i;
	memset(vis, false, sizeof(vis));
	for(i = ps; i >= 0; i --)
	{
		visit(path[i]);
	}
	for(i = 0; i < n; i ++)
	{
		if(!Used[i] && !vis[i])return false;
	}
	return true;
}

bool flag;
int cas;

void Output()
{
	int i;
	printf("Case #%d: ", cas);
	for(i = 1; i <= n; i ++)
	{
		printf("%05d", zip[ord[vpath[i]]]);
	}
	putchar('\n');
}

void dfs(int v, int d)
{
	int i, j;
	int rec, reclen;
	vpath[d] = v;

	if(d == n)
	{
		Output();
		flag = true;
		return;
	}

	for(i = 0; i < n; i ++)
	{
		if(Used[i])continue;
		for(j = plen; j >= 0; j --)
		{
			if(isCon(path[j], i))
			{
				if(check(j))
				{
					Used[i] = true;
					rec = path[j+1];
					reclen = plen;
					path[j+1] = i;
					plen = j+1;
					dfs(i, d+1);
					if(flag)return;
					path[j+1] = rec;
					plen = reclen;
					Used[i] = false;
				}
				break;
			}
		}
	}
}

int main()
{
	//freopen("C-large-practice.in", "r", stdin);
	//freopen("C-large2.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for(cas = 1; cas <= T; cas ++)
	{
		int i, j;
		scanf("%d%d", &n,&m);
		
		for(i = 0; i < n; i ++)
		{
			scanf("%d", &zip[i]);
			ord[i] = i;
		}
		memset(con, false, sizeof(con));
		while(m --)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--;y--;
			con[x][y] = true;
			con[y][x] = true;
		}

		sort(ord, ord+n, cmp);

		for(i = 0; i < n; i ++)
		{
			Used[i] = true;
			path[0] = i;
			plen = 0;
			dfs(i, 1);
			if(flag)break;
		}
		memset(Used, false, sizeof(Used));
	}
	return 0;
}
