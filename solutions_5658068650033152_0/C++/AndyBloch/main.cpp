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
  int n,m,k ;
  cin >> n >> m >> k;
  if ((n <3) || (m< 3) || (k<4)) {
    cout << "Case #" << caseNumber << ": " << k << endl ;
    return 1;
  }
  int x,y;
  int fewest = k ;
  for (x = 3 ; x <= n ; x++) {
    y = (k+4)/x+1;
    if (y > m)
      y = m ;
    int enclosed = x * y - 4 ;
    int s = 2*(x+y-4);
    if (k > enclosed)
      s += k - enclosed ;
    if (v)
      cout << x << " x " << y << ": " << s << endl ;
    if (s < fewest) {
      fewest = s;
    }
    y-- ;
    enclosed = x * y - 4 ;
    s = 2*(x+y-4);
    if (k > enclosed)
      s += k - enclosed ;
    if (s < fewest) {
      fewest = s;
    }
    if (v)
      cout << x << " x " << y << ": " << s << endl ;
  }
  cout << "Case #" << caseNumber << ": " << fewest << endl ;
  
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

