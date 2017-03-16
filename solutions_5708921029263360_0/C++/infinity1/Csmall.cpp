#include <cstdio>
#include <algorithm>
#include <vector>

#define pb push_back

using namespace std;

struct combi {
  int X, Y, Z;
};

bool operator==( combi A, combi B ) {
  return A.X == B.X && A.Y == B.Y && A.Z == B.Z;
}

combi make_combi( int x, int y, int z ) {
  combi A;
  A.X = x;
  A.Y = y;
  A.Z = z;
  return A;
}

int K;
vector< combi > all, solution;

int main( void ) {
  int T;
  //freopen("Csmall.in","rt",stdin);
  //freopen("Csmall.out","wt",stdout);
  scanf("%d", &T );
  for( int t = 1; t <= T; t++ ) {
    int J, S, P;
    scanf("%d%d%d%d", &J, &P, &S, &K );
    all.clear();
    for( int i = 1; i <= J; i++ ) {
      for( int j = 1; j <= P; j++ ) {
        for( int k = 1; k <= S; k++ ) {
          all.pb( make_combi( i, j, k ) );
        }
      }
    }
    vector< combi > solution;
    for( int bit = 0; bit < ( 1 << ( J* S*P ) ); bit++ ) {
      vector< combi > current;
      int status = true;
      int nbits = __builtin_popcount(bit);
      if( J == 3 && S == 3 && P == 3 ) {
        if( K == 1 && nbits != 9 ) continue;
        else if( K == 2 && nbits != 18 ) continue;
        else if( K >= 3 && nbits != 27 ) continue;
      }
      if( nbits <= solution.size() ) continue;
      int A[ 4 ][ 4 ] = { 0 }, B[ 4 ][ 4 ] = { 0 }, C[ 4 ][ 4 ] = { 0 };
      for( int i = 0; i < J * S * P; i++ ) {
        if( bit & ( 1 << i ) ) {
          if( A[ all[ i ].X ][ all[ i ].Y ] == K || B[ all[ i ].X ][ all[ i ].Z ] == K || C[ all[ i ].Y ][ all[ i ].Z ] == K ) {
            status = false;
            break;
          } else {
            current.pb( all[ i ] );
            A[ all[ i ].X ][ all[ i ].Y ]++;
            B[ all[ i ].X ][ all[ i ].Z ]++;
            C[ all[ i ].Y ][ all[ i ].Z ]++;
          }
        }
      }
      if( status && current.size() > solution.size() ) solution = current;
    }
    printf("Case #%d: %d\n", t, ( int )solution.size() );
    for( int i = 0; i < solution.size(); i++ ) {
      printf("%d %d %d\n", solution[ i ].X, solution[ i ].Y, solution[ i ].Z );
    }
  }
  return 0;
}
