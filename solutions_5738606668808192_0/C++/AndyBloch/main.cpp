// code jam c
int verbose = 0 ;

#include <iostream>
#include <math.h>

using namespace std ;
int runTest() {
  cout << endl ;
  int n , j ;
  cin >> n >> j ;
  int x = 3 + (3<<(n-2)) ;
  int i ;
  for (i = 0 ; i < j ; i++) {
    int q ;
    int y = x ;
    for (q = 0 ; (1 << q) <= i ; q++) {
      if ((1<<q)&i) {
        y += 3 << (2*(q+1));
      }
    }
    if (verbose)
    cout << i << " " ;
    cout << bitset<16>(y) ;
    for (q = 2 ; q <= 10 ; q++)
      cout << " " << q + 1;
    cout << endl ;
  }
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
  int i;
  for (i=0 ; i < testCases ; i++) {
    if (verbose)
      cout << "// Running case #" << i+1 << endl ;
    cout << "Case #" << i + 1 << ": " ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  
  return 0;
}

