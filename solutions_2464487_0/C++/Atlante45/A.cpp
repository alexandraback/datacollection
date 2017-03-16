#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <gmpxx.h>

using namespace std;

void alg() {
  mpz_class r, t;
  cin >> r >> t;
  

  mpz_class tmpt = t, tmpr = r, tmp;
  while ((tmp = 2*tmpr + 1) <= tmpt) {
    tmpt -= tmp;
    tmpr += 2;
  }

  /*
  if (r%2 == t%2)
    cout << ((sqrt(9 + 4*(2*t + 3*r + r*r - 2)) - 3)/2 - r)/2 << endl;
  else
    cout << ((sqrt(9 + 4*(2*t + 3*r + r*r - 2)) - 3)/2 - r)/2 + 1 << endl;
  */

  cout << (tmpr - r)/2 << endl;
}

int main() {
    int n_cases;
    cin >> n_cases;
    
    for (int test_case = 1; test_case <= n_cases; test_case++) {
      cout << "Case #" << test_case << ": ";
      alg();
    }

    return EXIT_SUCCESS;
}
