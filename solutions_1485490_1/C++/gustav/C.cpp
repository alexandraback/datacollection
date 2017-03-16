#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAX 105

typedef long long llint;

int T, N, M;
llint a[ MAX ]; int A[ MAX ];
llint b[ MAX ]; int B[ MAX ];

llint dp[ MAX ][ MAX ];

llint solve( int n, int m ) {
  if( n >= N || m >= M ) return 0;

  llint &ref = dp[n][m];
  if( ref >= 0 ) return ref;

  ref = max( solve( n + 1, m ), solve( n, m + 1 ) );

  llint now = a[n];
  llint produce = 0;

  for( int i = m; i < M; ++i ) {
    if( B[i] == A[n] ) {
      llint now_produce = min( now, b[i] );
      llint left = b[i] - now_produce;

      produce += now_produce;
      now -= now_produce;

      ref = max( ref, solve( n + 1, i + 1 ) + produce );

      while( now == 0 ) {
	++n;
	while( n < N && A[n] != B[i] ) ++n;
	if( n == N ) break;

	now = a[n];
	now_produce = min( now, left );

	produce += now_produce;
	now -= now_produce;
	left -= now_produce;

	ref = max( ref, solve( n + 1, i + 1 ) + produce );
      }
    }
  }

  return ref;
}

int main( void )
{
  scanf( "%d", &T );

  for( int tc = 1; tc <= T; ++tc ) {
    scanf( "%d%d", &N, &M );

    for( int i = 0; i < N; ++i ) {
      scanf( "%lld%d", &a[i], &A[i] );
    }

    for( int i = 0; i < M; ++i ) {
      scanf( "%lld%d", &b[i], &B[i] );
    }

    memset( dp, -1, sizeof dp );

    printf( "Case #%d: %lld\n", tc, solve( 0, 0 ) );
  }

  return 0;
}
