#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
double d[256];
string u;
int dfs( int depth, int S, int K, int L, string& s, string& t ){
  if( depth == S ){
    //cout << u << endl;
    int cnt = 0;
    for( int j=0; j<=S-L; j++ ){
      int f = 1;
      for( int k=0; k<L; k++ ){
        if( u[j+k] != s[k] ){
          f = 0;
          break;
        }
      }
      if( f ) cnt++;
    }
    return cnt;
  }
  int ret = 0;
  for( int i=0; i<K; i++ ){
    u[depth] = t[i];
    ret += dfs( depth+1, S, K, L, s, t );
  }
  return ret;
}
int main( void )
{
  int T,K,L,S;
  string s,t;
  cin >> T;
  for( int ti=1; ti<=T; ti++ ){
    cin >> K >> L >> S;
    cin >> t;
    for( int i='A'; i<='Z'; i++ ){
      d[i] = 0;
    }
    for( int i=0; i<K; i++ ){
      d[t[i]]++;
    }
    for( int i='A'; i<='Z'; i++ ){
      d[i] /= K;
    }
    cin >> s;
    // zero check
    int f = 0;
    for( int i=0; i<L; i++ ){
      if( d[s[i]] == 0 ){
        printf( "Case #%d: %.12f\n", ti, 0.0 );
        f = 1;
        break;
      }
    }
    if( f ) continue;
    // find maximum
    int mi = L;
    for( int i=1; i<L; i++ ){
      int f = 1;
      for( int j=0; i+j<L; j++ ){
        if( s[i+j] != s[j] ){
          f = 0;
          break;
        }
      }
      if( f ){
        mi = i;
        break;
      }
    }
    int mn = 1 + (S-L)/mi;
    //cout << '*' << mi << ' ' << mn << endl;
    u = "          ";
    int cnt = dfs( 0, S, K, L, s, t );
    int n = 1;
    for( int i=0; i<S; i++ ){
      n *= K;
    }
    // calc average
    double ret = ((double)mn) - ((double)cnt) / ((double)n);
    printf( "Case #%d: %.12f\n", ti, ret );
  }
}
