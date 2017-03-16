// 2013 code jam round 1B Problem B
int verbose = 0 ;

#include <iostream>
using namespace std ;
#include <vector>
//#include <string>
//#include <map>
//#include <set>
#include <math.h>

int caseNumber;

int runTest() {
  int N,X,Y ;
  cin >> N >> X >> Y ;
  X = abs(X);
  int height = sqrt(0.25+2*N) - 0.5 ;
  if ((height&1) == 0) height -- ; // height of central pyramid mus be odd.
  int r = N - (height+1)*height/2 ;
  if (verbose) {
    cout << "N: " << N << " height: " << height << " remaining: " << r << " X: " << X << " Y: " << Y << endl ;
  }
  if (X+Y < height) {
    cout << "Case #" << caseNumber << ": " << 1 << endl ;
    return 1 ;
  }
  if ((r == 0)||(X+Y > height+2)||(X==0)) {
    cout << "Case #" << caseNumber << ": " << 0 << endl ;
    return 1 ;
  }
  if (Y+1 > r) {
    cout << "Case #" << caseNumber << ": " << 0 << endl ;
    return 1 ;
  }
  int minHeight = r - height-1 ;
  if (minHeight < 0)
    minHeight = 0 ;
  if (verbose) {
    cout << "minHeight: " << minHeight<< endl ;
  }
  if (minHeight>=Y+1) {
    cout << "Case #" << caseNumber << ": " << 1 << endl ;
    return 1 ;
  }
  if (minHeight > 0) {
    cout << "Case #" << caseNumber << ": 0.50" << endl ;
    return 1 ;
  }

  
  // probability is the number of ways to flip at least Y+1 heads out of r flips ;
  // sum ( combin(r,n) ) / 2^r ,  0 <= n <= Y gives probability of failure
  
  long long ways = 1 ;
  int i;
  long long combin = 1 ;
  for (i = 1 ; i <= Y ; i++) {
    combin *= r+1 - i ;
    combin /= i ;
    ways += combin ;
    if (verbose)
      cout << i << " " << combin << " " << ways << endl ;
  }
  double p = (double) ways / ((long long)1<<r) ;
  
  
  cout << "Case #" << caseNumber << ": " ;
  cout << 1-p << endl ;
  
  return 1;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  if (verbose) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  for (caseNumber=1 ; caseNumber <= testCases ; caseNumber++) {
    if (verbose)
      cout << "// Running case #" << caseNumber << endl ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  return 0;
}

