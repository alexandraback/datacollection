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

ll t, n;

bool used[72];

bool append( ll x ){
  while( x > 0 ){
    used[ x%10 ] = true;
    x /= 10;
  }
  REP( i , 10 ) if( !used[i] ) return false;
  return true;
}

void answer( ll c , ll x ){
  printf( "Case #%lld: " , c+1 );
  if( x == -1 ) printf( "INSOMNIA\n" );
  else printf( "%lld\n" , x );
}

int main(){

  scanf( "%lld" , &t );
  REP( test_cnt , t ){
    scanf( "%lld" , &n );
    if( n == 0 ){
      answer( test_cnt , -1 );
      continue;
    }
    REP( i , 10 ) used[i] = false;
    ll cur = n;
    while( 1 ){
      if( append( cur ) ){
	answer( test_cnt , cur );
	break;
      }
      cur += n;
    }
  }
  
  return 0;
}
