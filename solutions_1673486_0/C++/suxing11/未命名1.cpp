# include <stdio.h>


double p[100010] ;
double sump[1000010] ;


double gao(int a, int n)
{
	double p1, p2 ;
	p1 = sump[a] ;
	p2 = 1 - p1 ;
	return p1 * (n-a+1) + p2 * (n-a+1+n+1) ;
}


double calc(int a, int n)
{
	if (a < n) return n+2 ;
	return sump[n]*1.0 + (1-sump[n])*(n+2) ;
}


int main ()
{
	int T, i ;
	int a, b, nCase = 1;
	double ans, buf_ans ;
	freopen ("A-small-attempt0.in", "r", stdin) ;
	freopen ("Aout.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d%d", &a, &b) ;
		sump[0] = 1 ;
		for (i = 1 ; i <= a ; i++)
		{
			scanf ("%lf", &p[i]) ;
			sump[i] = sump[i-1] * p[i] ;
		}

		ans = calc(a,b) ;
		for (i = a ; i >= 0 ; i--)
		{
			buf_ans = a-i+gao(i,b) ;
			if (buf_ans < ans) ans = buf_ans ;
		}
		printf ("Case #%d: %.6lf\n", nCase++, ans) ;
	}
	return 0 ;
}
