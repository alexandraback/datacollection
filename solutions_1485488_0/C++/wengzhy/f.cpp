#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int x,y;
	node( int xx = 0, int yy = 0 )
	{
		x = xx;
		y = yy;
	}
};
int t[1000][1000];
bool u[1000][1000];
int c[1000][1000];
int f[1000][1000];
queue<node> q;
int d[4][2];
void init()
{
	d[0][0] = 1;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 1;
	d[2][0] = -1;
	d[2][1] = 0;
	d[3][0] = 0;
	d[3][1] = -1;
}
int main()
{
	int cas, ca = 0;
	int n,m,h;
	init();
	scanf( "%d", &cas );
	while ( cas -- )
	{
		scanf( "%d%d%d", &h, &n, &m );
		for ( int i = 1; i <= n; i++ )
			for ( int j = 1; j <= m; j++ )
				scanf( "%d", &c[i][j] );
	
		for ( int i = 1; i <= n; i++ )
			for ( int j = 1; j <= m; j++ )
				scanf( "%d", &f[i][j] );

		memset( u, false, sizeof( u ));
		memset( t, -1, sizeof( t ));
		while ( !q.empty() ) q.pop();
		u[1][1] = true;
		t[1][1] = 0;
		q.push( node(1,1));
		while ( !q.empty() ) 
		{
			if ( t[n][m] == 0 ) break;
			node x = q.front();
//			printf( "%d %d\n",x.x,x.y);
//			printf( "%d\n",t[x.x][x.y] );
			q.pop();
			u[x.x][x.y] = false;
			for ( int i = 0; i < 4; i++ )
			{
				if ( x.x+d[i][0] >= 1 && x.x+d[i][0] <= n && x.y+d[i][1] >= 1 && x.y+d[i][1] <= m )
				{
					int x1 = x.x+d[i][0];
					int y1 = x.y+d[i][1];
					if ( c[x.x][x.y] - f[x1][y1] >= 50  )
					if ( c[x1][y1] - f[x.x][x.y] >= 50 )
					if ( c[x1][y1] - f[x1][y1] >= 50 )
					{
//						printf( "%d %d\n",x1,y1);
						int h1 = h - t[x.x][x.y] ;
						if ( c[x1][y1] - h1 >= 50 )
						{
//							printf("1\n");
//							double tt;
							int tt;
							if ( h1 -  f[x.x][x.y] >= 20 )
							tt = 10;
							else tt = 100;
							if ( t[x.x][x.y] == 0 ) tt = 0;
							if ( t[x1][y1] == -1 || t[x.x][x.y] + tt < t[x1][y1] )
							{
								if ( u[x1][y1] == false )
								{
									q.push( node(x1, y1 ) );
									u[x1][y1] = true;
									t[x1][y1] = t[x.x][x.y] + tt;
								}
								else t[x1][y1] = t[x.x][x.y] + tt;
							}
						}
						else
						{
//							printf("2\n");
							int tt = 50 -  c[x1][y1] + h1 ;
							h1 = c[x1][y1] - 50;
							if ( h1 -  f[x.x][x.y] >= 20 )
							tt = tt + 10;
							else tt = tt + 100;
							if (  t[x1][y1] == -1 || t[x.x][x.y] + tt < t[x1][y1] )
							{
								if ( u[x1][y1] == false )
								{
									q.push( node(x1, y1 ) );
									u[x1][y1] = true;
									t[x1][y1] = t[x.x][x.y] + tt;
//									printf( "%d %d\n",x1,y1);
//									printf( "%d\n", t[x1][y1] );
								}
								else t[x1][y1] = t[x.x][x.y] + tt;
							}
						}
					}
				}
			}

		}
		ca++;
		printf( "Case #%d: ",ca);
		printf( "%.1lf\n", double(t[n][m])/10 );
		
	}
	
	return 0;
}