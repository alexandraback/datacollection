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
  
  cout << ((sqrt(9 + 4*(2*t - r + r*r - 2)) - 3)/2 - r)/2 + 1 << endl;
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
