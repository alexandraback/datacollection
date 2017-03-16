#include<cstdio>
#include<vector>
#define NMAX 1005
using namespace std;

vector<int> G[NMAX];
char Viz[NMAX];
int ans;

void DFS(int x)
{
	Viz[x] = 1;
	for(int i = 0; i < G[x].size(); ++i)
	{
		if(Viz[G[x][i]])
		{
			ans = 1;
			return;
		}
		DFS(G[x][i]);
	}
}

void solve()
{
	int n;
	scanf("%d", &n);

	for(int x = 1; x <= n; ++x)
	{
		int m;
		scanf("%d", &m);
		while(m--)
		{
			int y;
			scanf("%d", &y);
			G[x].push_back(y);
		}
	}

	ans = 0;
	for(int x = 1; x <= n && !ans; ++x)
	{
		for(int i = 1; i <= n; ++i)
			Viz[i] = 0;
		DFS(x);
	}
	if(ans)
		printf("Yes\n");
	else
		printf("No\n");
	for(int x = 1; x <= n; ++x)
		G[x].clear();
}

int main()
{
	//freopen("input.txt", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
