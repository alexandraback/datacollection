#include <iostream>
#include <algorithm>
using namespace std;
int main( void )
{
  int T,N,M,K,ret;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> N >> M >> K;
    if( N > M ) swap( N,M );
    ret = 2*(N+M)-4;
    if( ret < 1 ) ret = 1;
    while( 1 ){
      if( N <= 2 ){
        ret = min( ret, K );
        break;
      }
      for( int i=0; i<N-2; i++ ){
        int d = N * M - 4 - i*2;
        if( d < K ){
          int rem = K - d;
          ret = min( ret, 2 * (N-2) + 2 * (M-2) - i + rem );
          goto L1;
        }
        ret = 2*(N-2) + 2*(M-2) - i;
      }
      M--;
      if( N > M ) swap( N,M );
    }
L1:
    cout << "Case #" << testcase << ": " << ret << endl;
  }
  return 0;
}
