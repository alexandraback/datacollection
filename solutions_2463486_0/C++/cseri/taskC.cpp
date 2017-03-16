#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <limits>
#include <stdexcept>

#include "prettyprint.hpp"

using namespace std;

typedef long long int ll;


const int precalc_end = 20001;
std::vector<ll> precalc_numbers;

char x[1000];
ll makePali(ll n) {
  sprintf(x, "%lld", n);
  const int l = strlen(x);
  for (int i = 0; i < l; ++i) {
    x[2*l-i-1] = x[i];
  }
  x[2*l] = 0;

  ll ret;
  sscanf(x, "%lld", &ret);
  return ret;
}

ll makePaliWithMiddle(ll n, int middle) {
  sprintf(x, "%lld", n);
  const int l = strlen(x);
  for (int i = 0; i < l; ++i) {
    x[2*l-i] = x[i];
  }
  x[l] = '0'+middle;
  x[2*l+1] = 0;

  ll ret;
  sscanf(x, "%lld", &ret);
  return ret;
}

bool isPali(ll n) {
  sprintf(x, "%lld", n);
  const int l = strlen(x);
  for (int i = 0; i < l/2; ++i) {
    if (x[l-i-1] != x[i]) return false;
  }
  return true;
}

void precalc() {
  for (ll num = 1; num < 10; ++num) {
    if (isPali(num*num)) {
      fprintf(stderr, "i:- num:%lld sq:%lld\n", num, num*num);
      precalc_numbers.push_back(num*num);  
    }
  }
  for (ll i = 1; i < precalc_end; ++i) {
    {
      ll num = makePali(i);
      if (isPali(num*num)) {
        fprintf(stderr, "i:%lld num:%lld sq:%lld\n", i, num, num*num);
        precalc_numbers.push_back(num*num);  
      }
    }

    for (int m = 0; m < 10; ++m) {
      ll num = makePaliWithMiddle(i, m);
      if (isPali(num*num)) {
        fprintf(stderr, "i:%lld num:%lld sq:%lld\n", i, num, num*num);
        precalc_numbers.push_back(num*num);  
      }
    }
  }
}


int main() {

  int tn;
  cin >> tn;

  precalc();
  std::sort(precalc_numbers.begin(), precalc_numbers.end());

  for (int ti = 0; ti < tn; ti++) {

    ll a, b;
    cin >> a >> b;

    cerr << "ti: " << ti << endl;

    auto itb = std::lower_bound(precalc_numbers.begin(), precalc_numbers.end(), a);
    auto ite = std::upper_bound(precalc_numbers.begin(), precalc_numbers.end(), b);

    ll result = ite-itb;
    cout << "Case #" << ti+1 << ": " << result << endl;
    cerr << "Case #" << ti+1 << ": " << result << endl;

  }
}

