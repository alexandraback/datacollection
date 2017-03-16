// code jam b
int verbose = 0 ;

#include <iostream>
using namespace std ;

int runTest() {
  int N ;
  int M ;
  cin >> N ;
  cin >> M ;
  if (verbose)
    cout << "// N=" << N << " M=" << M << endl ;
  int i,j;
  int heights[N][M];
  int lessThanRowMax[N][M];
  for (i = 0 ; i < N ; i++) {
    for (j = 0 ; j < M ; j++) {
      cin >> heights[i][j];
      lessThanRowMax[i][j] = 0 ;
    }
  }
  int rowMax ;
  for (i = 0 ; i < N ; i++) {
    rowMax = 0 ;
    for (j = 0 ; j < M ; j++) {
      if (heights[i][j] > rowMax)
        rowMax = heights[i][j];
    }
    for (j = 0 ; j < M ; j++) {
      if (heights[i][j] < rowMax)
        lessThanRowMax[i][j] = 1 ;
    }
  }
  for (j = 0 ; j < M ; j++) {
    int columnMax = 0 ;
    for (i = 0 ; i < N ; i++) {
      if (heights[i][j] > columnMax)
        columnMax = heights[i][j];
    }
    for (i = 0 ; i < N ; i++) {
      if ((heights[i][j] < columnMax) && lessThanRowMax[i][j]) {
        cout << "NO" << endl;
        return 1 ;
      }
        
    }
  }
  cout << "YES" << endl ;
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

