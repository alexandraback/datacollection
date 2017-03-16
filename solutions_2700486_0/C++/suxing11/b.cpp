# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#define N 100000000
int sum[1010], outside[1010] ;
int fm[10000], fz[10000] ;


int moni(int ss, int ll, int rr)
{
	int p, q, f ;
	p = ss, q = ss ;
	while (rr--)
	{
		if (p == 0)
		{
			q--, ll-- ;
		}
		else if (q == 0) p-- ;
		else
		{
			f = rand()%2 ;
			if (f == 0)p-- ;
			else q--, ll-- ;
		}
		if (ll == 0) return 1 ;
	}
	return 0 ;
}


double dfs (int l, int r, int rem, int level)
{
	if (level == 0) return 1.0 ;
	if (rem == 0) return 0 ;
	if (l == 0) return dfs (l, r-1, rem-1, level-1) ;
	else if (r == 0) return dfs (l-1, r, rem-1, level) ;
	return 0.5 * (dfs(l,r-1,rem-1,level-1) + dfs(l-1,r,rem-1,level)) ;
}


double calc(int s, int l, int r)
{
	double ans = 0 ;
	int i ;
	if (r <= 20) return dfs(s, s, r, l) ;
	for (i = 0 ; i <= N ; i++)
		ans += moni(s,l,r) ;
	return ans / N ;
}


double gao(int nn, int x, int y)
{
	int i, idx = 0 ;
	int p, q, r ;
	int xy, level, side ;
	for (i = 1 ; ; i++)
		if (sum[i] < nn) idx = i ;
		else break ;
	p = sum[idx], q = outside[idx], r = nn-sum[idx] ;
	idx = (idx-1)*2 ;
	if (x+y == 0) return 1 ;
	xy = x+y ;
	if (xy <= idx) return 1 ;
	if (xy > idx+2) return 0 ;
	if (x == 0)
	{
		if (q == r) return 1 ;
		else return 0 ;
	}
	level = y+1 ;
	side = (q-1)/2 ;
	if (r-side>=level) return 1 ;
	return calc(side, level, r) ;
}


void init()
{
	int i ;
	sum[0] = 0, outside[0] = 1 ;
	for (i = 1 ; i <= 1000 ; i++)
		sum[i] = sum[i-1]+outside[i-1],
		outside[i] = outside[i-1]+4 ;
}


int main ()
{
	int T, nCase = 1, n, x, y ;
	double ans ;
	freopen ("B-small-attempt0.in", "r", stdin) ;
	freopen ("B-small-attempt0.txt", "w", stdout) ;
	srand(time(0)) ;
	init() ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d%d%d", &n, &x, &y) ;
		if (x < 0) x = -x ;
		ans = gao(n, x, y) ;
		printf ("Case #%d: %.7lf\n", nCase++, ans) ;
	}
	return 0 ;
}
