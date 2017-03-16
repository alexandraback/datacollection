#include <iostream>
using namespace std;
int main( void )
{
  int T,R,C,W;
  cin >> T;
  for( int ti=1; ti<=T; ti++ ){
    cin >> R >> C >> W;
    int ret = (R-1)*(C/W);
    ret += C/W - 1;
    ret += W;
    if( C % W != 0 ){
      ret++;
    }
    cout << "Case #" << ti << ": " << ret << endl;
  }
}
