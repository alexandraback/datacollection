# include <stdio.h>
# include <string.h>


int cb[1000010] ;
int xy[1000010] ;
char ans[1000010] ;
int n ;


int gao(int x)
{
	int i, sum = 0 ;
	for (i = 1 ; ; i++)
	{
		cb[i] = 1 ;
		sum += i ;
		if (sum >= x && (sum-x)%2 == 0) break ;
	}
	cb[(sum-x)/2] = -1 ;
	return i ;
}


int abs(int x){return x<0?-x:x;}
int calc(int n, int x)
{
	int i ;
	for (i = n ; i >= 1 ; i--)if (cb[i] == 1)
	{
		if (i <= x){
			xy[i] = 1 ;
			x -= i ;
		}
	}
	return x == 0 ;
}



void set (int f, char ch1, char ch2)
{
	int i ;
	for (i = 1 ; i <= n ; i++)if (xy[i] == f)
	{
		if (cb[i] == 1) ans[i] = ch1 ;
		else ans[i] = ch2 ;
	}
}


int main ()
{
	int T, nCase = 1 ;
	int x, y ;
	//srand (time(0)) ;
	freopen ("B-large.in", "r", stdin) ;
	freopen ("B-large.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d%d", &x, &y) ;
		//x = rand()%1000000, y = rand()%1000000 ;
		n = gao(abs(x)+abs(y)) ;
		memset (xy, 0, sizeof(xy)) ;
		printf ("Case #%d: ", nCase++) ;
		if (calc(n, abs(x))){
			if (x >= 0) set(1, 'E', 'W') ;
			else set(1, 'W', 'E') ;
			if (y >= 0) set (0, 'N', 'S') ;
			else set(0, 'S', 'N') ;
			ans[n+1] = '\0' ;
			puts (ans+1) ;
		}
		
		else if (calc(n, abs(y)))
		{
			if (y >= 0) set(1, 'N', 'S') ;
			else set(1, 'S', 'N') ; 
			if (x >= 0) set(0, 'E', 'W') ;
			else set(0, 'W', 'E') ;
			ans[n+1] = '\0' ;
			puts (ans+1) ;
		}
		else printf ("Pitty!!!\n") ;
		//printf ("%d\n", nCase++) ;
		//if (!calc(n, x) && !calc(n, y))printf ("%d, %d, Pitty!\n", x, y) ;
		//else printf ("Good!\n") ;
	}
	return 0 ;
}
