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
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

struct MaxFlow{
  typedef ll weight;
  const weight zero = 0;
  const weight INF_WEIGHT = INFLL;
  struct edge{
    int to, rev;
    weight cap;
    edge(){}
    edge( int to , weight cap , int rev ) : to(to) , cap(cap) , rev(rev) {}
  };
  vector<vector<edge> > G;
  vi level, iter;
  int n;
  void init( int arg_n ){
    n = arg_n;
    G = vector<vector<edge> >( n , vector<edge>(0) );
  }
  void add_edge( int from , int to , weight cap ){
    G[from].pb( to , cap , SZ(G[to]) );
    G[to].pb( from , zero , SZ(G[from])-1 );
  }
  void bfs( int s ){
    level = vi( n , -1 );
    queue<int> que;
    level[s] = 0;
    que.push( s );
    while( !que.empty() ){
      int v = que.front(); que.pop();
      YYS( e , G[v] ){
	if( e.cap > zero && level[e.to] < 0 ){
	  level[e.to] = level[v] + 1;
	  que.push( e.to );
	}
      }
    }
  }
  weight dfs( int v , int t , weight f ){
    if( v == t ) return f;
    for( int &i = iter[v]; i < G[v].size(); i++ ){
      edge &e = G[v][i];
      if( e.cap > zero && level[v] + 1 == level[e.to] ){
	weight d = dfs( e.to , t , min( f , e.cap ) );
	if( d > zero ){
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return zero;
  }
  weight max_flow( int s , int t ){
    weight flow = zero;
    while( 1 ){
      bfs( s );
      if( level[t] < 0 ) return flow;
      iter = vi( n , 0 );
      weight f;
      while( (f = dfs( s , t , INF_WEIGHT )) > zero ) flow += f;
    }
  }
};


int te;
int n;

MaxFlow mf;

map<string,int> ss, st;

string s, t;

int main(){

  cin >> te;
  REP( tc , te ){
    cin >> n;
    int sta = 2*n;
    int ter = sta+1;
    mf.init( n*2+2 );
    ss.clear();
    st.clear();
    int is = 0, it = 0;
    REP( i , n ){
      cin >> s >> t;
      if( ss.find( s ) == ss.end() ) ss[s] = is++;
      if( st.find( t ) == st.end() ) st[t] = it++;
      mf.add_edge( ss[s] , n + st[t] , 1 );
    }
    REP( i , is ) mf.add_edge( sta , i , 1 );
    REP( i , it ) mf.add_edge( n+i , ter , 1 );
    int res = mf.max_flow( sta , ter );
    int cuv = is + it - res;
    printf( "Case #%lld: %d\n" , tc+1 , n - cuv );
  }
  
  
  return 0;
}
