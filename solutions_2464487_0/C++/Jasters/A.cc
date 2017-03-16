#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iterator>
#include <queue>
#include <cassert>
#include <gmpxx.h>

using namespace std;

int main(int argc, char *argv[]) {
//	mpz_class a, b, c;
//	a = 1234;
//	b = "-5678";
//	c = a * a * a * a * a;
//	cout << "sum is " << sqrt(c) << "\n";
//	cout << "absolute value is " << abs(c) << "\n";

  int T;

  mpz_class r, t, numrings;
  
  cin >> T;
  cin.ignore(256, '\n');
  for (int trial = 1; trial <= T; ++trial) {
    cin >> r >> t;
    numrings = t * t;
    cout << "Case #" << trial << ": ",
    cout << ((1-2*r)+sqrt(4*r*(r-1)+1+8*t))/4 << endl;
//    cout << "Case #" << trial << ": " << cout << ((1-2*r)+sqrt(4*r*(r-1)+1+8*t))/4 << endl;
  }
  
  return 0;
}
