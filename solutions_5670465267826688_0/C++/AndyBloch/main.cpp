// code jam c
int verbose = 0 ;

#include <iostream>
#include <math.h>

int qmult(int a, int b) {
  int table[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2,-1, 4,-3},
    {0, 3,-4,-1, 2},
    {0, 4, 3,-2,-1}
  };
  if (a*b < 0)
    return -table[abs(a)][abs(b)];
  return table[abs(a)][abs(b)];
}

using namespace std ;
int runTest() {
  int L ;
  int repeat ;
  cin >> L >> repeat ;
  char q[L+1] ;
  cin >> q ;
  if (verbose) {
    cout << "L = " << L << " repeat " << repeat << ": " << q << endl ;
  }
  int i ;
  int j;
  int foundi = 0 ;
  int foundj = 0 ;
  int currentQ = 1 ;
  for (j = 0 ; j < repeat ; j++)
  for (i = 0 ; i < L ; i++) {
    currentQ = qmult(currentQ, q[i] - 'i' + 2) ;
    if (!foundi) {
      if (currentQ == 2) {
        foundi = 1 ;
        currentQ = 1 ;
      }
    }
    else if (!foundj) {
      if (currentQ == 3) {
        foundj = 1 ;
        currentQ = 1 ;
      }
    }
  }
  if (foundj&&(currentQ == 4))
    cout << "YES" << endl ;
  else
    cout << "NO" << endl ;
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

