#include <cstdio>
#include <cstring>

#include <bitset>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1005

int T, N, M, f;

bitset< MAXN > b[ MAXN ];
int bio[ MAXN ];
bool sol;

vector< int > g[ MAXN ];

void dfs( int n ) {
  if( bio[n] ) return;
  bio[n] = 1;

  for( int i = 0; i < g[n].size(); ++i ) {
    dfs( g[n][i] );
  }

  b[n].reset();

  for( int i = 0; i < g[n].size(); ++i ) {
    if( ( b[n] & b[g[n][i]] ).any() ) {
      sol = true;
      return;
    }
    if( b[n][g[n][i]] ) {
      sol = true;
      return;
    }
    else {
      b[n][g[n][i]] = 1;
    }
    b[n] |= b[g[n][i]];
  }
}

int main( void )
{
  scanf( "%d", &T );

  for( int tc = 1; tc <= T; ++tc ) {
    scanf( "%d", &N );

    for( int i = 0; i < N; ++i ) {
      g[i].clear();
      scanf( "%d", &M );

      for( int j = 0; j < M; ++j ) {
	scanf( "%d", &f ); --f;
	g[i].push_back( f );
      }
    }

    sol = false;
    memset( bio, 0, sizeof bio );

    for( int i = 0; i < N; ++i ) {
      if( bio[i] ) continue;
      dfs( i );
    }

    printf( "Case #%d: %s\n", tc, ( sol ? "Yes" : "No" ) );
  }

  return 0;
}
