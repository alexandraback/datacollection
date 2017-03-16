#include <iostream>
#include <string>

using namespace std;

int main( void ) {
  int T;
  freopen("Alarge.in","rt",stdin);
  freopen("Alarge.out","wt",stdout);
  cin >> T;
  for( int t = 1; t <= T; t++ ) {
    string input;
    cin >> input;
    string answer;
    answer += input[ 0 ];
    for( int i = 1; i < input.size(); i++ ) {
      if( answer[ 0 ] <= input[ i ] ) {
        string newstr;
        newstr += input[ i ];
        answer = newstr + answer;
      } else {
        answer += input[ i ];
      }
    }
    cout << "Case #" << t << ": " << answer << endl;
  }
  return 0;
}
