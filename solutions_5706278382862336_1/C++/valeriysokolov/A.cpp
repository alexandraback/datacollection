#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>

typedef long long Int;

using namespace std;

void get_p_and_q(Int &p, Int &q) {
  string s;
  cin >> s;
  s.replace(s.find('/'), 1, " ");
  istringstream is(s);
  is >> p >> q;
}

Int gcd(Int x, Int y) {
  if (y == 0) {
    return x;
  }

  return gcd(y, x % y);
}

bool is_power_of_two(Int x) {
  return !(x & (x-1));
}

int nearest_ancesor(Int p, Int q) {
  if (p >= q/2) {
    return 1;
  }

  return 1 + nearest_ancesor(p, q/2);
}

void solve(int test_num) {
  Int p, q;
  get_p_and_q(p, q);

  Int g = gcd(p, q);
  p /= g;
  q /= g; 

  if (!is_power_of_two(q)) {
    cout << "Case #" << test_num << ": " << "impossible" << endl;
  } else {
    cout << "Case #" << test_num << ": " << nearest_ancesor(p, q) << endl;
  }
}


int main() {
  int tests;
  cin >> tests;
  for (int t = 1; t <= tests; ++t) {
    solve(t);
  }
  return 0;
}
