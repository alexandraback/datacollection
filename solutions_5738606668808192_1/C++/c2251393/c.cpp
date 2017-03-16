
// default code for competitive programming
// ver 3.1415 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(i, e) for( int i = 0 ; i < (e) ; i++ )
#define ITER(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define IOS ios_base::sync_with_stdio( 0 )
#define DEBUG 1
#define fst first
#define snd second
#define PB push_back
#ifdef ONLINE_JUDGE
#define FILE( fn ) \
    freopen(fn".in","r",stdin); \
    freopen(fn".out","w",stdout);
#else
#define FILE( fn )
#endif

#ifdef AKAI
#define debug( ... ) fprintf( stderr , __VA_ARGS__ )
#else
#define debug( ... )
#endif

using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef tuple<ll, int> tli;
typedef pair<int, int> pii;
typedef tuple<int, int> tii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);

// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

int _R( int& x ) { return scanf( "%d" , &x ); }
int _R( ll& x ) { return scanf( "%" PRId64 , &x ); }
int _R( double& x ) { return scanf( "%lf" , &x ); }
int _R( char* s ) { return scanf( "%s" , s ); }

int R() { return 0; }

template< typename T1 , typename... T2 >
int R( T1& x , T2&... tail )
{
  int tmp = _R( x );
  return tmp + R( tail... );
}

template< typename Iter , typename F >
inline void out( Iter s , Iter e , F of )
{
  bool flag = 0;
  for( Iter it = s ; it != e ; it++ )
  {
    if( flag ) printf( " " );
    else flag = 1;
    of( *it );
  }
  puts( "" );
}

// }}}
// start ~~QAQ~~

const int SZ_PRIMES = 14;

int n , J;
int pw[ 11 ][ 40 ][ SZ_PRIMES ];
vector<int> test_primes{ 2,3,5,7,11,13,17,19,23,29,31,37,43,47 };
vector<pair<ll,vector<int>>> ans;

inline int comp( ll msk , int bs ) {
  FOR( p , SZ_PRIMES ) {
    int test = 0;
    FOR( i , n ) if( (msk>>i)&1ll ) {
      test += pw[ bs ][ i ][ p ];
    }
    test %= test_primes[ p ];
    if( test == 0 ) return test_primes[ p ];
  }
  return -1;
}

inline void chk( ll msk ) {
  vector<int> res;
  REP( i , 2 , 10 ) {
    int tmp = comp( msk , i );
    if( tmp < 0 ) return ;
    res.push_back( tmp );
  }
  ans.push_back( { msk , res } );
}
void dfs( int now , ll msk ) {
  if( now == 1 ) {
    chk( (msk<<1)+1 );
    return ;
  }
  dfs( now-1 , msk<<1 );
  if( SZ( ans ) < J )
    dfs( now-1 , (msk<<1)+1 );
}

int main()
{
  REP( i , 2 , 10 ) {
    FOR( j , SZ_PRIMES ) pw[ i ][ 0 ][ j ] = 1;
    REP( j , 1 , 32 ) {
      FOR( k , SZ_PRIMES ) {
        pw[ i ][ j ][ k ] = (i*pw[ i ][ j-1 ][ k ])%test_primes[ k ];
      }
    }
  }
  int tc;R( tc );
  REP( _ , 1 , tc ) {
    printf( "Case #%d:\n" , _ );
    R( n , J );
    dfs( n-1 , 1 );
    assert( SZ( ans ) >= J );
    ans.resize( J );
    for( auto p : ans ) {
      ll msk = p.first;
      REP( i , 1 , n )
        printf( "%lld" , (msk>>(n-i))&1ll );
      for( int x : p.second ) printf( " %d" , x );
      puts( "" );
    }
  }
}
