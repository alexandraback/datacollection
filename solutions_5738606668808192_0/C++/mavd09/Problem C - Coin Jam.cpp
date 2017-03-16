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
typedef vector< vll >       vvll;
typedef vector< vvll >      vvvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;

const int MOD = ll( 2 );
const int oo  = INT_MAX;

const int MIN_BASE = 2;
const int MAX_BASE = 10;

const int LENGTH_COINJAM = 16;
const int TOTAL_COINJAM  = 50;

const ll MAX = ll( 1e3 );

vll sieve( ) {
  vll primes;
  bitset< MAX > bs; bs.set( );
  bs[ 0 ] = bs[ 1 ] = 0;
  for( ll i = 2; i < MAX; i++ ) {
    if( bs[ i ] ) {
      primes.PB( i );
      for( ll j = i*i; j < MAX; j += i )
        bs[ j ] = 0;
    }
  }
  return primes;
}

int main( ) {

  #ifdef LOCAL
    //freopen( "input", "r", stdin );
    freopen( "output", "w", stdout );
  #endif // LOCAL

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  vll primes = sieve( );
  int tp = int( primes.size( ) );
  vvvll table( MAX_BASE+1, vvll( LENGTH_COINJAM, vll( tp ) ) );

  for( ll b = MIN_BASE; b <= MAX_BASE; b++ ) {
    for( ll l = 0; l < LENGTH_COINJAM; l++ ) {
      for( int i = 0; i < tp; i++ ) {
        if( l == 0 )
          table[ b ][ l ][ i ] = 1LL;
        else
          table[ b ][ l ][ i ] = ( table[ b ][ l-1 ][ i ]*b )%primes[ i ];
      }
    }
  }

  cout << "Case #1:\n";
  for( ll mask = ( 1LL<<( LENGTH_COINJAM-1 ) )+1, j = 0; mask < ( 1LL<<LENGTH_COINJAM ) && j < TOTAL_COINJAM; mask += 2LL ) {
    vll ans;
    bool ok = true;
    for( ll b = MIN_BASE; b <= MAX_BASE; b++ ) {
      ll correct = -1;
      for( int i = 0; i < tp; i++ ) {
        ll cur = 0;
        for( ll l = 0; l < LENGTH_COINJAM; l++ ) {
          if( ( mask>>l )&1 )
            cur = ( cur+table[ b ][ l ][ i ] )%primes[ i ];
        }
        if( cur == 0 ) {
          correct = primes[ i ];
          break;
        }
      }
      if( correct != -1 )
        ans.PB( correct );
      else {
        ok = false;
        break;
      }
    }
    if( ok ) {
      for( ll l = LENGTH_COINJAM-1; l >= 0; l-- )
        cout << ( ( mask>>l )&1 );
      for( auto& e : ans )
        cout << " " << e;
      cout << "\n";
      j++;
    }
  }

  return 0;
}
