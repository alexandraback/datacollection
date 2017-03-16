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

typedef vector<double> vec;
typedef vector<vec> mat;

vec solvelse( mat m ){
  /*
  YYS( v , m ){
    YYS( w , v ) cout << w << " ";
    cout << endl;
  }
  */
  
  for( int i = 0; i < 10; i++ ){
    double piv = i;
    for( int j = i+1; j < m.size(); j++ )
      if( abs(m[j][i]) > abs(m[piv][i]) ) piv = j;
    
    swap( m[i] , m[piv] );

    for( int j = 0; j < m.size(); j++ ){
      if( i == j ) continue;
      double b = m[j][i]/m[i][i];
      for( int k = i; k < m[j].size(); k++ )
	m[j][k] -= m[i][k]*b;
    }
  }

  /*
  YYS( v , m ){
    YYS( w , v ) cout << w << " ";
    cout << endl;
  }
  */

  vec res(0);
  for( int i = 0; i < 10; i++ )
    res.push_back( m[i][ m[i].size()-1 ] / m[i][i] );
  return res;
}


const string ST[] = { "ZERO" , "ONE" , "TWO" , "THREE" , "FOUR" , "FIVE" , "SIX" , "SEVEN" , "EIGHT" , "NINE" };

const int MAX_N = 2010;

int t;

char s[MAX_N];
mat A;

int main(){

  A = mat( 26 , vec( 11 , 0.0 ) );
  REP( i , 10 ) YYS( w , ST[i] ) A[w-'A'][i] += 1;

  scanf( "%d" , &t );
  REP( tc , t ){
    scanf( "%s" , s );
    int n = strlen( s );
    REP( i , 26 ) A[i][10] = 0;
    REP( i , n ) A[s[i]-'A'][10] += 1;
    vec res = solvelse( A );
    string ans = "";
    REP( i , 10 ){
      int x = int( res[i] + 0.5 );
      REP( j , x ) ans += char( '0' + i );
    }
    printf( "Case #%lld: %s\n" , tc+1 , ans.c_str() );
  }
  
  return 0;
}
