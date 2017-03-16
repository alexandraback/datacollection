#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
vector<string> v[2];
set<string> s[2];
int main( void )
{
  ios::sync_with_stdio(false);
  int T, N;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> N;
    v[0].clear(); v[1].clear();
    for( int i=0; i<N; i++ ){
      string S, T;
      cin >> S >> T;
      v[0].push_back( S );
      v[1].push_back( T );
    }
    int ret = 0;
    for( int i=0; i<(1<<N); i++ ){
      int d = i;
      int r = 0;
      for( int j=0; j<N; j++ ){
        if( d&1 ) r++; 
        d >>= 1;
      }
      if( r <= ret ) continue;

      d = i;
      s[0].clear(); s[1].clear();
      for( int j=0; j<N; j++ ){
        if( (d&1) == 0 ){
          s[0].insert( v[0][j] );
          s[1].insert( v[1][j] );
        }
        d >>= 1;
      }
      d = i;
      bool f = true;
      for( int j=0; j<N; j++ ){
        if( (d&1) == 1 ){
          if( s[0].find( v[0][j] ) == s[0].end() ){
            f = false; break;
          }
          if( s[1].find( v[1][j] ) == s[1].end() ){
            f = false; break;
          }
        }
        d >>= 1;
      }
      if( f ){
        ret = r;
      }
    }

    cout << "Case #" << testcase << ": " << ret << endl;
  }
}
