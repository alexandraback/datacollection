#include <cstdio>
#include <algorithm>
#include <vector>

#define MAXN 1000
#define pb push_back

using namespace std;

int F[ MAXN + 1 ];
int A[ MAXN + 1 ];

int main( void ) {
  int T;
  freopen("Csmall.in","rt",stdin);
  freopen("Csmall.out","wt",stdout);
  scanf("%d", &T );
  for( int t = 1; t <= T; t++ ) {
    int N, ans = 0;
    scanf("%d", &N );
    for( int i = 0; i < N; i++ ) {
      scanf("%d", &F[ i ] );
      F[ i ]--;
      A[ i ] = i;
    }
    do {
      int maxim = 0;
      for( int i = 0; i < N; i++ ) {
        bool status = true;
        int B[ i + 1 ];
        for( int j = 0; j <= i; j++ ) B[ j ] = A[ j ];
        int n = i + 1;
        for( int j = 0; j <= i; j++ ) {
          if( F[ B[ j ] ] != B[ ( j + 1 ) % n ] && F[ B[ j ] ] != B[ ( j - 1 + n ) % n ] ) status = false;
        }
        if( status ) maxim = i + 1;
      }
      ans = max( ans, maxim );
    } while( next_permutation( A, A + N ) );
    printf("Case #%d: %d\n", t, ans );
  }
  return 0;
}
