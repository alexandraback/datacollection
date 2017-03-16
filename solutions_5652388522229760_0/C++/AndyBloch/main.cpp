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

long int lastInt(long int n) {
  if (n == 0) return 0;
  int hasInt[10]={0,0,0,0,0,0,0,0,0,0};
  int hasIntCount = 0 ;
  int m ;
  for (m = 1 ; m < 100 ; m++) {
    char nc[10];
    sprintf(nc,"%ld",n*m);
    if (v)
      cout << n << " " << nc << " " << n*m << endl ;
    int i ;
    for (i = 0 ; nc[i] != 0 ; i++) {
      //if (i> 1) continue ; // For verifying that only 0 results in insomnia
      int d = (nc[i]) - '0' ;
      if (!hasInt[d]) {
        hasInt[d] = 1 ;
        hasIntCount ++ ;
        if (hasIntCount == 10) {
          return n*m ;
        }
      }
    }
  }
  return 0 ;
}

void test(long int maxn) {
  long int i;
  for (i = 0 ; i <= maxn ; i++) {
    long int r = lastInt(i);
    if (r == 0)
      cout << i << " INSOMNIA" << endl ;
    else
      cout << i << " " << r << endl ;
  }
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  //test(testCases);
  if (v) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  for (caseNumber=1 ; caseNumber <= testCases ; caseNumber++) {
    long int n ;
    cin >> n ;
    cout << "Case #" << caseNumber << ": " ;
    long int r = lastInt(n);
    if (r == 0)
      cout << "INSOMNIA" << endl ;
    else
      cout << r << endl ;
  }
  return 0;
}

