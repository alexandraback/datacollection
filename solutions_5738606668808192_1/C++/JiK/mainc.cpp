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
#include <bitset>

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
    if(it!=v.begin())
      std::cout << " ";
    std::cout << (*it);
  }
}

//Copy functions from TCR here.



//Solution:

ll getval(ll m, ll b) {
  ll bb = 1;
  ll res = 0;
  for (ll i=1; i < m; i *= 2) {
    if (m&i) { res += bb; }
    bb *= b;
  }
  return res;
}

ll getdiv(ll val) {
  if (val%2==0) { return 2; }
  for (ll x=3; x*x <= val; x+= 2 ) {
    if (val%x == 0) { return x; }
  }
  return val;
}

ll solve() {
  ll N, J;
  cin >> N >> J;

  cout << endl;
  for (ull m=1; m<(1LLU<<(N/2)); m+= 2) {

    if (J==0) break;
    J--;

    ull val = m;
    for (ull i=1; i<= m; i*= 2) {
      if (m&i) { 
	val |= (1LLU<<(N-1)) / i;
      }
    }
    
    std::cout << bitset<32>(val)
	      << " 3 4 5 6 7 8 9 10 11"
	      << endl;

    
  }


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
    std::cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
