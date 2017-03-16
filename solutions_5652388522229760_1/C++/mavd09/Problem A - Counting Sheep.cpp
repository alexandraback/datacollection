#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef vector< bool >      vb;
typedef vector< double >    vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;

const int MAX = int( 1e6 );
const int MOD = int( 1e9+7 );
const int oo  = INT_MAX;

ll go( ll n ) {
  if( n == 0 )
    return -1;
  int used = 0;
  for( ll i = 1; ; i++ ) {
    ll tmp = i*n;
    while( tmp ) {
      int d = tmp%10LL;
      used |= ( 1<<d );
      tmp /= 10LL;
    }
    if( __builtin_popcount( used ) == 10 )
      return i*n;
  }
  return -1;
}

int main( ) {

  #ifdef LOCAL
    freopen( "A-large.in", "r", stdin );
    freopen( "A-large.out", "w", stdout );
  #endif // LOCAL

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int nTest;
  cin >> nTest;

  for( int tc = 1; nTest--; tc++ ) {
    ll n; cin >> n;
    cout << "Case #" << tc << ": ";
    ll ans = go( n );
    if( ans == -1 )
      cout << "INSOMNIA\n";
    else
      cout << ans << "\n";
  }

  return 0;
}
