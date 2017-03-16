#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cctype>
using namespace std;

typedef long double Real;

const Real o = 1e-10;
const Real pi = acos(-1.0);
const int max_n = 1024;
const int oo = 0x7fffffff;

int T, I, n, X;
int s[max_n];

bool ok(int i, Real yi) {
  Real sum = yi;
  for (int j = 0; j < n; ++j) {
    if (j != i)
      sum += max((Real)0, ((Real)(s[i] - s[j])) / X + yi);
  }
  return sum >= 1 - o;
}

int main() {
  cin >> T;
  for (I = 0; I < T; ++I) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> s[i];

    X = 0;
    for (int i = 0; i < n; ++i)
      X += s[i];

    printf("Case #%d:", I + 1);
    for (int i = 0; i < n; ++i) {
      Real low = 0, high = 1;
      while (high - low > o) {
        Real mid = (low + high) / 2;
        if (ok(i, mid))
          high = mid;
        else
          low = mid;
      }
      printf("% .9Lf", (low + high) * 100 / 2);
    }
    printf("\n");
  }
	return 0;
}

