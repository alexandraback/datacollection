// code jam b
int verbose = 0 ;

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std ;

int flips(char *cakes) {
  int count = 0 ;
  char prevCake = cakes[0];
  long int numCakes = strlen(cakes);
  int i ;
  for (i = 1 ; i<numCakes ; i++) {
    char nextCake = cakes[i] ;
    if (prevCake != nextCake)
      count++;
    prevCake = nextCake ;
  }
  if (prevCake == '-')
    count++;
  return count ;
}

int runTest() {
  char cakeString[102] ;
  cin >> cakeString ;
  if (verbose) {
    cout << endl << "Cakes: " << cakeString << " :" ;
  }
  cout << flips(cakeString) << endl ;
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
    if (!r)
      cerr << "Test " << i+1 << " failed!" << endl ;
  }
  return 0;
}

