#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long llint;

const int MAXN = 105;

llint a[MAXN], b[MAXN];
int A[MAXN], B[MAXN];

llint dp[MAXN][MAXN];

int main( void ) {
  int t;
  scanf( "%d", &t );
  for( int c = 1; c <= t; ++c ) {
    int n, m;
    scanf( "%d %d", &n, &m );
    for( int i = 0; i < n; ++i )
      scanf( "%lld %d", a+i, A+i );
    for( int i = 0; i < m; ++i )
      scanf( "%lld %d", b+i, B+i );
    
    memset( dp, 0, sizeof( dp ) );
    for( int i = 0; i <= n; ++i )
      for( int j = 0; j <= m; ++j ) {
        dp[i+1][j] = max( dp[i+1][j], dp[i][j] );
        dp[i][j+1] = max( dp[i][j+1], dp[i][j] );
        if( A[i] != B[j] ) continue;

        llint s1 = 0;
        for( int l = i; l < n; ++l )
          if( A[l] == A[i] ) {
            s1 += a[l];
            llint s2 = 0;
            for( int k = j; k < m; ++k )
              if( B[j] == B[k] ) {
                s2 += b[k];
                dp[l+1][k+1] = max( dp[l+1][k+1], dp[i][j] + min(s1,s2) );
              }
          }
      }
    printf( "Case #%d: %lld\n", c, dp[n][m] );
  }
  return 0;
}
