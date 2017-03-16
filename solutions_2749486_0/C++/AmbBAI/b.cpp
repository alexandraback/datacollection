# include <stdio.h>


int ans[1000] ;
int cnt ;

int abs(int x){return x<0?-x:x;}
void gao(int x)
{
	int i ;
	cnt = 0 ;
	for (i = 0 ; i < x ; i++)
		ans[cnt++] = 1, ans[cnt++] = 0 ;
}


void output(char c1, char c2)
{
	int i ;
	for (i = 0 ; i < cnt ; i++)
		if (ans[i] == 0) putchar (c1) ;
		else putchar (c2) ;
}


int main ()
{
	int T, nCase = 1 ;
	int x, y ;
	freopen ("B-small-attempt0.in", "r", stdin) ;
	freopen ("B-small-attempt0.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d%d", &x, &y) ;
		printf ("Case #%d: ", nCase++) ;
		gao(abs(x)) ;
		if (x > 0) output ('E', 'W') ;
		else output ('W', 'E') ;
		gao(abs(y)) ;
		if (y > 0) output ('N', 'S') ;
		else output('S', 'N') ;
		printf ("\n") ;
	}
	return 0 ;
}
