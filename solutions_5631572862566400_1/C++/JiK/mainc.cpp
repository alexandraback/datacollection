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
    if(it!=v.begin())
      std::cout << " ";
    std::cout << (*it);
  }
}

//Copy functions from TCR here.



//Solution:
ll getcycle (vector<ll> bff) {
  ll N = bff.size();

  ll res = 0;


  for (int i=0; i<N; i++) {
    vector<bool> used (N, false);
    int a = i;
    while(true) {
      if (used[a]) break;
      used[a] = true;
      a = bff[a];
    }

    ll len = 1;
    for (int b = a; bff[b] != a; b = bff[b] ) {
      len++;
    }

    res = max(len, res);
  }
  return res;
}

vector<ll> getchains (vector<ll> bff) {
  ll N = bff.size();

  vector<ll> res(N, 0);

  for (int i=0; i<N; i++) {
    vector<bool> used (N, false);
    int a = i;
    ll len = 0;
    while(true) {
      if (used[a]) break;
      len++;
      res[a] = max(res[a], len);
      used[a] = true;
      a = bff[a];
    }
  }
  return res;
}

vector<ll> gettwochains (vector<ll> bff) {
  ll N = bff.size();


  vector<ll> twochains (N, 0);

  for (int i=0; i<N; i++) {
    vector<bool> used0 (N, false);
    int a = i;
    while(true) {
      if (used0[a]) break;
      used0[a] = true;
      a = bff[a];
    }

    if (bff[bff[a]] != a) {
      continue;
    }

    for (int j=0; j<N; j++) {
      vector<bool> used1 (N, false);
      int b = j;
      while(true) {
	if (used1[b]) break;
	used1[b] = true;
	b = bff[b];
      }

      if (bff[bff[b]] != b) {
	continue;
      }

      if (a == b) {
	continue;
      }
      
      if (!used0[b]) { 
	continue;
      }
      
      ll count = 0;
      for (int k=0; k<N; k++) {
	if (used0[k] || used1[k]) { 
	  count++;
	}
      }
      twochains[min(a,b)] = max(twochains[min(a,b)], count);
      
      //      cerr << "Starting from " << i << " and " << j << " ending in "
      //	   << a << " and " << b << " len " << count << endl;
    }
  }
  return twochains;
}


ll solve() {
  ll N;
  cin >> N;
  vector<ll> bff;
  read_to_vector(N, bff);
  for (auto & i : bff) {
    i--;
  }

  ll res = 0;

  res = getcycle(bff);
  //  cerr << "Cycle: " << res << endl;

  vector<ll> chains = getchains(bff);
  ll resc = 0;
  for (int i=0; i<N; i++) {
    if (bff[i] > i && bff[bff[i]] == i) {
      resc += max(chains[i], chains[bff[i]]);
      //      cerr << "Chain ending in " << i << " total " << resc << endl;
    }
  }

  res = max(res, resc);

  vector<ll> twochains = gettwochains(bff);
  ll resc2 = 0;
  for (int i=0; i<N; i++) {
    if (bff[bff[i]] == i) {
      resc2 += twochains[i];
      //      cerr << "Twochains ending in " << i << " total " << resc2 << endl;
    }
  }
  res = max (res, resc2);

  return res;

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
