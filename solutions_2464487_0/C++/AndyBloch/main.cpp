// 2013 code jam round 1A Problem A
int v = 0 ;

#include <iostream>
#include <math.h>
using namespace std ;
//#include <vector>
//#include <string>
//#include <map>
//#include <set>

int caseNumber;

long slow(unsigned long r, unsigned long t) {
  long area = (r+1) *(r+1) - r*r ;
  if (area <= t)
    return 1+ slow(r+2,t-area) ;
  return 0 ;
}
int runTest() {
  unsigned long r, t;
  cin >> r >> t ;
  
  // first ring is ((r+1)^2 - r^2) * * pi
  // nth ring is ((r+2n-1)^2 - (r+2n-2)^2) * pi
  // difference is (r+2n-1)*2 - 1
  // sum is ((r+1)*2 - 1 + (r+2n-1)*2 - 1)/2*n
  // == (2r+2-1+2r+4n-2-1)/2*n
  // == (2r + 2n + 1)n
  // == 2n^2 + 2rn + n
  // when is 2n^2 + (2r+1)n - t = 0 ?
  // n = floor(-(2r+1) + sqrt ((2r+1)^2 + 4*2*t) / 4) ;
  
  if (v) {
    cout << "r " << r << " t " << t << endl ;
  }
/*
  long n = (-(double)(2*r+1)+sqrt((2*r+1)*(2*r+1) + 4*2*t))/4 ;
  long n1 = n+1 ;
  if (2*n1*n1 + (2*r+1)*n == t)
    n = n1 ;

*/
  long n = slow(r,t);
  cout << "Case #" << caseNumber << ": " ;
  cout << n << endl ;
  
/*
  if (n!=n2) {
    cout << "Error! slow function says " << n2 << endl ;
  }
*/
  
  return 1 ;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  if (v) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  for (caseNumber=1 ; caseNumber <= testCases ; caseNumber++) {
    if (v)
      cout << "// Running case #" << caseNumber << endl ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  return 0;
}

