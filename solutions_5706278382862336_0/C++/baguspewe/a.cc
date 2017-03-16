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

  void convert_gcf() {
    uint64_t a=P;
    uint64_t b=Q;
    while (b != 0) {
      uint64_t temp = a;
      a=b;
      b=temp%a;
    }
    P = P/a;
    Q = Q/a;
  }

  string solve() {
    int cnt = 1;

    convert_gcf();

    uint64_t q = 1;
    for (int i=0; i<40; i++) {
      if (Q==q) {
        goto normal;
      }
      q = q<<1;
    }

    return "impossible";

   normal:
    float n = 0.5;
    while ((float(P)/Q) < n) {
      cnt++;
      n = n/2;
    }

    convert << cnt;
    return convert.str();
  }

  uint64_t P, Q;

};
 
int main (void) {
  int n, T;
  string val;

  cin >> T;

  for (n=1; n<=T; n++) {  
    Solver *solver = new Solver();
    cin >> val;

    int pos;
    pos = val.find("/");
    solver->P = stoi(val.substr(0, pos));
    pos++;
    solver->Q = stoi(val.substr(pos, val.length()));

    cout << "Case #" << n << ": " << solver->solve() << endl;
  }

  return 0;
}
