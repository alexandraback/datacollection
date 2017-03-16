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


int multi[4][4] = {{1, 2, 3, 4},
		   {2, -1, 4, -3},
		   {3, -4, -1, 2},
		   {4, 3, -2, -1}
};

int multiply(int a, int b){
  return multi[abs(a)-1][abs(b)-1] * ((a*b<0) ? -1 : 1);
}

//Solution:

string solve() {
  ll L, X;
  cin >> L;
  cin >> X;
  string s;
  cin >> s;

  vector<int> vec;
  for(int i=0; i<X; i++) {
    for(int j=0; j<L; j++) {
      if(s[j]=='1') 
	vec.push_back(1);
      else
	vec.push_back(s[j]-'i'+2);
    }
  }

  //  print_vector(vec);

  int i=0;
  int prod=1;
  int sym=2;
  for(; i<L*X; i++) {
    prod = multiply(prod, vec[i]);
    //    cout << "Prod: " << prod;
    if(sym!=4 && prod==sym) {
      sym++;
      prod = 1;
    }
  }
  return (sym==4 && prod==4) ? "YES" : "NO";
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
