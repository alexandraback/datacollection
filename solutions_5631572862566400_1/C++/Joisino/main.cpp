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

const int MAX_N = 2024;

int t, n;

vi G[MAX_N];
int to[MAX_N];
int dep[MAX_N];

int used[MAX_N];

int circans = 0;
int lineans = 0;

void dfs( int x , int p , int d , int k ){
  dep[x] = d;
  used[x] = k;
  if( used[ to[x] ] == k ){
    chmax( circans , dep[x] - dep[to[x]] +1 );
  } else if( used[ to[x] ] == 0 ){
    dfs( to[x] , x , d+1 , k );
  }
}

int dfs2( int x , int p ){
  used[x] = INF;
  int res = 1;
  YYS( w , G[x] ) if( w != p ) chmax( res , dfs2( w , x ) + 1 );
  return res;
}

int main(){

  scanf( "%d" , &t );
  REP( tc , t ){
    scanf( "%d" , &n );
    REP( i , n ) scanf( "%d" , &to[i] ), to[i]--;

    circans = lineans = 0;
    
    REP( i , n ) G[i].clear();
    REP( i , n ) G[ to[i] ].pb( i );

    REP( i , n ) dep[i] = used[i] = 0;
    
    REP( i , n ) if( to[ to[i] ] == i && used[i] == 0 ){
      lineans += dfs2( i , to[i] ) + dfs2( to[i] , i );
    }

    int k = 1;
    REP( i , n ) if( used[i] == 0 ) dfs( i , -1 , 1 , k++ );
    
    printf( "Case #%lld: %d\n" , tc+1 , max( lineans , circans ) );
  }
  
  return 0;
}
