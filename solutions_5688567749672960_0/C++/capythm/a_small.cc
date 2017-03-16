#include <iostream>
using namespace std;
int d[1000005];
int reverse( int n ){
  int ret = 0;
  while( n > 0 ){
    ret = ret*10 + (n%10);
    n /= 10;
  }
  return ret;
}
int main( void )
{
  d[1] = 1;
  for( int i=1; i<=1000000; i++ ){
    if( d[i+1] == 0 ){
      d[i+1] = d[i] + 1;
    } else {
      d[i+1] = min( d[i]+1, d[i+1] );
    }
    int f = reverse( i );
    if( d[f] == 0 ){
      d[f] = d[i] + 1;
    } else {
      d[f] = min( d[i]+1, d[f] );
    }
  }
  int T;
  cin >> T;
  for( int ti=1; ti<=T; ti++ ){
    int N;
    cin >> N;
    cout << "Case #" << ti << ": " << d[N] << endl;
  }
}
