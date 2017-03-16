# include <stdio.h>
# include <stdlib.h>


typedef long long ll ;
ll A, N, mote[110] ;
ll ans ;


ll min(ll a, ll b){return a<b?a:b;}


long long gao()
{
	ll t, i ;
	if (A == 1) return N ;
	ans = N ;
	t = 0 ;
	for (i = 0 ; i < N ; i++)
	{
		while (A <= mote[i]) A += A-1, t++ ;
		A += mote[i] ;
		ans = min(ans, t + (N-i-1)) ;
	}
	return ans ;
}


int cmp(const void *a, const void *b)
{
	return *(ll*)a - *(ll*)b ;
}


int main ()
{
	int T, nCase = 1 ;
	ll i ;
	freopen ("A-small-attempt0.in", "r", stdin) ;
	freopen ("A-small-attempt0.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%I64d%I64d", &A, &N) ;
		for (i = 0 ; i < N ; i++)
			scanf ("%I64d", &mote[i]) ;
		qsort(mote, N, sizeof(mote[0]), cmp) ;
		printf ("Case #%d: ", nCase++) ;
		printf ("%I64d\n", gao()) ;
	}
	return 0 ;
}
