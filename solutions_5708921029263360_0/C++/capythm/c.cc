#include <iostream>
using namespace std;
int jp[101];
int js[101];
int ps[101];
int ret[1001];
int cur[1001];
int main( void )
{
  ios::sync_with_stdio(false);
  int T, J, P, S, K;
  string mstr;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> J >> P >> S >> K;
    int m = 0;
    for( int i=0; i<(1<<(J*P*S)); i++ ){
      int n=i;
      int num = 0;
      for( int j=0; j<J; j++ ){
        for( int p=0; p<P; p++ ){
          for( int s=0; s<S; s++ ){
            if( n & 1 ){
              cur[num++] = j*100 + p*10 + s;
            }
            n >>= 1;
          }
        }
      }
      if( num <= m ) continue;
      bool f = true;
      for( int c=0; c<100; c++ ){
        jp[c] = js[c] = ps[c] = 0;
      }
      for( int c=0; c<num; c++ ){
        int j = cur[c] / 100;
        int p = (cur[c]/10)%10;
        int s = cur[c] % 10;
        if( ++jp[j*10+p] > K ){ f=false; break; }
        if( ++js[j*10+s] > K ){ f=false; break; }
        if( ++ps[p*10+s] > K ){ f=false; break; }
      }
      if( f ){
        m = num;
        for( int c=0; c<m; c++ ){
          ret[c] = cur[c];
        }
      }
    }
    cout << "Case #" << testcase << ": " << m << endl;
    for( int i=0; i<m; i++ ){
      cout << ret[i]/100+1 << ' ' << (ret[i]/10)%10+1 << ' ' << ret[i]%10+1 << endl;
    }
  }
}
