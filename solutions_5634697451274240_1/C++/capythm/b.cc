#include <iostream>
#include <string>
using namespace std;
int main( void )
{
  ios::sync_with_stdio( false );
  int T;
  cin >> T;
  for( int testcase = 1; testcase <= T; testcase++ ){
    string S;
    cin >> S;
    int ret = 0;
    for( int i=1; i<S.size(); i++ ){
      if( S[i] != S[i-1] ) ret++;
    }
    if( (S[0] == '+') ^ (ret%2 == 0) ) ret++;
    cout << "Case #" << testcase << ": " << ret << endl;
  }
}
