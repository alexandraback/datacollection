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

const int MAX_N = 128;

int t;
int n;
mi a;
int res[MAX_N][MAX_N];

bool swap_f = false;

bool usedrow[MAX_N];
bool usedcol[MAX_N];
bool used[MAX_N];

vi ans;

int main(){


  scanf( "%d" , &t );
  REP( tc , t ){
    scanf( "%d" , &n );
    a.resize( 2*n-1 );
    REP( i , n*2-1 ) a[i].resize( n );
    REP( i , n*2-1 ) REP( j , n ) scanf( "%d" , &a[i][j] );
    SORT( a );

    if( a[0][0] != a[1][0] ){
      REP( i , n*2-1 ){
	REP( j , n ) a[i][j] *= -1;
	REVERSE( a[i] );
      }
      swap_f = true;
    } else swap_f = false;

    SORT( a );

    /*
    if( a[0][0] != a[1][0] ){
      REP( i , n*2-1 ){
        REP( j , n ) cout << a[i][j] << " ";
	cout << endl;
      }
    }
    */

    /*
    REP( i , 2*n-1 ){
      REP( j , n ) cout << a[i][j] << " ";
      cout << endl;
    }
    */
    
    assert( a[0][0] == a[1][0] );

    REP( i , n ) REP( j , n ) res[i][j] = INF;
    REP( i , n ) res[i][0] = a[0][i], res[0][i] = a[1][i];

    REP( i , n*2-1 ) used[i] = false;
    used[0] = used[1] = true;

    REP( i , n ) usedrow[i] = usedcol[i] = false;
    usedrow[0] = usedcol[0] = true;
    
    REP( lp , n*2-1 ){
      bool update = false;
      pi crcand = pi( -1 , -1 );
      pi cccand = pi( -1 , -1 );
      REP( i , n*2-1 ) if( !used[i] ){
	int cr = -1, cc = -1;
	REP( j , n ){
	  if( res[j][0] == a[i][0] ){
	    bool ok = !usedrow[j];
	    REP( k , n ) if( res[j][k] != INF && a[i][k] != res[j][k] ) ok = false;
	    if( ok ) cr = j;
	  }
	  if( res[0][j] == a[i][0] ){
	    bool ok = !usedcol[j];
	    REP( k , n ) if( res[k][j] != INF && a[i][k] != res[k][j] ) ok = false;
	    if( ok ) cc = j;
	  }
	}
	if( cr != -1 && cc != -1 ){
	  int op = i+1;
	  if( i == 2*n-2 || a[i+1][0] != a[i][0] ) op = i-1;
	  bool cf = true, rf = true;
	  if( a[i][0] == a[op][0] ){
	    if( a[i][cr] != a[op][cc] ) cf = false;
	    if( a[i][cc] != a[op][cr] ) rf = false;
	  } else cf = rf = false;
	  if( !cf ) cc = -1;
	  if( !rf ) cr = -1;
	}
	if( cr != -1 ) crcand = pi( i , cr );
	if( cc != -1 ) cccand = pi( i , cc );
	if( cr != cc ){
	  if( cr != -1 ){
	    // cout << "ROW " << cr << endl;
	    REP( k , n ) res[cr][k] = a[i][k];
	    usedrow[cr] = true;
	  } else {
	    // cout << "COL " << cc << endl;
	    REP( k , n ) res[k][cc] = a[i][k];
	    usedcol[cc] = true;
	  }
	  update = true;
	  used[i] = true;
	}
      }
      if( !update ){
	if( crcand.fi != -1 ){
	  REP( k , n ) res[crcand.se][k] = a[crcand.fi][k];
	  // cout << "row " << crcand.fi << " " << crcand.se << endl;
	  used[ crcand.fi ] = true;
	  usedrow[ crcand.se ] = true;
	} else if( cccand.fi != -1 ){
	  REP( k , n ) res[k][cccand.se] = a[cccand.fi][k];
	  // cout << "col " << cccand.fi << " " << cccand.se << endl;
	  used[ cccand.fi ] = true;
	  usedcol[ cccand.se ] = true;
	}
      }

      /*
      REP( i , n ){
	REP( j , n ) cout << res[i][j] << " ";
	cout << endl;
      }
      cout << endl;
      */
    }

    bool answered = false;
    REP( i , 2*n-1 ) if( !used[i] ){
      /*
      cout << i << " " << endl;
      if( answered ){
	REP( i , n ){
	  REP( j , n ) cout << res[i][j] << " ";
	  cout << endl;
	}
      }
      */
      assert( !answered );
      ans = a[i];
      answered = true;
    }

    if( !answered ){
      ans.clear();
      REP( i , n ){
	if( !usedrow[i] ){
	  assert( !answered );	  
	  REP( j , n ) ans.pb( res[i][j] );
	  answered = true;
	}
	if( !usedcol[i] ){
	  assert( !answered );
	  REP( j , n ) ans.pb( res[j][i] );
	  answered = true;
	}
      }
    }

    if( swap_f ){
      REP( i , n ) ans[i] *= -1;
      REVERSE( ans );
    }

    /*
    if( ans[0] < 0 ){
      REP( i , n ){
	REP( j , n ) cout << res[i][j] << " ";
	cout << endl;
      }
      return 0;
    }
    */

    printf( "Case #%lld:" , tc+1 );
    REP( i , n ) printf( " %d" , ans[i] );
    printf( "\n" );
  }
  
  return 0;
}
