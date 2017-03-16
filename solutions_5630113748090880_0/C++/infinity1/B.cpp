#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define pb push_back

using namespace std;

int H[ 2510 ];

vector< int > V;

int main( void ) {
  int T;
  freopen("B.in","rt",stdin);
  freopen("B.out","wt",stdout);
  scanf("%d", &T );
  for( int t = 1; t <= T; t++ ) {
    int n;
    scanf("%d", &n );
    memset( H, 0, sizeof( H ));
    for( int i = 0; i < 2*n - 1; i++ ) {
      for( int j = 0; j < n; j++ ) {
        int h;
        scanf("%d", &h );
        H[ h ]++;
      }
    }
    for( int i = 1; i < 2510; i++ ) {
      if( H[ i ] % 2 == 1 ) V.pb( i );
    }
    sort( V.begin(), V.end() );
    printf("Case #%d:", t );
    for( int i = 0; i < V.size(); i++ ) {
      printf(" %d", V[ i ] );
    }
    printf("\n");
    V.clear();
  }
  return 0;
}
