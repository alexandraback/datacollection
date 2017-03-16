#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

class Solver {
 public:
  Solver() {
  }

  ostringstream convert;

  string solve() {
    uint64_t cnt = -1;

    if (N < 3 || M < 3) {
      cnt = K;
    }
    else {
      uint64_t k = 5;
      uint64_t p = 3;
      uint64_t l = 3;
      cnt = p+p+l+l-8;

      if (K > (M*N-4)) {
        k = K;
        cnt = M+N+M+N-8 + (K-(M*N-4));
      }
      else {
        while (K > k) {

          if (p < M) {
            p = p+1;
            k = k+l;

            if (K <= k) {
              //cout << "k = " << k << endl;
              //cout << "p = " << p << endl;
              //cout << "l = " << l << endl;
              cnt = p+l+p+l-8;
              break;
            }
          }

          if (l < N) {
            l = l+1;
            k = k+p;

            if (K <= k) {
              //cout << "k = " << k << endl;
              //cout << "p = " << p << endl;
              //cout << "l = " << l << endl;
              cnt = p+l+p+l-8;
              break;
            }
          }
        }
      }

    }

    convert << cnt;
    return convert.str();
  }

  uint64_t N, M, K;

};
 
int main (void) {
  int n, T;
  string val;

  cin >> T;

  for (n=1; n<=T; n++) {  
    Solver *solver = new Solver();
    cin >> solver->N >> solver->M >> solver->K;

    cout << "Case #" << n << ": " << solver->solve() << endl;
  }

  return 0;
}
