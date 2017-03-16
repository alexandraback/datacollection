/* My Template for the Google Code Jam.
 *
 * Compile: g++ -std=c++11 -lgmp -lgmpxx
 *  - I'm probably using some c++11 features.
 *  - I might use GMP (GNU Multiple Precision Arighmetic Library) so
 *    I'm including -lgmp and -lgmpxx in the template even if they
 *    won't be used.
 *
 * This code is ugly but it works - otherwise you wouldn't be reading
 * it, right?
 */

#include <cassert>
//#define NDEBUG

#include <cstdlib>
#include <cstdint>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <gmpxx.h>

double solve() {
  std::cout.precision(15);
  double C, F, X;
  std::cin >> C;
  std::cin >> F;
  std::cin >> X;

  double rate = 2;
  double time = 0;

  while(true) {
    //    std::cout << time << "\n";
    //See if it is better to quit now?
    if((X-C)/rate <= X/(rate+F)) {
      return time+X/rate;
    }
    
    //Buy next
    time += C/(rate);
    rate += F;
  }
  
}

void pre_compute() {
  
}

int main() {
  pre_compute();
  size_t T;
  std::cin >> T;
  for(size_t i=1; i<=T; i++) {
    auto res = solve();
    std::cout << "Case #" << i << ": " << res << "\n";
  }

  return 0;
}
