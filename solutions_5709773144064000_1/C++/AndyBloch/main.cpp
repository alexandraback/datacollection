// code jam b
int verbose = 0 ;

#include <iostream>
#include <iomanip>
using namespace std ;

int runTest() {
  double C ;
  double F ;
  double X ;
  cin >> C ;
  cin >> F ;
  cin >> X ;
  if (verbose)
    cout << endl << "C = " << C << ", F = " << F << ", X = " << X << endl ;
  // For each input, there's an ideal number of farms to buy. Then you wait until you have X cookies
  // let r be your current cookie production rate
  // n is the number of farms
  // You stop buying a farm when the time it takes you to reach X (X/r = X/(2+F*n)) is less than the time to reach X+C
  // with another farm (X+C)/(2+F*(n+1)
  //  X/(2+F*n) >(X+C) / (2+F*(n+1))
  //  X*(2+F*(n+1)) >(X+C)*(2+F*n)
  //  2X+FXn+FX > 2X+FXn+2C+CFn
  //  FX > 2C+CFn
  //  CFn < FX - 2C
  //  n >= 2/F -  X/C

  int n ;
  double t = 0 ;
  double rate = 2.0;
  double lastT = 1000000 ;
  double elapsedT = 0;
  for (n = 0 ; n < 10000000 ; n++) {
    t = elapsedT + X/rate ;
    if (verbose)
      cout << n << "\t" << t << endl;
    if (t > lastT) {
      cout << fixed << setprecision(7) << lastT << endl ;
      return 1;
    }
    lastT = t ;
    elapsedT += C/rate ;
    rate += F ;
  }
  return 0;
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

