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
const int N = 37;
int p[N][N];
int mid[N];
char s[1000007];
int to[N], from[N];
int appear[N];
const ll mod = 1e9 + 7;
int jc[1007];
bool vis[N];
bool dfs( int v )
{
  if( vis[v] )
    return false;
  vis[v] = true;
  for( int i = 0; i <= 'z' - 'a'; ++i )
    if( i != v && p[v][i] )
      {
	// cout << (char)( 'a' + i ) << endl;
	if( !dfs(i) )
	  return false;
      }
  return true;
}
int mulM( int a, int b)
{
  return ( (ll)a * (ll)b ) % mod;
}
int main()
{
  jc[0] = 1;
  for( int i = 1; i < 1007; ++i )
    jc[i] = mulM( jc[ i - 1 ], i);
  int T;
  scanf("%d", &T);
  for( int t = 1; t <= T; ++t)
    {
      int n;
      scanf("%d", &n);
      memset(p, 0, sizeof(p));
      memset(mid, 0, sizeof(mid) );
      memset( to, -1, sizeof(to) );
      memset( from, -1, sizeof(from) );
      memset( appear, 0, sizeof( appear) );
      bool ok = true;
      for( int i = 0; i < n; ++i )
	{
	  scanf("%s", s);
	  int j = 0;
	  appear[ s[0] - 'a' ] = 1;
	  for( ; s[j] && s[0] == s[j]; ++j )
	    ;
	  if( s[j] )
	    {
	      int k = j;
	      for( ; s[k]; ++k )
		appear[ s[k] - 'a' ] = 1;
	      --k;
	      int l = k;
	      for( ; l >= j && s[l] == s[k]; --l )
		;
	      for( ; l >= j; )
		{
		  ++mid[ s[l] - 'a' ];
		  for( char tmp = s[l]; l >= j && s[l] == tmp; --l )
		    ;
		}
	      if( s[0] == s[k] )
		ok = false;
	      ++p[ s[0] - 'a' ][ s[k] - 'a' ];
	    }
	  else
	    {
	      ++p[ s[0] - 'a' ][ s[0] - 'a' ];
	    }
	}
      for( int i = 0; ok && i < 'z' - 'a' + 1; ++i )
	{
	  int cnt1(0), cnt2(0);
	  for( int j = 0; ok && j < 'z' - 'a' + 1; ++j )
	    if( i != j )
	      {
		cnt1 += p[i][j];
		if( p[i][j] )
		  to[i] = j;
		cnt2 += p[j][i];
		if( p[j][i] )
		  from[i] = j;
	      }
	  if( cnt1 > 1 || cnt2 > 1)
	    ok = false;
	}
      for( int i = 0; ok && i < 'z' - 'a' + 1; ++i )
	if( mid[i] )
	  {
	    if( mid[i] > 1 )
	      ok = false;
	    else
	      for( int j = 0; j < 'z' - 'a' + 1; ++j )
		if( p[i][j] || p[j][i] )
		  ok = false;
	  }
      int ans(0);
      if( ok )
	{
	  ans = 1;
	  for( int i = 0; i <= 'z' - 'a'; ++i )
	    ans = mulM( ans, jc[ p[i][i] ] );
	  // int cnt(0);
	  // for( int i = 0; i <= 'z' - 'a'; ++i )
	  //   if( from[i] < 0 )
	  //     {
	  // 	for( int j = 0; j <= 'z' - 'a'; ++j )
	  // 	  if( p[i][j] || p[j][i] )
	  // 	    {
	  // 	      ++cnt;
	  // 	      break;
	  // 	    }
	  //     }
	  // ans = mulM( ans, jc[cnt] );
	  memset( vis, 0, sizeof(vis) );
	  int cnt(0);
	  for( int i = 0; i <= 'z' - 'a'; ++i )
	    if( !vis[i] && appear[i] && 0 == mid[i] && from[i] < 0)
	      {
		// cout << (char)('a' + i );
		if( !dfs(i) )
		  ok = false;
		else ++cnt;
	      }
	  for( int i = 0; i <= 'z' - 'a'; ++i )
	    if( !vis[i] && appear[i] && 0 == mid[i] )
	      ok = false;
	  if( !ok )
	    ans = 0;
	  else ans = mulM( ans, jc[cnt] );
	}
      printf("Case #%d: %d\n", t, ans);
    }
  return 0;
}
