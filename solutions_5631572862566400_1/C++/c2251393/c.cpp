
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

const int MAXN = 1010;

int n;
int nxt[ MAXN ];
bool vis[ MAXN ];
vector<int> g[ MAXN ];
vector<int> cy2s , cys;

int dfs( int u , int p , int d ) {
  int mx = d;
  for( int v : g[ u ] ) if( v != p ) {
    mx = max( mx , dfs( v , u , d+1 ) );
  }
  return mx;
}

inline int go_cyc( int u ) {
  static int stp[ MAXN ];
  //printf( "gocyc %d\n" , u );
  fill( stp , stp+n+1 , 0 );
  int cnt = 0;
  while( stp[ u ] == 0 ) {
    //printf( "  now %d\n" , u );
    stp[ u ] = ++cnt;
    u = nxt[ u ];
  }
  int res = cnt+1-stp[ u ];
  //printf( "  %d res %d\n" , u , res );
  return res;
}

int main()
{
  int tc;R( tc );
  REP( _ , 1 , tc ) {
    printf( "Case #%d: " , _ );

    R( n );
    fill( vis , vis+n+1 , 0 );
    REP( i , 1 , n ) g[ i ].clear();
    cy2s.clear() , cys.clear();
    REP( i , 1 , n ) {
      R( nxt[ i ] );
      g[ nxt[ i ] ].push_back( i );
    }

    

    REP( i , 1 , n ) {
      if( vis[ i ] ) continue ;
      if( i == nxt[ nxt[ i ] ] ) {
        int len1 = dfs( i , nxt[ i ] , 1 );
        int len2 = dfs( nxt[ i ] , i , 1 );
        cy2s.push_back( len1+len2 );
        vis[ i ] = vis[ nxt[ i ] ] = 1;
      } else {
        cys.push_back( go_cyc( i ) );
      }
    }

    int ans = 0;
    for( int x : cy2s ) ans += x;

    for( int x : cys ) ans = max( ans , x );

    printf( "%d\n" , ans );
  }
}
