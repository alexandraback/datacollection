#include <cstdio>
#include <cmath>
#include <iostream>
#include <inttypes.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  uint64_t r,t;
  for (int t_ = 0; t_ < T; t_++) {
    cin >> r >> t;

    uint64_t min, max;
    min = 0;
    max = (1LLU<<32)-1;
    uint64_t n;
    while (min < max) {
      if ((max+min)%2 == 0)
        n = (max+min)/2;
      else
        n = (max+min)/2+1;
      // cout << min << " " << max << " " << n << endl;
      uint64_t val = 2*n*n+n*(2*r-1);
      if (val > t) {
        max = n-1;
      } else {
        min = n;
      }
    }


    cout << "Case #" << t_+1 << ": " << (int)min;
    cout << endl;
  }


  return 0;
}
