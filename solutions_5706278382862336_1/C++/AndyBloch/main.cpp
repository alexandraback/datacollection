// 2014 code jam round 1C Problem A
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
  long long p ;
  long long q ;
  cin >> p ;
  cin.ignore();
  cin >> q ;
  //cout << p << "/" << q << endl ;
  int log2q = log2(q);
  log2q = 0;
  while (!(q&1)) {
    q >>= 1 ;
    log2q++;
  }
  if (q != 1) {
    if ((p%q)!=0) {
      cout << "Case #" << caseNumber << ": impossible" << endl ;
      return 1;
    }
    p /= q ;
  }
  
  int log2p = log2(p);
  
  cout << "Case #" << caseNumber << ": " ;
  cout << log2q - log2p << endl ;
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

