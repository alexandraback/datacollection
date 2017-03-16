# include <stdio.h>


#define FOR(i,a,b) for (i = a ;i < b ; i++)


char g[5][5] ;
int flag ;


int check(char ch)
{
	int i, j, col[4] = {0}, row[4] = {0} ;
	int cc = 0, dd = 0;
	FOR(i,0,4){
		if(g[i][i]==ch || g[i][i]=='T') cc++ ;
		if(g[i][3-i]==ch || g[i][3-i]=='T') dd++ ;
		FOR(j,0,4)
		{
			if (g[i][j]==ch||g[i][j]=='T') row[i]++ ;
			if (g[j][i]==ch||g[j][i]=='T') col[i]++ ;
		}
	}
	FOR(i,0,4) if (row[i]==4 || col[i]==4) return 1 ;
	if (cc==4 || dd==4) return 1 ;
	return 0 ;
}


int gao()
{
	int i, j, flag = 0 ;
	FOR(i,0,4) FOR(j,0,4) flag+=(g[i][j]=='.') ;
	if (check('X')) return 0 ;
	if (check('O')) return 1 ;
	if (flag==0) return 2 ;
	return 3 ;
}


int main ()
{
	int T, i, nCase = 1 ;
	
	freopen ("A-small-attempt0.in", "r", stdin) ;
	freopen ("A-small-attempt0.txt", "w", stdout) ;
	
	char result[][50] = {	"X won", "O won", "Draw", 
							"Game has not completed"} ;
	scanf ("%d", &T) ;
	while (T--)
	{
		for (i = 0 ; i < 4 ; i++)
			scanf ("%s", g[i]) ;
		printf ("Case #%d: %s\n", nCase++,
								result[gao()]) ;
	}
	return 0 ;
}
