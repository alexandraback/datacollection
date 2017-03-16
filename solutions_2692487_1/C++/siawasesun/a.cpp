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

const int MAX_N = 1000010;

// Variables shared among each tests.


void CommonInit() {
}

struct Problem {
  // Input variables (these inputs are only avaiable in each test).
  int A, N;
  int M[MAX_N];

  void Input() {
    scanf("%d %d", &A, &N);
    for (int i = 0; i < N; i++) scanf("%d", M + i);
  }

  int go(int i, int sum) {
    if (i == N) return 0;

    if (sum > M[i]) return go(i + 1, sum + M[i]);

    int res = 0;

    int removed_res = 1 + go(i + 1, sum);

    if (sum == 1) {
      return removed_res;
    }

    while (true) {
      sum += sum - 1;
      res++;
      if (sum > M[i]) break;
    }
    int added_res = res + go(i + 1, sum + M[i]);

    return min(removed_res, added_res);
  }

  void Solve() {
    sort(M, M + N);

    int res = go(0, A);

    printf("%d", res);
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
