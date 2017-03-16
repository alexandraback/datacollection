#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std ;
#define INF (int)1e9
int dx[] = {-1,1,0,0} ;
int dy[] = {0,0,-1,1} ;

#define MAXN 102
int H,a[MAXN][MAXN],b[MAXN][MAXN],n,m ;


int q[MAXN * MAXN * MAXN * 20] ;
double best[MAXN][MAXN][2] ;
int main()
{
 int runs ;
 cin >> runs ;
 for(int t = 1;t <= runs;t++)
 {
  cin >> H >> n >> m ;
  for(int i = 0;i < n;i++)
   for(int j = 0;j < m;j++)
    cin >> b[i][j] ;
  for(int i = 0;i < n;i++)
   for(int j = 0;j < m;j++)
    cin >> a[i][j] ;
  
  for(int i = 0;i < n;i++)
   for(int j = 0;j < m;j++)
    best[i][j][0] = best[i][j][1] = 1e9 ;
  
  int sz = 0 ;
  best[0][0][0] = 0 ;
  q[sz++] = 0 ; q[sz++] = 0 ; q[sz++] = 0 ;
  
  for(int i = 0;i < sz;i += 3)
  {
   int x = q[i],y = q[i + 1],waited = q[i + 2] ;
   double now = best[x][y][waited] ;

   double water = max(0.,H - now * 10) ;
   for(int j = 0;j < 4;j++)
   {
    int xx = x + dx[j],yy = y + dy[j] ;

    if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue ;
    if(b[xx][yy] - a[xx][yy] < 50) continue ;
    if(b[xx][yy] - a[x][y] < 50) continue ;
    if(b[x][y] - a[xx][yy] < 50) continue ;

    double wait = 0,diff = b[xx][yy] - max(water,0. + a[x][y]) ;
    if(diff < 50.0) wait = (50 - diff) / 10. ;

    double nlevel = water - 10 * wait ;
    double nbest = now + wait + (nlevel - a[x][y] >= 20 ? 1 : 10) ;
    int nwaited = waited == 0 && wait < 1e-9 ? 0 : 1 ;

    if(nwaited == 0) nbest = 0 ;

    if(nbest < best[xx][yy][nwaited] - 1e-9)
    {
     best[xx][yy][nwaited] = nbest ;
     q[sz++] = xx ; q[sz++] = yy ; q[sz++] = nwaited ;
    }
   }
  }
  double ret = min(best[n - 1][m - 1][0],best[n - 1][m - 1][1]) ;
  printf("Case #%d: %.9lf\n",t,ret) ;
 }
 return 0 ;
}
