# include <stdio.h>


long long tab[41] = {
	0LL, 1LL, 2LL, 3LL, 11LL, 22LL, 
	101LL, 111LL, 121LL, 202LL, 212LL, 
	1001LL, 1111LL, 2002LL, 10001LL, 10101LL, 
	10201LL, 11011LL, 11111LL, 11211LL, 20002LL, 
	20102LL, 100001LL, 101101LL, 110011LL, 111111LL, 200002LL, 
	1000001LL, 1001001LL, 1002001LL, 1010101LL, 1011101LL, 
	1012101LL, 1100011LL, 1101011LL, 1102011LL, 1110111LL, 
	1111111LL, 2000002LL, 2001002LL, 10000001LL} ;
	
int main ()
{
	int i, T, cc, nCase=1 ;
	long long a, b ;
	freopen ("C-large-1.in", "r", stdin) ;
	freopen ("C_out.txt", "w", stdout) ;
	for (i = 0 ; i < 41 ; i++) tab[i] *= tab[i] ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%I64d%I64d", &a, &b) ;
		cc = 0 ;
		for (i = 0 ; i < 41 ; i++)
			if (tab[i] >= a && tab[i] <= b) cc++ ;
		printf("Case #%d: %d\n", nCase++, cc) ;
	}
	return 0 ;
}
