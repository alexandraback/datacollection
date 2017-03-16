#include <iostream>
using namespace std;
int main( void )
{
  int T,C,D,V;
  cin >> T;
  for( int ti=1; ti<=T; ti++ ){
    int d[128];
    cin >> C >> D >> V;
    for( int i=0; i<=V; i++ ){
      d[i] = 0;
    }
    d[0] = 1;
    for( int i=0; i<D; i++ ){
      int a;
      cin >> a;
      for( int j=V; j>=0; j-- ){
        if( d[j] && j+a <= V ){
          d[j+a] = 1;
        }
      }
    }
    int ret = 0;
    for( int i=1; i<=V; i++ ){
      if( d[i] == 0 ){
        ret++;
        for( int j=V; j>=0; j-- ){
          if( d[j] && j+i <= V ){
            d[j+i] = 1;
          }
        }
      }
    }
    cout << "Case #" << ti << ": " << ret << endl;
  }
}
