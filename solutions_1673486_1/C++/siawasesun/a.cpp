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

// Macro
#define foreach(c, i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define mp make_pair
#define ALL(a) (a).begin(), (a).end()
#define OSS ostringstream
#define ISS istringstream
#define CAST(x,type)  *({OSS oss; oss << (x); ISS iss(oss.str()); static type _r; iss >> _r; &_r; })


using namespace std;

void CommonInit() {
}

const int MAX_A = 100010;
typedef long long int64;
#define INF (1<<29)

struct Problem {
  int A, B;
  double P[MAX_A];
  double PP[MAX_A];

  void Input() {
    scanf("%d %d", &A, &B);
    for (int i = 0; i < A; i++) {
      scanf("%lf", P + i);
    }
  }

  void Solve() {
    PP[0] = 1.0;
    for (int i = 1; i <= A; i++) {
      PP[i] = PP[i - 1] * P[i - 1];
    }

    double types[A + 10];
    fill(types, types + A + 10, 0.0);

    int R = (B - A);

    // enter bs rightaway.
    types[A + 1] = (1 + B + 1);
    // remove to i th.
    for (int i = A; i >= 0; i--) {
      int l = A - i;
      int C = R + 1;
      int T = 2 * l + C;
      types[i] = T * PP[i] + (T + B + 1) * (1 - PP[i]);
    }

    double res = INF;
    for (int i = A + 1; i >= 0; i--) {
      res = min(res, types[i]);
    }
    printf("%lf", res);
  }

}; // struct Problem


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
