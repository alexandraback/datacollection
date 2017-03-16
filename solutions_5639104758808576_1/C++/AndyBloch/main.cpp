//codejam a
int v = 0 ;

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std ;
int caseNumber ;

int runTest() {
  int smax;
  cin >> smax ;
  char c ;
  int s ;
  int maxNeeded = 0 ;
  int total = 0 ;
  if (v)
    cout << "smax = " << smax << " : " ;
  for (s = 0 ; s <smax+1 ; s++) {
    cin >> c ;
    int n = c - '0';
    if (v)
      cout << c ;
    int needed = s - total ;
    if (needed > 0) {
      if (needed > maxNeeded)
        maxNeeded = needed ;
    }
    total += n ;
  }
  if (v)
    cout << " " ;
  cout << "Case #" << caseNumber << ": " << maxNeeded << endl ;
  return 1 ;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  //testxor();
  cin >> testCases ;
  if (v) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  for (caseNumber=1 ; caseNumber <= testCases ; caseNumber++) {
    //if (caseNumber > 11) v = 1;
    if (v)
      cout << "// Running case #" << caseNumber << endl ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  return 0;
}

