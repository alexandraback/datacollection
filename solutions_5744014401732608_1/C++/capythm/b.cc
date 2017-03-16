#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;
int main( void )
{
  ios::sync_with_stdio(false);
  int T, B;
  string mstr;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> B >> mstr;
    ll Mmax = 1LL<<(B-2);
    stringstream ss;
    ss << Mmax;
    if( ss.str().size() < mstr.size() ){
      cout << "Case #" << testcase << ": IMPOSSIBLE" << endl;
      continue;
    }
    ll M = 0;
    for( int i=0; i<mstr.size(); i++ ){
      M = M*10 + mstr[i] - '0';
    }
    if( Mmax < M ){
      cout << "Case #" << testcase << ": IMPOSSIBLE" << endl;
      continue;
    }
    cout << "Case #" << testcase << ": POSSIBLE" << endl;
    bool f = (Mmax == M);
    for( int i=0; i<B-1; i++ ){
      for( int j=0; j<B-1; j++ ){
        if( i < j ) cout << 1;
        else cout << 0;
      }
      if( i == 0 ){
        if( f ) cout << 1 << endl;
        else cout << 0 << endl;
      } else {
        if( f ) cout << 1 << endl;
        else cout << (M&1) << endl;
        M >>= 1;
      }
    }
    for( int i=0; i<B; i++ ){
      cout << 0;
    }
    cout << endl;
  }
}
