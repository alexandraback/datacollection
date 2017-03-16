# include <stdio.h>
# include <stdlib.h>
# include <time.h>


int subset[510] ;
int a[510] ;
int sum[3] ;
int n ;
int max_out ;


int random()
{
	int i ;
	sum[0] = sum[1] = sum[2] = 0 ;
	for (i = 0 ; i < n ; i++)
	{
		max_out = i ;
		subset[i] = rand() % 3 ;
		sum[subset[i]] += a[i] ;
		if (sum[0] == sum[1] && sum[0] != 0 && sum[1] != 0)
			return 1 ;
	}
	return 0 ;
}


void Print()
{
	int i, flag ;
	for (i = 0, flag = 0 ; i <= max_out && i < n  ; i++)
	{
		if (subset[i] == 0)
		{
			if (flag == 0) flag = 1 ;
			else printf (" ") ;
			printf ("%d", a[i]) ;
		}
	}
	puts ("") ;
	for (i = 0, flag = 0 ; i <= max_out && i < n ; i++)
	{
		if (subset[i] == 1)
		{
			if (flag == 0) flag = 1 ;
			else printf (" ") ;
			printf ("%d", a[i]) ;
		}
	}
	puts ("") ;
}


int main ()
{
	int T , i, nCase = 1 ;
	int cnt ;
	
	freopen ("C-small-attempt0 (1).in", "r", stdin) ;
	freopen ("cout.out", "w", stdout) ;
	
	srand(time(0)) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d", &n) ;
		for (i = 0 ; i < n ; i++)
			scanf ("%d", &a[i]) ;
		cnt = 100000 ;
		printf ("Case #%d:\n", nCase++) ;
		while(cnt--)
		{
			if (random())
			{
				Print() ;
				break ;
			}
		}
		if (cnt == -1)
		{
			puts ("Impossible") ;
		}
	}
	return 0 ;
}
