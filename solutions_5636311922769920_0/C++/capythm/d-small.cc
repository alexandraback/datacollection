#include <iostream>
using namespace std;
int main( void )
{
  ios::sync_with_stdio( false );
  int T, K, C, S;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> K >> C >> S;
    cout << "Case #" << testcase << ":";
    for( int i=1; i<=S; i++ ){
      cout << " " << i;
    }
    cout << endl;
  }
}
