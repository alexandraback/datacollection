# include <stdio.h>


char TTT[10][10] ;


int fuck()
{
	int i, j, cc = 0 ;
	for (i = 0 ;i < 4 ; i++)
	{
		cc = 0 ;
		for (j = 0 ; j < 4 ; j++)
			if (TTT[i][j] == 'X' || TTT[i][j] == 'T') cc++ ;
		if (cc == 4) return 0 ;
	}
	for (j = 0 ; j < 4 ; j++)
	{
		cc = 0 ;
		for (i = 0 ; i < 4 ; i++)
			if (TTT[i][j] == 'X' || TTT[i][j] == 'T') cc++ ;
			if (cc == 4) return 0 ;
	}
	cc = 0 ;
	for (i = 0 ; i < 4 ; i++) if (TTT[i][i] == 'X' || TTT[i][i] == 'T')
		cc++ ;
	if (cc == 4) return 0 ;
	cc = 0 ;
	for (i = 0 ; i < 4 ; i++) if (TTT[i][3-i] == 'X' || TTT[i][3-i] == 'T')
		cc++ ;
	if (cc == 4) return 0 ;
	
	////////////////////////////
		for (i = 0 ;i < 4 ; i++)
	{
		cc = 0 ;
		for (j = 0 ; j < 4 ; j++)
			if (TTT[i][j] == 'O' || TTT[i][j] == 'T') cc++ ;
		if (cc == 4) return 1 ;
	}
	for (j = 0 ; j < 4 ; j++)
	{
		cc = 0 ;
		for (i = 0 ; i < 4 ; i++)
			if (TTT[i][j] == 'O' || TTT[i][j] == 'T') cc++ ;
			if (cc == 4) return 1 ;
	}
	cc = 0 ;
	for (i = 0 ; i < 4 ; i++) if (TTT[i][i] == 'O' || TTT[i][i] == 'T')
		cc++ ;
	if (cc == 4) return 1 ;
	cc = 0 ;
	for (i = 0 ; i < 4 ; i++) if (TTT[i][3-i] == 'O' || TTT[i][3-i] == 'T')
		cc++ ;
	if (cc == 4) return 1 ;
	
	///////////////////////
	for (i =0 ; i < 4 ; i++)
		for (j = 0 ; j < 4 ; j++)
			if (TTT[i][j] == '.') return 3;
	return 2 ;
	
}


int main ()
{
	int T, Case, i ;
	
	freopen ("A-small-attempt0.in", "r", stdin) ;
	freopen ("A-small-attempt0.out", "w", stdout) ;
	
	scanf ("%d", &T) ;
	for (Case = 1 ; Case <= T ; Case++)
	{
		
		for (i = 0 ; i < 4 ; i++)
			scanf ("%s", TTT[i]) ;
		int ans = fuck() ;
		printf ("Case #%d: ", Case) ;
		if (ans == 0) puts ("X won") ;
		else if (ans == 1) puts ("O won") ;
		else if (ans == 2) puts ("Draw") ;
		else puts("Game has not completed") ;
	}
	return 0 ;
}
