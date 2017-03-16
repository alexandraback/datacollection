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

ll k, c, s;
vl ans;

bool solve(){
  scanf( "%lld %lld %lld" , &k , &c , &s );
  if( s * c < k ) return false;
  ans.clear();
  for( ll i = 0; i < k; i += c ){
    ll res = 0;
    REP( j , c ) res = res * k + min( i + j , k-1 );
    ans.pb( res );
  }
  return true;
}

int t;

int main(){

  scanf( "%d" , &t );
  REP( test_cnt , t ){
    bool res = solve();
    printf( "Case #%lld: " , test_cnt+1 );
    if( res ){
      REP( i , SZ(ans) ) printf( "%lld%c" , ans[i]+1 , i == SZ(ans)-1 ? '\n':' ' );
    } else printf( "IMPOSSIBLE\n" );
  }
  
  return 0;
}
