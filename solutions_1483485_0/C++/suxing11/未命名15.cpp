# include <stdio.h>


char str[110] ;
char tab[] = "yhesocvxduiglbkrztnwjpfmaq" ;
//char tab[] = "yhesocvxduiglbkrqtnwjpfmaz" ;
//char tab[] = "yhesocvxduiglbkrztnwjpfmaq" ;


int main ()
{
	int i, T, nCase = 1 ;
	scanf ("%d%*c", &T) ;
//	freopen ("A-small-attempt0.in", "r", stdin) ;
	freopen ("out.txt", "w", stdout) ;
	
	while (T--)
	{
		gets (str) ;
		printf ("Case #%d: ", nCase++) ;
		for (i = 0 ; str[i] ; i++)
			if (str[i] >= 'a'&& str[i] <= 'z')
				putchar(tab[str[i]-'a']) ;
			else putchar (str[i]) ;
		printf ("\n") ;
	}
	return 0 ;
}
