#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main( void )
{
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    string S;
    int L;
    cin >> S >> L;
    int ret=0;
    for( int i=0; i<S.size(); i++ ){
      for( int j=i; j<S.size(); j++ ){
        int c=0,d=0,prev=0;
        for( int k=i; k<=j; k++ ){
          if( S[k] == 'a' || S[k] == 'e' ||
              S[k] == 'i' || S[k] == 'o' || S[k] == 'u' ){
            prev=0;
          } else {
            if( prev ) d++;
            else {
              d=1; prev=1;
            }
          }
          c = max( d, c );
        }
        if( c >= L ) ret++;
      }
    }
    cout << "Case #" << testcase << ": " << ret << endl;
  }
  return 0;
}
