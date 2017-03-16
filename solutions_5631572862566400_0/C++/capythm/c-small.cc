#include <iostream>
#include <algorithm>
using namespace std;
int b[11];
int N;
int solve(){
  int d[10];
  int ret = 2;
  for( int i=0; i<N; i++ ) d[i] = i+1;
  do {
    for( int i=ret+1; i<=N; i++ ){
      bool f = true;
      for( int j=0; j<i; j++ ){
        if( b[d[j]] == d[(j+1)%i] || b[d[j]] == d[(j+i-1)%i] ){
        } else {
          f = false;
          break;
        }
      }
      if( f ) ret=i;
    }
  } while( next_permutation( d, d+N ) );
  return ret;
}
int main( void )
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> N;
    for( int i=1; i<=N; i++ ){
      cin >> b[i];
    }
    int ret = solve();
    cout << "Case #" << testcase << ": " << ret << endl;
  }
}
