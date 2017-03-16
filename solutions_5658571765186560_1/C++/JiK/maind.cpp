/* My Template for the Google Code Jam.
 *
 * Compile: g++ -std=c++11 -lgmp -lgmpxx
 *  - I'm probably using some C++11 features.
 *  - I might use GMP (GNU Multiple Precision Arighmetic Library) so
 *    I'm including the library in the template even if they
 *    won't be used.
 *
 * This code is ugly but it works - otherwise you wouldn't be reading
 * it, right?
 */

#include <cassert>
//#define NDEBUG

#include <cstdlib>
#include <cstdint>
#include <cmath>

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#include <gmpxx.h>

using namespace std;
typedef size_t szt;

typedef long long ll;
typedef unsigned long long ull;

typedef mpz_class mpz;

template<typename T>
void read_to_vector(size_t N, std::vector<T> &v) {
  for(size_t i=0; i<N; i++) {
    T tmp;
    std::cin >> tmp;
    v.push_back(tmp);
  }
}
template<typename T>
void print_vector(const std::vector<T> &v) {
  for(auto it = v.begin(); it<v.end(); it++) {
    if(it==v.begin())
      std::cout << " ";
    std::cout << (*it);
  }
}

//Copy functions from TCR here.



//Solution:

string solve() {
  ll X, R, C;
  cin >> X;
  cin >> R;
  cin >> C;
 
  bool gabriel = true;

  if (X >= 7) {
    gabriel = false;
  } else {
    switch(X) {
    case 1:
      break;
    case 2:
      gabriel &= (R*C%2==0);
      break;
    case 3:
      gabriel &= (R*C%3==0);
      gabriel &= min(R,C)>1;
      break;
    case 4:
      gabriel &= (R*C%4==0);
      gabriel &= min(R,C)>2;
      gabriel &= max(R,C)>=4;
      break;
    case 5:
      gabriel &= (R*C%5==0);
      gabriel &= min(R,C)>2; // W piece
      if(min(R,C)==3) {
	gabriel &= max(R,C)>=10; // W piece
      }
      break;
    case 6:
      gabriel &= (R*C%6==0);
      gabriel &= min(R,C)>3;
      gabriel &= max(R,C)>=6;
    }
  }

 

  return gabriel ? "GABRIEL" : "RICHARD";
}

//This is executed before any input is read.
void pre_compute() {
  
}

int main() {
  std::cout << std::setprecision(15);
  pre_compute();
  size_t T;
  std::cin >> T;
  for(size_t i=1; i<=T; i++) {
    //CHOOSE A
    auto res = solve();
    std::cout << "Case #" << i << ": " << res << "\n";
  }

  return 0;
}
