#include <cstdio>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define MAXN 10

using namespace std;

typedef pair< int, int > pii;

vector< int > G[ MAXN + 1 ];

void generate_graph( int bitmask, int B ) {
  for( int i = 0; i <= MAXN; i++ ) G[ i ].clear();
  int i = 1, j = 2;
  for( int bit = 0; bit < B * ( B - 1 ) / 2; bit++ ) {
    if( bitmask & ( 1 << bit ) ) {
      G[ i ].pb( j );
    }
    j++;
    if( ( j - 1 ) % B == 0 ) {
      i++;
      j = i + 1;
    }
    if( i == B ) break;
  }
}

int find_ways( int B ) {
  int dp[ MAXN + 1 ] = { 0 };
  dp[ 1 ] = 1;
  for( int i = 1; i <= B; i++ ) {
    for( int j = 0; j < G[ i ].size(); j++ ) {
      int v = G[ i ][ j ];
      dp[ v ] += dp[ i ];
    }
  }
  return dp[ B ];
}

void print_graph( int B ) {
  int M[ MAXN + 1 ][ MAXN + 1 ] = { 0 };
  for( int i = 1; i <= B; i++ ) {
    for( int j = 0; j < G[ i ].size(); j++ ) {
      int v = G[ i ][ j ];
      M[ i ][ v ] = true;
    }
  }
  for( int i = 1; i <= B; i++ ) {
    for( int j = 1; j <= B; j++ ) {
      printf("%d", M[ i ][ j ] );
    }
    printf("\n");
  }
}

int main( void ) {
  int T;
  freopen("Bsmall.in","rt",stdin);
  freopen("Bsmall.out","wt",stdout);
  scanf("%d", &T );
  for( int t = 1; t <= T; t++ ) {
    int B, M, status = 0;
    scanf("%d%d", &B, &M );
    printf("Case #%d: ", t );
    for( int bit = 0; bit < ( 1 << ( B * ( B - 1 ) / 2 ) ); bit++ ) {
      generate_graph( bit, B );
      int ways = find_ways( B );
      if( ways == M ) {
        status = true;
        printf("POSSIBLE\n");
        print_graph( B );
        break;
      }
    }
    if( !status ) printf("IMPOSSIBLE\n");
  }
  return 0;
}
