# include <stdio.h>
# include <string.h>


char name[110] ;
int len, n ;

int vol(char ch)
{
	char s[] = "aeiou" ;
	int i ;
	for (i = 0 ; i < 5 ; i++)
		if (ch == s[i]) return 1 ;
	return 0 ;
}


int max(int a, int b){return a>b?a:b;}


int calc(int s, int e)
{
	int flag = 0, i ;
	int ans = 0 ;
	int pp = 0 ;
	//printf ("%d, %d\n", s, e) ;
	for (i = s ; i <= e ; i++)
	{
		if (!vol(name[i])){
			pp ++ ;
			ans = max(ans, pp) ;
		}
		else
		{
			pp = 0 ;
		}
	}
	return ans ;
}


int main ()
{
	int T, nCase = 1 ;
	int ans, i, j ;
	freopen ("A-small-attempt0.in", "r", stdin) ;
	freopen ("A-small-attempt0.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%s %d", name, &n) ;
		len = strlen(name) ;
		ans = 0 ;
		for (i = 0 ; i < len ; i++)
			for (j = i ; j < len ; j++)
				if (calc(i, j)>=n) ans++ ;
				
		printf ("Case #%d: %d\n", nCase++, ans) ;
	}
	return 0 ;
}
