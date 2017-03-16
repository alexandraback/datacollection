#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pii zipX[55];
int T, TK;
int G[55][55];
int zip[55];

int ans[55];
int currOut[55];
int dep[55];

bool secured[55];

bool vis[55];
int dfs(int x,int N)
{
	if(vis[x]) return 0;
	vis[x] = true;
	for(int y = 1;y <= N;y++)
	{
		if(!G[x][y] || vis[y] || secured[y]) continue;
		dfs(y,N);
	}
	return 0;
}

int stk[55];
int STop = 0;
bool isConnected(int back,int N)
{
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < STop;i++)
	{
		dfs(stk[i],N);
		if(stk[i] == back) break;
	}
	
	for(int i = 1;i <= N;i++)
	{
		if(!secured[i] && !vis[i]) return false;
	}
	return true;
}

int greedy(int N)
{
	int x = min_element(zip+1,zip+1+N) - zip;
	int root = x;
	memset(currOut,-1,sizeof(currOut));
	memset(dep,0,sizeof(dep));
	memset(secured,0,sizeof(secured));

	int idx = 0;
	set<pii> availFrom[55]; // [to] =  set{ (depth, from) }
	ans[idx++] = x;
	secured[x] = true;
	dep[x] = 0;
	
	STop = 0;
	stk[STop++] = x;
	while(idx < N)
	{
		for(int y = 1;y <= N;y++) 
		{
			if(!G[x][y]) continue;
			availFrom[y].insert(pii(-dep[x],x));
		}
		for(int i = 0;i < N;i++)
		{
			int nxt = zipX[i].second;
			if(secured[nxt]) continue;
			if(availFrom[nxt].empty()) continue;
			
			// try:
			int back = (availFrom[nxt].begin())->second;
			if(back == x)
			{
				// yeah
				currOut[x] = nxt;
				dep[nxt] = dep[x] + 1;
				x = nxt;
				break;
			}

			G[back][currOut[back]] = G[currOut[back]][back] = 0;
			if(isConnected(back,N))
			{
				// succ!
				while(stk[STop-1] != back)
				{
					int tx = stk[STop-1];
					for(int j = 1;j <= N;j++) if(G[tx][j]) availFrom[j].erase(pii(-dep[tx],tx));
					availFrom[x].erase(pii(-dep[back],back));
					--STop;
				}
				currOut[back] = nxt;
				dep[nxt] = dep[back] + 1;
				x = nxt;
				break;
			}
			G[back][currOut[back]] = G[currOut[back]][back] = 1;
		}
		
		secured[x] = true;
		stk[STop++] = x;
		ans[idx++] = x;
	}
	return 0;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++TK);

		int N = 0;
		int M = 0;
		scanf("%d %d",&N,&M);
		memset(G,0,sizeof(G));
		for(int i = 1;i <= N;i++) scanf("%d",&zip[i]);
		for(int i = 0;i < M;i++)
		{
			int x = 0;
			int y = 0;
			scanf("%d %d",&x,&y);
			G[x][y] = G[y][x] = 1;
		}

		for(int i = 0;i < N;i++) zipX[i] = pii(zip[i+1],i+1);
		sort(zipX,zipX+N);
		greedy(N);
		for(int i = 0;i < N;i++) printf("%d",zip[ans[i]]);
		puts("");
	}
	while(getchar() != EOF);
	return 0;
}
