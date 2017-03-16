# include <stdio.h>
# include <string.h>


typedef struct NODE{
	long long num ;
	int type ;
}NODE ;




NODE a[110], b[110] ;
long long dp[110][110] ;
int n, m ;


long long min(long long a, long long b){return a<b?a:b;}
long long max(long long a, long long b){return a>b?a:b;}


long long calc(int x, int y)
{
	if (a[x].type == b[y].type)
		return min(a[x].num, b[y].num) ;
	return 0 ;
}


long long dfs(int x, int y)
{
	long long min_match ;
	long long ans = 0 ;
	if (x >= n || y >= m) return 0 ;
	
	if (a[x].type == b[y].type)
	{
		if (a[x].num <= b[y].num)
		{
			b[y].num -= a[x].num ;
			ans = a[x].num + max(ans, dfs (x+1, y));
			b[y].num += a[x].num ;
		}
		else
		{
			a[x].num -= b[y].num ;
			ans = b[y].num + max(ans, dfs(x,y+1)) ;
			a[x].num += b[y].num ;
		}
	}
	else
	{
		ans = max(dfs(x+1,y), dfs(x,y+1)) ;
	}
	return ans ;
}


int main ()
{
	int T, nCase = 1 ;
	int i, j ;
	freopen ("C-small-attempt0.in", "r", stdin) ;
	freopen ("cout.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d%d", &n, &m) ;
		for (i = 0 ; i < n ; i++)
			scanf ("%I64d%d", &a[i].num, &a[i].type) ;
		for (i = 0 ; i < m ; i++)
			scanf ("%I64d%d", &b[i].num, &b[i].type) ;
		printf ("Case #%d: %I64d\n", nCase++, dfs(0,0)) ;
	}
	return 0 ;
}
