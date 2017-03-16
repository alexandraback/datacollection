// code jam d
int verbose = 0 ;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

long long int ipow(long long int base, int exp)
{
  long long int result = 1;
  while (exp)
  {
    if (exp & 1)
    result *= base;
    exp >>= 1;
    base *= base;
  }
  
  return result;
}

int runTest() {
  
  long long int k,c,s ;
  cin >> k >> c >> s ;
  // Each guess can eliminate c tiles of original sequence
  // So it can be accomplished if c * s >= k
  if (c*s < k) {
    cout << " IMPOSSIBLE" << endl ;
    return 1 ;
  }
  int i ;
  for (i = 0 ; i < k ; i+=c) {
    long long int guess = 0 ;
    long long int j ;
    for (j = i ; j < i + c ; j++) {
      if (j < k) {
        long long x = j*ipow(k,j-i) ;
        if (verbose)
          cout << i << " " << j << " " << x << endl ;
        guess += x;
      }
    }
    cout << " " << guess+1 ;
  }
  cout << endl ;
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
    cout << "Case #" << i + 1 << ":" ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  
  return 0;
}

