#include <algorithm>
#include <assert.h>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <numeric>
#include <limits>
#include <iomanip>
using namespace std;

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define LL long long
#define LD long double
#define vi vector<int>
#define vl vector<LL>
#define vs vector<string>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define SET(v, i) (v | (1 << i))
#define TEST(v, i) (v & (1 << i))
#define TOGGLE(v, i) (v ^ (1 << i))

LL GCD(LL a, LL b) {
  return b == 0 ? a : GCD(b, a % b);
}

int Count(LL q) {
  int ret = 0;
  while (q) {
    if ((q & 1))
      ++ret;
    q >>= 1;
  }

  return ret;
}

int Solve(LL p, LL q) {
  LL gcd = GCD(p, q);
  p /= gcd;
  q /= gcd;

  if (p % 2 == 0 || Count(q) != 1)
    return -1;

  LL m = 1;
  int ret = 0;
  while (p < (q / m)) {
    m *= 2L;
    ++ret;
  }

  return ret;
}

int main() {
  int t;
    scanf("%d", &t);
    LL p, q;
    for (int i = 1; i <= t; ++i) {
      scanf("%lld/%lld", &p, &q);
      printf("Case #%d: ", i);

      int ret = Solve(p, q);
      if (ret == -1)
        printf("impossible\n");
      else
        printf("%d\n", ret);
    }
  return 0;
}
