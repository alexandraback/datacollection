#include <iostream>
using namespace std;
typedef long long ll;
int main( void )
{
  ios::sync_with_stdio( false );
  int T;
  cin >> T;
  for( int testcase = 1; testcase <= T; testcase++ ){
    ll N, n;
    bool f[10];
    for( int i=0; i<10; i++ ) f[i] = false;
    cin >> N;
    if( N == 0 ){
      cout << "Case #" << testcase << ": INSOMNIA" << endl;
      continue;
    }
    for( ll i=1; ; i++ ){
      n = N * i;
      while( n > 0 ){
        f[n%10] = true;
        n /= 10;
      } 
      int g = true;
      for( int j=0; j<10; j++ ){
        g &= f[j];
      }
      if( g ){
        n = N * i;
        break;
      }
    }
    cout << "Case #" << testcase << ": " << n << endl;
  }
}
