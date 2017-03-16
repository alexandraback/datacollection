#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ulli unsigned long long int



int main(){
  int T;
  cin >> T;
  for( int test_case = 1; test_case <= T; test_case++ ){
    ulli r,t;
    cin >> r >> t;
    ulli ub = min((t / (2*r)) + 1,(ulli)2LL * 1000LL * 1000LL * 1000LL);
    ulli lb = 0;
    while( ub - lb > 1 ){
      ulli m = (ub + lb) / 2;
      if( 2 * r * m - m + 2 * m * m <= t ){
	lb = m;
      } else {
	ub = m;
      }
    }
    cout << "Case #" << test_case << ": " << lb << endl;
  }
  return 0;
}

