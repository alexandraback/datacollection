#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 51

using namespace std;

typedef unsigned long long llu;

int G[ MAXN + 1 ][ MAXN + 1 ];

int main( void ) {
  int T;
  freopen("B.in","rt",stdin);
  freopen("B.out","wt",stdout);
  scanf("%d", &T );
  for( int t = 1; t <= T; t++ ) {
    int B;
    llu M;
    memset( G, 0, sizeof( G ) );
    scanf("%d%llu", &B, &M );
    for( int i = 2; i <= B; i++ ) {
      for( int j = i + 1; j <= B; j++ ) {
        G[ i ][ j ] = 1;
      }
    }
    printf("Case #%d:", t);
    if( M >= ( 1 << B ) ) {
      printf(" IMPOSSIBLE\n");
      continue;
    }
    for( int i = 0; i <= B - 1 && M > 0; i++ ) {
      int b = M % 2LL;
      M /= 2LL;
      if( b > 0 ) G[ 1 ][ B - i ] = 1;
    }
    printf(" POSSIBLE\n");
    for( int i = 1; i <= B; i++ ) {
      for( int j = 1; j <= B; j++ ) {
        printf("%d", G[ i ][ j ] );
      }
      printf("\n");
    }
  }
  return 0;
}
