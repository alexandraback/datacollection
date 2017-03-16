#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
#define pb emplace_back
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_P = 1000010;
bool isp[MAX_P];
vl ps;

vi ans;
bool check( ll x , ll n ){
  ans.clear();
  FOR( base , 2 , 11 ){
    ll cur = x;
    ll y = 0;
    ll B = 1;
    REP( i , n ){
      y += B * ( cur % 2 );
      B *= base;
      cur /= 2;
    }
    ll res = -1;
    YYS( p , ps ){
      if( y <= p ) break;
      if( y % p == 0 ){
	res = p;
	break;
      }
    }
    if( res == -1 ) return false;
    ans.pb( res );
  }
  return true;
}

set<ll> ss;
int t, n, j;

mt19937 mt;

int main(){

  mt.seed( clock() );

  FOR( i , 2 , MAX_P ) isp[i] = true;
  FOR( i , 2 , MAX_P ){
    if( isp[i] ){
      ps.pb( i );
      for( int j = i*2; j < MAX_P; j += i ) isp[j] = false;
    }
  }
  
  scanf( "%d %d %d" , &t , &n , &j );
  REP( test_cnt , t ){
    printf( "Case #%lld:\n" , test_cnt+1 );
    while( SZ(ss) < j ){
      ll x = ( (ll)mt() % PW(n-2) ) * 2LL + PW(n-1) + 1LL;
      if( ss.find(x) == ss.end() && check( x , n ) ){
	ss.insert(x);
	vi bs(0);
	REP( i , n ){
	  bs.pb( x % 2 );
	  x /= 2;
	}
	REVERSE( bs );
	REP( i , n ) printf( "%d" , bs[i] );
	YYS( w , ans ) printf( " %d" , w );
	printf( "\n" );
      }
    }
  }
  
  return 0;
}
