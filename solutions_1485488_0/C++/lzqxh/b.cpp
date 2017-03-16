//By Lin
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 105

using namespace std; 
const	int mm[4][2] = {0,1,0,-1,1,0,-1,0};

struct	Node{
	int c, f; 
}data[maxn][maxn];
int		n,m,hh;
double t[maxn][maxn]; 
int		mark[maxn][maxn]; 

int		main()
{
	int cas , tt = 0; 
	scanf("%d", &cas ); 
	while ( cas -- ) 
	{
		scanf("%d%d%d", &hh , &n, &m );
		for (int i = 1; i<=n; i++) 
			for (int j = 1; j<=m; j++) scanf("%d" , &data[i][j].c ); 
		for (int i = 1; i<=n; i++) 
			for (int j = 1; j<=m; j++) scanf("%d" , &data[i][j].f ); 
		memset( mark , 0 , sizeof(mark) );
		mark[1][1] = 2; 
		t[1][1] = 0; 
		while ( true ) 
		{
			int g = -1 , h = -1; 
			for (int i = 1; i<=n; i++) 
				for (int j = 1; j<=m; j++) 
					if ( mark[i][j] == 2 ) 
						if ( g == -1 ) g = i , h = j; 
			if ( g == -1 ) break; 
			mark[g][h] = 1; 
			for (int i = 0; i<4; i++) 
			{
				int x = g+mm[i][0] , y = h+mm[i][1]; 
				if ( x < 1 || x > n || y < 1 || y > m || mark[x][y] == 1 ) continue; 
				if ( data[x][y].c - data[g][h].f < 50 || data[g][h].c - data[x][y].f < 50 || data[x][y].c - data[x][y].f < 50 ) continue; 
				if ( data[x][y].c - hh < 50 ) continue; 
				t[x][y] = 0; 
				mark[x][y] = 2; 
			}
		}
		while ( true ) 
		{
			int g = -1 , h = -1; 
			for (int i = 1; i<=n; i++) 
				for (int j = 1; j<=m; j++) 
					if ( mark[i][j] == 1 ) 
						if ( g == -1 || t[i][j] < t[g][h] ) g = i , h = j; 
			mark[g][h] = 2; 
			if ( g == n && h == m ) break; 
			for (int i = 0; i<4; i++) 
			{
				int x = g+mm[i][0] , y = h+mm[i][1]; 
				if ( x < 1 || x > n || y < 1 || y > m || mark[x][y] == 2 ) continue; 
				if ( data[x][y].c - data[g][h].f < 50 || data[g][h].c - data[x][y].f < 50 || data[x][y].c - data[x][y].f < 50 ) continue; 

				double k = max((hh-data[x][y].c+50)*1.0/10,t[g][h]); 
				if ( mark[x][y] == 0 || t[x][y] > k+10 )  t[x][y] = k + 10; 
				if ( hh-k*10 >= data[g][h].f + 20 ) 
					if ( mark[x][y] == 0 || t[x][y] > k+1 )  t[x][y] = k + 1; 
				mark[x][y] = 1; 
			}
		}
		printf("Case #%d: %.7f\n" , ++tt , t[n][m] ); 
	}
	return 0; 
}
