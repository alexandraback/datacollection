# include <stdio.h>
# include <math.h>


double d ;
double t[2010], x[2010] ;
int n ;


double max(double a, double b){return a>b?a:b;}


double gao(double ac)
{
	double mt = sqrt(2.0 * d / ac) ;
	double t1, x1, t2, x2 ;
	double s1, s2 ;
	if (n == 1) return mt ;
	if (n > 2) while (1) ;
	if (t[0] == t[1]) while (1) ;
	if (x[0] >= d) return mt ;
	t1 = t[0] , x1 = x[0] ;
	if (x[1] <= d) t2 = t[1], x2 = x[1] ;
	else t2 = (t[1] - t[0]) * (d-x[0]) / (x[1]-x[0]) + t[0], x2 = d ;
	
	s1 = x1 - 0.5*ac*t1*t1 ;
	s2 = x2 - 0.5*ac*t2*t2 ;
	
//	if (s1 < 0 && s2 < 0) return mt ;
	if (s1 > 0 && s2 > 0) return mt ;
	if (x2 == d) return max(t2, mt) ;
//	if (t2 + sqrt(2*(d-x2)/ac) < mt) while (1) ;
	return t2 + sqrt(2*(d-x2)/ac) ;
}


int main ()
{
	int T , i, a ;
	int nCase = 1 ;
	double ac ;
	freopen ("B-small-attempt2.in", "r", stdin) ;
	freopen ("Bout.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%lf%d%d", &d, &n, &a) ;
		for (i = 0 ; i < n ; i++)
			scanf ("%lf%lf", &t[i], &x[i]) ;
		printf ("Case #%d:\n", nCase++) ;
		for (i = 0 ;i < a ; i++)
		{
			scanf ("%lf", &ac) ;
			printf ("%lf\n", gao(ac)) ;
		}
	}
	return 0 ;
}
