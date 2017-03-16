#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int n[1000005];
int d[1000005];
int main( void )
{
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    string S;
    int L;
    cin >> S >> L;

    int prev=0;
    for( int i=0; i<S.size(); i++ ){
      if( S[i] == 'a' || S[i] == 'e' ||
          S[i] == 'i' || S[i] == 'o' || S[i] == 'u' ){
        n[i] = 0;
        prev=0;
      } else {
        if( prev ) n[i] = n[i-1]+1;
        else n[i] = 1;
        prev=1;
      }
    }
    prev=-1;
    for( int i=0; i<S.size(); i++ ){
      if( n[i] >= L ){
        prev = i;
        d[i] = i;
      } else {
        d[i] = prev;
      }
    }
    ll ret=0;
    for( int i=S.size()-1; i>=0; i-- ){
      if( d[i] >= 0 ){
        ret += d[i] - L + 2;
      }
    }
    cout << "Case #" << testcase << ": " << ret << endl;
  }
  return 0;
}
