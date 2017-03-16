#include <iostream>
using namespace std;
typedef long long ll;
int main( void )
{
  ios::sync_with_stdio( false );
  int T, N, J;
  cin >> T;
  cin >> N >> J;
  int cnt=0;
  cout << "Case #1:" << endl;
  for( ll i=0; i<(1LL<<14); i++ ){
    ll d = (1LL<<15) | (i<<1) | 1;
    bool f = true;
    ll r[11];
    for( int j=2; j<=10; j++ ){
      ll v = 0, m = 1, dd = d;
      while( dd > 0 ){
        v += (dd&1) * m;
        m *= j;
        dd >>= 1;
      }
      if( v % 2 == 0 ){
        r[j] = 2;
        continue;
      }
      bool ff=false;
      for( ll p=3; p*p<=v; p+=2 ){
        if( v % p == 0 ){
          r[j] = p;
          ff = true;
          break;
        }
      }
      if( !ff ){ f = false; break; }
    }
    if( !f ) continue;
    for( int j=0; j<N/16; j++ ){
      for( int k=15; k>=0; k-- ){
        cout << (int)((d&(1<<k))?1:0);
      }
    }
    for( int j=2; j<=10; j++ ){
      cout << " " << r[j];
    }
    cout << endl;
    cnt++;
    if( cnt == J ) break;
  }
}
