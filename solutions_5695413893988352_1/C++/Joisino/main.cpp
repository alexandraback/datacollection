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

const int MAX_N = 20;

int te;

char s[MAX_N], t[MAX_N];
char ts[MAX_N], tt[MAX_N];
char tas[MAX_N], tat[MAX_N];

ll get( char *x ){
  int n = strlen( x );
  ll a = 0;
  REP( i , n ) a = a * 10 + ll( x[i] - '0' );
  return a;
}

ll calc(){
  return abs( get(s) - get(t) );
}

int main(){

  scanf( "%d" , &te );
  REP( tc , te ){
    scanf( "%s %s" , s , t );
    int n = strlen( s );
    int p = -1;
    for( int i = n-1; i >= 0; i-- ) if( s[i] != '?' && t[i] != '?' && s[i] != t[i] ) p = i;
    if( p == -1 ){
      REP( i , n ) if( s[i] == '?' && t[i] == '?' ) s[i] = t[i] = '0';
      REP( i , n ) if( s[i] == '?' ) s[i] = t[i];
      REP( i , n ) if( t[i] == '?' ) t[i] = s[i];
    } else {
      bool swap_f = false;
      if( s[p] < t[p] ){
	swap( s , t ); swap_f = true;
      }

      REP( i , n ) ts[i] = s[i], tt[i] = t[i];

      int q = -1;
      int qq = -1;
      for( int i = p-1; i >= 0; i-- ){
	if( s[i] == '9' ){
	  t[i] = '0';
	}
	if( t[i] == '0' ){
	  s[i] = '9';
	}
	if( s[i] == '?' && t[i] == '?' ){
	  s[i] = '9'; t[i] = '0';
	  qq = i;
	}
	if( s[i] == '?' ){
	  s[i] = t[i] - 1;
	  q = i;
	  break;
	}
	if( t[i] == '?' ){
	  t[i] = s[i] + 1;
	  if( qq != -1 ) break;
	  q = i;
	  break;
	}
      }

      if( q == -1 && qq != -1 ){
	REP( i , n ) s[i] = ts[i], t[i] = tt[i];
	for( int i = p-1; i >= 0; i-- ){
	  if( s[i] == '9' ){
	    t[i] = '0';
	  }
	  if( t[i] == '0' ){
	    s[i] = '9';
	  }
	  if( s[i] == '?' && t[i] == '?' ){
	    s[i] = '0'; t[i] = '1';
	    q = i;
	    break;
	  }
	  if( s[i] == '?' ){
	    s[i] = t[i] - 1;
	    q = i;
	    break;
	  }
	  if( t[i] == '?' ){
	    t[i] = s[i] + 1;
	    q = i;
	    break;
	  }
	}
      }

      ll tya = INFLL, tyb = INFLL;

      if( q != -1 ){
	REP( i , q ){
	  if( s[i] == '?' && t[i] == '?' ) s[i] = t[i] = '0';
	  if( s[i] == '?' ) s[i] = t[i];
	  if( t[i] == '?' ) t[i] = s[i];
	}
	FOR( i , p , n ){
	  if( s[i] == '?' ) s[i] = '9';
	  if( t[i] == '?' ) t[i] = '0';
	}
	tya = calc();
	REP( i , n+1 ) tas[i] = s[i], tat[i] = t[i];
      }

      REP( i , n ) s[i] = ts[i], t[i] = tt[i];
      REP( i , p ){
	if( s[i] == '?' && t[i] == '?' ) s[i] = t[i] = '0';
	if( s[i] == '?' ) s[i] = t[i];
	if( t[i] == '?' ) t[i] = s[i];
      }
      FOR( i , p , n ){
	if( s[i] == '?' ) s[i] = '0';
	if( t[i] == '?' ) t[i] = '9';
      }
      tyb = calc();

      if( tya < tyb ){
	REP( i , n ) s[i] = tas[i], t[i] = tat[i];
      } else if( tya > tyb ){
	
      } else if( !swap_f ){
	pl resa = pl( get( tas ) , get( tat ) );
	pl resb = pl( get( s ) , get( t ) );
	if( resa < resb ) REP( i , n ) s[i] = tas[i], t[i] = tat[i];
      } else {
	pl resa = pl( get( tat ) , get( tas ) );
	pl resb = pl( get( t ) , get( s ) );
	if( resa < resb ) REP( i , n ) s[i] = tas[i], t[i] = tat[i];
      }
      
      if( swap_f ) swap( s , t );
    }
    printf( "Case #%lld: %s %s\n" , tc+1 , s , t );
  }
  
  return 0;
}
