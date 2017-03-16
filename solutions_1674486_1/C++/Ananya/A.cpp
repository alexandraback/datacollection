#include <cstdio>
#include <vector>
using namespace std;

#define MAXD 1010
vector< vector<int> > g;
bool visited[MAXD];
int T, M, N, i, j, dia;

bool dfs ( int v )
{
	if ( visited[v] ) return true;
	visited[v] = true;
	bool seen = false;
	
	for ( int i = 0; i < g[v].size(); i++ )
	{
		seen |= dfs(g[v][i]);
	}
	
	return seen;
}

int main ()
{
	scanf("%d",&T);
	
	for ( int cnt = 1; cnt <= T; cnt++ )
	{
		scanf("%d",&N);
		g.assign(N+1,vector<int>());
		dia = false;
		
		for ( i = 1; i <= N; i++ )
		{
			scanf("%d",&M);
			g[i].assign(M,0);
			
			for ( j = 0; j < M; j++ )
			{
				scanf("%d",&g[i][j]);
			}
		}
		
		for ( i = 1; i <= N; i++ )
		{
			for ( j = 1; j <= N; j++ ) visited[j] = false;
			if ( dfs(i) ) { dia = true; break; }
		}
		
		if ( dia ) printf("Case #%d: Yes\n",cnt);
		else printf("Case #%d: No\n",cnt);
	}
}