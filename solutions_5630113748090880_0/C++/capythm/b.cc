#include <iostream>
#include <algorithm>
using namespace std;
int d[2501];
int main( void )
{
  ios::sync_with_stdio(false);
  int T, N, h;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> N;
    for( int i=1; i<=2500; i++ ){
      d[i] = 0;
    }
    for( int i=0; i<2*N-1; i++ ){
      for( int j=0; j<N; j++ ){
        cin >> h;
        d[h]++;
      }
    }
    cout << "Case #" << testcase << ":";
    for( int i=1; i<=2500; i++ ){
      if( d[i] % 2 == 1 ){
        cout << " " << i;
      }
    }
    cout << endl;
  }
}
