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
    freopen( "D-small-attempt0.in", "r", stdin );
    freopen( "D-small-attempt0.out", "w", stdout );
  #endif // LOCAL

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int nTest;
  cin >> nTest;

  for( int tc = 1; nTest--; tc++ ) {
    ll k, c, s; cin >> k >> c >> s;
    cout << "Case #" << tc << ":";
    for( int i = 1; i <= k; i++ )
      cout << " " << i;
    cout << "\n";
  }

  return 0;
}
