#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <inttypes.h>
#include <gmpxx.h>

typedef mpz_class bigint;

using namespace std;

#define mp make_pair
#define ALL(a) (a).begin(), (a).end()


// Constants.


// Variables shared among each tests.


void CommonInit() {
}

long long combination(long long a, long long b) {
    if (a < b || b < 0) return 0;
    b = min(b, a - b);
    long long res = 1;
    for (int i = 0; i < b; ++i) res = res * (a - i) / (i + 1);
    return res;
  }

struct Problem {
  // Input variables (these inputs are only avaiable in each test).
  int N, X, Y;

  void Input() {
    scanf("%d %d %d", &N, &X, &Y);
  }

  int D(int r) {
    return 2 * r * r + 3 * r + 1;
  }

  double Go(int count, int rank, int y) {
    int fastest = y + 1;
    int latest = y + 1 + 2 * rank;

    if (y == 2 * rank) {
      fastest = latest = 4 * rank + 1;
    }

    if (count >= latest) return 1.0;
    if (count < fastest) return 0.0;

    double base = pow(0.5, fastest);
    double res = base;

    if (count == fastest) {
      return res;
    }

    res += (double)(count - fastest) / pow(2, 2 * rank);

    return res;
  }

  void Solve() {
    int rank = (X + Y) / 2;

    int last_rank = D(rank - 1);

    if (N <= last_rank) {
      printf("%lf", 0.0);
      return;
    }

    double d = Go(N - last_rank, rank, Y);
    printf("%lf", d);
  }
};

int main() {
  int T;
  scanf("%d", &T);

  CommonInit();

  for (int testCase = 1; testCase <= T; ++testCase) {
    printf("Case #%d: ", testCase);

    Problem p;
    p.Input();
    p.Solve();

    printf("\n");
  }

  return 0;
}
