#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>

#include "gmpxx.h"

using namespace std;

#define REP(i, n)      for (int (i) = 0, __n = (int)(n); (i) < __n; ++(i))
#define REPS(i, s, n)  for (int (i) = (s), __n = (int)(n); (i) < __n; ++(i))
#define REPD(i, n)     for (int (i) = (n); (i) >= 0; --(i))
#define FOREACH(i, x)  for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define SIZE(x)        (int)((x).size())

typedef mpz_class bigint_t;
const int MAXL = 26;

vector<bigint_t> S;

bigint_t f(int left, int mid = -1) {
  vector<int> digits;
  string x;

  for (; left > 0; left >>= 1)
    digits.push_back(left & 1);
  reverse(digits.begin(), digits.end());

  int L = digits.size();
  REP(i, L) x += (digits[i] + '0');
  if (mid >= 0) x += (mid + '0');
  REP(i, L) x += (digits[L-i-1] + '0');

  return bigint_t(x);
}

inline bool is_palin(bigint_t const& x) {
  string s = x.get_str();
  int L = s.length();

  REP(i, L) if (s[i] != s[L-i-1]) return false;
  return true;
}

bigint_t f(string left, int mid = -1) {
  string x = left;
  
  if (mid >= 0) x += (mid + '0');
  for (string::reverse_iterator it = left.rbegin(); 
       it != left.rend(); ++it)
    x += *it;

  return bigint_t(x);
}

template<typename T>
void add(T left, int mid = -1) {
  bigint_t x = f(left, mid);
  bigint_t y = x*x;

  assert(is_palin(x));
  assert(is_palin(y));

  S.push_back(y);
}

void generate_all() {
  REPS(s, 1, 1 << MAXL) {
    if (__builtin_popcount(s) > 4) continue;

    add(s); add(s, 0); add(s, 1);
    if (__builtin_popcount(s) <= 2) add(s, 2);
  }

  string y = "2";
  while (y.length() < MAXL) {
    add(y); add(y, 0); add(y, 1);
    y += '0';
  }

  S.push_back(bigint_t(1));
  S.push_back(bigint_t(4));
  S.push_back(bigint_t(9));

  sort(S.begin(), S.end());
}

int query(bigint_t x) {
  vector<bigint_t>::iterator it = lower_bound(S.begin(), S.end(), x);

  if (it == S.end()) return S.size();
  if (it != S.end() && *it != x) {
    if (it == S.begin()) return 0;
    --it;
  }

  return distance(S.begin(), it) + 1;
}

int main() {
  generate_all();

  ios_base::sync_with_stdio(false);
  int T; cin >> T;

  REP(tc, T) {
    string a, b; cin >> a >> b;
    printf("Case #%d: %d\n", tc+1, query(bigint_t(b)) - query(bigint_t(a)-1));
  }

  return EXIT_SUCCESS;
}
