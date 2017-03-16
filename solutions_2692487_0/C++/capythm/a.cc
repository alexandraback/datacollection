#include <iostream>
#include <algorithm>
using namespace std;
int m[105];
int main( void )
{
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    int A, N;
    cin >> A >> N;
    for( int i=0; i<N; i++ )
      cin >> m[i];
    sort( m, m+N );
    int ret = N;
    int d = 0;
    if( A == 1 ){
      goto END;
    }
    for( int i=0; i<N; i++ ){
      if( m[i] < A ){
        A += m[i];
      } else {
        while( A <= m[i] ){
          A += A-1;
          d++;
        }
        A += m[i];
      }
      ret = min( d+(N-i-1), ret );
      //cout << ret << ' ' << A << ' ' << m[i] << ' ' << d << endl;
    }
END:
    cout << "Case #" << testcase << ": " << ret << endl;
  }
  return 0;
}
