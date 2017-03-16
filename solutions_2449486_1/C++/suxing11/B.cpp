# include <stdio.h>


#define IN "B-large.in"
#define SWAP(a,b) (t=a,a=b,b=t)
#define FOR(i,a,b) for(i = a ; i < b ; i++)


int g[110][110] , gg[110][110] ;
int row[110],col[110] ;
int h[220][3] ;


int min(int a, int b){return a<b?a:b;}
int max(int a, int b){return a>b?a:b;}

int main()
{
	int T, nCase = 1 ;
	int ROW=0,COL=1 ;
	int flag, n, m, i, j, cc, t ;
	freopen (IN, "r", stdin) ;
	freopen ("B_out.txt", "w", stdout) ;
	scanf ("%d", &T) ;
	while (T--)
	{
		scanf ("%d%d", &n, &m) ;
		FOR(i,0,n) row[i]=0 ;
		FOR(j,0,m) col[j]=0 ;
		FOR(i,0,n)FOR(j,0,m)
			scanf("%d",&g[i][j]),
			row[i] = max(row[i], g[i][j]),
			col[j] = max(col[j], g[i][j]) ;
		cc = 0 ;
		FOR(i,0,n) h[cc][0]=row[i],h[cc][1]=i,h[cc][2]=ROW,cc++ ;
		FOR(i,0,m) h[cc][0]=col[i],h[cc][1]=i,h[cc][2]=COL,cc++ ;
		FOR(i,0,cc) FOR(j,0,i) if(h[i][0]<h[j][0])
			SWAP(h[i][0],h[j][0]),
			SWAP(h[i][1],h[j][1]),
			SWAP(h[i][2],h[j][2]) ;
		FOR(i,0,n) FOR(j,0,m) gg[i][j] = 100 ;
		for (i = cc-1 ; i >= 0 ; i--){
			if (h[i][2]==ROW)
				for (j = 0 ; j < m ; j++) gg[h[i][1]][j]=h[i][0] ;
			else
				for (j = 0 ; j < n ; j++) gg[j][h[i][1]] = h[i][0] ;
		}
		flag = 0 ;
		FOR(i,0,n) FOR(j,0,m) if (g[i][j] != gg[i][j]) flag = 1 ;
		printf ("Case #%d: %s\n", nCase++, flag?"NO":"YES") ;
	}
	return 0 ;
}
