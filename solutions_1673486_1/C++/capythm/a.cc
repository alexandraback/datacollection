#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

double p[100003];
int main( void )
{
  int T,A,B;
  double d;
  ios::sync_with_stdio(false);
  cin >> T;
  for( int testnum=1; testnum<=T; testnum++ ){
    cin >> A >> B;
    p[0] = 1.0;
    for( int i=0; i<A; i++ ){
      cin >> d;
      p[i+1] = p[i] * d;
      p[i] = 1.0 - p[i+1];
    }
    // keep
    double ret = p[A] * (B-A+1) + (1.0-p[A]) * (2*B-A+2);
    ///////cout << "keep " << ret << endl;
    // enter
    double ret0 = p[A] * ((A==B) ? 1 : B+2) + (1.0-p[A]) * (B+2);
    ret = min( ret, ret0 );
    ///////cout << "enter " << ret0 << endl;
    for( int i=1; i<A; i++ ){
      // bs i
      double d = p[A-i-1] * (2*B-A+2+2*i) + (1.0-p[A-i-1]) * (B-A+1+2*i);
      ret = min( ret, d );
      ///////cout << "bs" << i << " " << d << endl;
    }
    printf( "Case #%d: %.6lf\n", testnum, ret );
  }
  return 0;
}
