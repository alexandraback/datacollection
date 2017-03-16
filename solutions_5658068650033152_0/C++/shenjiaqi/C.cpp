#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int p[27][27];
int cnt;
const int dir[4][2] = { { -1, 0 }, {1,0}, {0,1}, {0,-1} };
void dfs( int x, int y, int n, int m )
{
  p[x][y] = 2;
  ++cnt;
  for( int i = 0; i < 4; ++i )
    {
      int xx = x + dir[i][0];
      int yy = y + dir[i][1];
      if( xx >= 0 && xx < n && yy >= 0 && yy < m && p[xx][yy] == 0 )
	dfs( xx, yy, n, m);
    }
}
bool test(int n, int m, int fig, int num )
{
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < m; ++j )
      p[i][j] = ( ( 1 << ( i * m + j ) ) & fig ) ? 1 : 0;
  cnt = 0;
  for( int j = 0; j < m; ++j )
    {
      if( p[0][j] == 0 )
	{
	  dfs(0, j, n, m);
	  if( n * m - cnt < num )
	    return false;
	}
      if( p[n - 1][j] == 0 )
	{
	  dfs( n - 1, j, n, m );
	  if( n * m - cnt < num )
	    return false;
	}
    }
  for( int i = 0; i < n; ++i )
    {
      if( p[i][0] == 0 )
	{
	  dfs( i, 0, n, m );
	  if( n * m - cnt < num )
	    return false;
	}
      if( p[i][ m - 1 ] == 0 )
	{
	  dfs( i, m - 1, n, m );
	  if( n * m - cnt < num )
	    return false;
	}
    }
  // if( __builtin_popcount(fig) == 7 )
  //   {
  //     cout << cnt << ' ' << num << endl;
  //     for( int i = 0; i < n; ++i )
  // 	{
  // 	  for( int j = 0; j < m; ++j )
  // 	    cout << p[i][j] ;
  // 	  cout << endl;
  // 	}
  //   }
  return true;
}
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 1; t <= T; ++t)
    {
      int n, m, k;
      scanf("%d%d%d", &n, &m, &k);
      if( n < m )
	swap( n, m);
      int ans = k;
      for( int i = 1; i < ( 1 << ( n * m ) ); ++i )
	{
	  int tmp = __builtin_popcount(i);
	  if( tmp < ans && test(n, m, i, k) )
	    ans = tmp;
	}
      printf("Case #%d: %d\n", t, ans);
    }
  return 0;
}
