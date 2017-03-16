#include <iostream>
#include <string>
using namespace std;
int main( void )
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    string S;
    cin >> S;
    string ret;
    ret.append( 1, S[0] );
    for( int i=1; i<S.size(); i++ ){
      if( ret[0] <= S[i] ){
        ret.insert( 0, 1, S[i] );
      } else {
        ret.append( 1, S[i] );
      }
    }
    cout << "Case #" << testcase << ": " << ret << endl;
  }
}
