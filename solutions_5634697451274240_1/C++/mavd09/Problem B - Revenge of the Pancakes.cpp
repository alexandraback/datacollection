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

const int MAX = int( 1e7 );
const int MOD = int( 1e9+7 );
const int oo  = INT_MAX;

int main( ) {

  #ifdef LOCAL
    freopen( "B-large.in", "r", stdin );
    freopen( "B-large.out", "w", stdout );
  #endif // LOCAL

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int nTest;
  cin >> nTest;

  for( int tc = 1; nTest--; tc++ ) {
    string s; cin >> s;
    int n = int( s.size( ) );
    string ns = string( 1, s[ 0 ] );
    for( int i = 1; i < n; i++ )
      if( s[ i ] != ns.back( ) )
        ns.PB( s[ i ] );
    int ans = int( ns.size( ) );
    if( ns.back( ) == '+' )
      ans--;
    cout << "Case #" << tc << ": " << ans << "\n";
  }

  return 0;
}
