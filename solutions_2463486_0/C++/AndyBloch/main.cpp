// code jam c
int verbose = 0 ;

#include <iostream>
#include <math.h>

using namespace std ;

int isPalindrome(unsigned long a) {
  char decimal[100];
  sprintf(decimal, "%ld",a);
  int i ;
  unsigned long N = strlen(decimal) ;
//  cout << decimal << ' ' << N << endl ;
  for (i = 0 ; i*2 < N-1 ; i++) {
    if (decimal[i] != decimal[N-i-1])
      return 0;
  }
  return 1 ;
}
int runTest() {
  unsigned long A ;
  unsigned long B ;
  cin >> A ;
  cin >> B ;
  if (verbose)
    cout << "// A=" << A << " B=" << B << endl ;
  unsigned long i;
  int count=0 ;
  for (i = sqrt(A) ; i <= sqrt(B) ; i++) {
    if (i*i < A)
      continue ;
/*    if (verbose) {
      if ( A > 10000000000) {
        if (isPalindrome(i))
          cout << i << endl ;
      }
    }
 */
    if (isPalindrome(i) && isPalindrome(i*i)) {
      if (verbose)
        cout << i << '\t' << i*i << endl ;
      count ++;
    }
  }
  cout << count << endl ;
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

