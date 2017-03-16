# include <stdio.h>
# include <string.h>
# include <stdlib.h>


int A, B ;
int ans[300][2], cnt ;
int buff[100], cc ;


int gao(char s[], int len, int num)
{
	int i, nn = 0 ;
	if (s[0] == '0') return 0 ;
	for(i = 0 ; i < len ; i++)
		nn = nn * 10 + s[i] -'0' ;
	if (nn <= B && nn > num){
		for (i = 0 ; i < cc ; i++)
			if (buff[i] == nn) break ;
		if (i == cc)
		{
			buff[cc++] = nn ;
			return 1 ;
		}
	}
	return 0 ;
}


int calc(int n)
{
	char s[30], s2[30] ;
	int i, len, rtn = 0 ;
	sprintf (s, "%d", n) ;
	len = strlen(s) ;
	strcpy(s2, s) ;
	strcat (s, s2) ;
	cc = 0 ;
	for (i = 0 ; i < len ; i++)
		if (gao(s+i, len, n)) rtn++ ;
//	printf ("\n") ;
	return rtn ;
}


int cmp (const void *a, const void *b)
{
	long long p = *(long long *)a, q = *(long long *) b;
	int x1, y1,  x2 , y2 ;
	x1 = p&0xffffffff, y1 = (p >> 32) ;
	x2 = q&0xffffffff, y2 = (q >> 32) ;
	if (x1 != x2) return x1 - x2 ;
	return y1 - y2 ;
}


int main ()
{
	int i,j, T ;
	int a, b, sum, nCase = 1 ;
	freopen ("C-large.in", "r", stdin) ;
	freopen ("c-out~.txt", "w", stdout) ;

	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d%d", &a, &b) ;
		A = a, B = b ;
		sum = 0 ;
		for(i = a ; i <= b ; i++)
			sum += calc(i) ;
//		qsort(ans, cnt, 8, cmp) ;
//		for (i = 1 ; i < cnt ; i++) 
//			if (ans[i][0] == ans[i-1][0] && ans[i][1] == ans[i-1][1])
//			printf ("%d, %d, %d\n", i, ans[i][0], ans[i][1]) ;
		printf ("Case #%d: %d\n", nCase++, sum) ;
		
	}
	
	return 0 ;
}
