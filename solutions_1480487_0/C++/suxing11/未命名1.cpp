# include <stdio.h>


int s[210] ;
double v[210] ;
int n, x ;


int test(double pi, int idx)
{
	double pt = s[idx] + pi * x ;
	double totp = 1 - pi, vv;
	int i ;
	for (i = 0 ; i < n ; i++)
	{
		if (idx == i) continue ;
		if (s[i]*1.0 > pt) continue ;
		vv = (pt - s[i]) * 1.0 / x ;
		totp -= vv ;
		if (totp < 0) return 0 ;
	}
	return 1 ;
}



double gao(int idx)
{
	double l = 0, r = 1, m ;
	while (r-l > 1e-9)
	{
		m =(l+r)*0.5 ;
		if (test(m, idx)) l = m ;
		else r = m ;
	}
	return m ;
}


int main ()
{
	int T, i, nCase = 1 ;
	freopen ("A-small-attempt0 (1).in", "r", stdin) ;
//	freopen ("aout.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while(T--)
	{
		scanf ("%d", &n) ;
		for (i = 0, x = 0 ; i < n ; i++)
		{
			scanf ("%d", &s[i]) ;
			x += s[i] ;
		}
		for (i = 0 ; i < n ; i++)
			v[i] = gao(i) ;
		printf ("Case #%d:", nCase++) ;
		for (i = 0 ; i < n ; i++)
			printf (" %lf", v[i]*100.0) ;
		puts ("") ;
	}
	return 0 ;
}
