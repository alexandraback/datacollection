#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <bitset>
#include <cmath>
#define phb push_back
#define ppb pop_back
#define mkp make_pair
#define frs first
#define scn second
using namespace std;

typedef unsigned long long ull;
const ull kMax = 1000000000ull;
const int kSize = 50;

struct Int {
  int v[kSize], ln;

  Int() {
    ln = 1;
    fill(&v[0], &v[kSize], 0);
  }

  Int(ull q) {
    ln = 0;
    fill(&v[0], &v[kSize], 0);
    do {
      v[ln++] = q % 10, q /= 10;
    } while (q > 0);
  }

  Int & set_ln() {
    for (ln = kSize; ln > 1; --ln)
      if (v[ln - 1])
        break;
    return *this;
  }

  Int operator + (const Int &ri) const {
    Int ret;
    int i, mx, sum, carry;

    mx = max(ln, ri.ln), sum = carry = 0;
    for (i = 0; i < mx; ++i) {
      sum = carry + v[i] + ri.v[i];
      ret.v[i] = sum % 10, carry = sum / 10;
    }

    if (carry > 0)
      ret.v[i] = carry;

    return ret.set_ln();
  }

  Int operator * (const Int &ri) const {
    Int ret;
    int i, j, mul, carry;

    for (i = 0; i < ri.ln; ++i) {
      mul = carry = 0;
      for (j = 0; j < ln; ++j) {
        mul = carry + ri.v[i] * v[j] + ret.v[i + j];
        ret.v[i + j] = mul % 10, carry = mul / 10;
      }

      if (carry > 0)
        ret.v[i + j] = carry;
    }

    return ret.set_ln();
  }

  bool operator > (const Int &ri) const {
    if (ln != ri.ln)
      return ln > ri.ln;
    else {
      for (int i = ln - 1; i >= 0; --i)
        if (v[i] != ri.v[i])
          return v[i] > ri.v[i];
      return false;
    }
  }
};

int Z;
ull R, T;

void soups_on(int);
Int yee_haw(ull);

int main() {
  cin >> Z;
  for (int zi = 1; zi <= Z; ++zi) {
    cin >> R >> T;
    soups_on(zi);
  }

  return 0;
}

void soups_on(int zi) {
  ull low = 0, up = kMax;

  while (low < up) {
    ull mid = (low + up) / 2 + 1;
    Int t = yee_haw(mid);
    if (t > Int(T))
      up = mid - 1;
    else
      low = mid;
  }

  cout << "Case #" << zi << ": " << low << "\n";
}

Int yee_haw(ull p) {
  Int a(2 * p - 1), b(p), c(2 * R);
  return b * (a + c);
}
