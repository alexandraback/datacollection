#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define MOD 1000000007LL
using namespace std;
typedef pair<string,int> P;
typedef long long ll;
int main( void )
{
  int T,N;
  P s[100];
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    ll ret=0;
    cin >> N;
    for( int i=0; i<N; i++ ){
      cin >> s[i].first;
      s[i].second = i;
    }
    sort( s, s+N );
    do {
      int a[256];
      for( int i=0; i<256; i++ ) a[i]=0;
      char prev = s[0].first[0];
      a[s[0].first[0]]++;
      ll f=1;
      for( int i=0; i<N; i++ ){
        for( int j=0; j<s[i].first.size(); j++ ){
          if( s[i].first[j] != prev ){
            a[s[i].first[j]]++;
            if( a[s[i].first[j]] > 1 ){
              f=0;
              goto L1;
            }
          }
          prev = s[i].first[j];
        }
      }
L1:
      //for( int i=0; i<N; i++ ){ cout << s[i].first; }
      //cout << ' ' << f << endl;
      ret = (ret+f) % MOD;
    } while( next_permutation( s, s+N ) );
    cout << "Case #" << testcase << ": " << ret << endl;
  }
  return 0;
}
