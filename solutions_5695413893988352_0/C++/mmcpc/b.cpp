#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

unsigned long long resa, resb;
unsigned long long diff;
bool checked;

unsigned long long LDiff(unsigned long long a, unsigned long long b) {
  if (a >= b) return (a - b);
  else return (b - a);
}

unsigned long long pow(unsigned long long base, int n) {
  unsigned long long res = 1;
  while (n) {
    if (n & 1) {
      res *= base;
    }
    n /= 2;
    base *= base;
  }

  return res;
}

void FindScore(const string& a, const string& b, int n,
               unsigned long long av, unsigned long long bv) {
  if (a.size() == n) {
    if (checked == false || LDiff(av, bv) < diff) {
      diff = LDiff(av, bv);
      resa = av;
      resb = bv;
      checked = true;
    } else if (diff == LDiff(av, bv)) {
      if (av < resa) {
        resa = av;
        resb = bv;
      } else if (av == resa && bv < resb) {
        resa = av;
        resb = bv;
      }
    }

    return;
  }

  int as = 0, bs = 0;
  int ae = 9, be = 9;
  if (a[n] != '?') { as = ae = (a[n] - '0'); }
  if (b[n] != '?') { bs = be = (b[n] - '0'); }

//  cout << n << " ========" << endl;

  for (int i = as; i <= ae; ++i) {
    for (int j = bs; j <= be; ++j) {
      int sz = a.size();
      unsigned long long p = pow(10, sz - n - 1);
//      cout << av << " " << bv << endl;
//      cout << p << endl;
      unsigned long long new_av = av + i * p;
      unsigned long long new_bv = bv + j * p;

      if (checked) {
        if (new_av > (new_bv + 2 * p)) {
          if (LDiff((new_av - p), (new_bv + p)) > diff) continue;
        } else if ((new_av + 2 * p) < new_bv) {
          if (LDiff((new_bv - p), (new_av + p)) > diff) continue;
        }
      }

//      cout << "NEW:" << new_av << " " << new_bv << endl;
      FindScore(a, b, n + 1, new_av, new_bv);
    }
  }
}

int main() {
  int t;
  cin >> t;
  for (int ci = 1; ci <= t; ++ci) {
    string a, b;
    cin >> a >> b;
    resa = 0;
    resb = 0;
    diff = 0;
    checked = false;

    FindScore(a, b, 0, 0, 0);

    int size = a.size();
    printf("Case #%d: %0*llu %0*llu\n", ci, size, resa, size, resb);
  }

  return 0;
}
