// 2013 code jam round 1C Problem B
int verbose = 0 ;

#include <iostream>
using namespace std ;
//#include <vector>
#include <string>
//#include <map>
//#include <set>

int caseNumber;

int runTest() {
  int X,Y;
  cin >> X >> Y ;
  
  int i ;
  string os ;
  for (i = 0 ; i < abs(X) ; i++) {
    if ( X < 0)
      os+="EW" ;
    else
      os+="WE" ;
  }
  for (i = 0 ; i < abs(Y) ; i++) {
    if ( Y < 0)
      os+="NS" ;
    else
      os+="SN" ;
  }
  
  
  cout << "Case #" << caseNumber << ": " ;
  cout << os << endl ;
  
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

