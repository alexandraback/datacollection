# include <stdio.h>


int ans ;
int a[1010], b[1010] ;
int vis[1010] ;
int n ;
int cnt ;

int step[1000][2];

void dfs(int stars, int num, int level)
{
	int buff, i ;
	if (num == n)
	{
		if (level < ans) ans = level ;
		if (level == 5)
		{
			for(i = 0 ; i < cnt ; i++)
				printf ("%d, %d\n", step[i][0], step[i][1]) ;
			puts ("") ;
		}
		return ;
	}
	for (i = 0 ; i < n ; i++)
	{
		if (vis[i] != 2 && b[i] <= stars)
		{
			step[cnt][0] = i ;
			step[cnt++][1] = 2 ;
			buff = vis[i] ;
			vis[i] = 2 ;
			dfs(stars+2-buff, num+1, level+1) ;
			vis[i] = buff ;
			cnt-- ;
		}
		if (vis[i] == 0 && a[i] <= stars)
		{
			step[cnt][0] = i ;
			step[cnt][1] = 1 ;
			cnt++ ;
			vis[i] = 1 ;
			dfs (stars + 1, num, level+1) ;
			vis[i] = 0 ;
			cnt-- ;
		}
	}
}


int main ()
{
	int T , i, nCase = 1 ;
//	freopen ("B-small-attempt0.in", "r", stdin) ;
//	freopen ("bb.txt", "w", stdout) ;
	
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d", &n) ;
		for (i = 0 ; i < n ; i++)
		{
			scanf ("%d%d", &a[i], &b[i]) ;
			vis[i] = 0 ;
		}
		ans = 0x0f0f0f0f ;
		dfs (0,0, 0) ;
		if (ans == 0x0f0f0f0f)
		{
			printf ("Case #%d: Too Bad\n", nCase++) ;
		}
		else
			printf ("Case #%d: %d\n", nCase++, ans) ;
	}
	return 0 ;
}
