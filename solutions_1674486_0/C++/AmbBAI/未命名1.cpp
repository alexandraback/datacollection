# include <stdio.h>
# include <string.h>


int graph[55][55] ;
int g[55][55] ;
int vis[55] ;
int n ;


int dfs(int x)
{
	int i ;
	if (vis[x] == 1) return 1 ;
	vis[x] = 1 ;
	for (i = 1 ; i <= n ; i++)
	{
		if (i == x) continue ;
		if (graph[x][i] != 1) continue ;
		if (dfs (i)) return 1 ;
	}
	return 0 ;
}


int fuck(int x)
{
	memset (vis, 0, sizeof (vis)) ;
	return dfs (x) ;
}


int gao()
{
	int i ;
	for (i = 1 ; i <= n ; i++) //Ã¶¾ÙÆðµã
		if (fuck(i)) return 1 ;
	return 0 ;
}


int main ()
{
	int T, num, m, i ;
	int nCase = 1 ;
	freopen ("A-small-attempt0.in", "r", stdin) ;
	freopen ("aout.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		memset (graph, 0, sizeof(graph)) ;
		scanf ("%d", &n) ;
		for (i = 1 ; i <= n ; i++)
		{
			scanf ("%d", &m) ;
			while (m--)
			{
				scanf ("%d", &num) ;
				graph[i][num] = 1 ;
			}
		}
		printf ("Case #%d: ", nCase ++ ) ;
		puts (gao()?"Yes":"No") ;
	}
	return 0 ;
}
