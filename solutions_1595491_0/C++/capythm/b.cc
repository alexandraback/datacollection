#include <iostream>
#include <algorithm>
using namespace std;

int main( void )
{
  int T,N,S,p,t,j,d,cnt,ret;
  cin >> T;
  for( t=1; t<=T; t++ ){
    ret = 0;
    cnt = 0;
    cin >> N >> S >> p;
    for( j=0; j<N; j++ ){
      cin >> d;
      if( d >= max(p-1,0) * 2 + p ) ret++;
      else if( cnt < S && d >= max(p-2,0) * 2 + p ){ cnt++; ret++; }
    }
    cout << "Case #" << t << ": " << ret << endl;
  }
  return 0;
}
