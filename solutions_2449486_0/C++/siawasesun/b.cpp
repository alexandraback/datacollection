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
#define ARRAY_SIZE(x) (sizeof(x) / sizeof( (x)[0]) )

using namespace std;

void CommonInit() {
}

struct Problem {
  int N, M;
  int A[110][110];
  void Input() {
    char tmp;
    scanf("%d %d\n", &N, &M);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        scanf("%d%c", &A[i][j], &tmp);
      }
    }
  }

  bool CanGoOut(int y, int x) {
    int h = A[y][x];
    bool canGoOutHorizontal = true;
    bool canGoOutVertical = true;

    for (int i = 0; i < M; ++i) {
      if (A[y][i] > h) {
        canGoOutHorizontal = false;
        break;
      }
    }
    for (int i = 0; i < N; ++i) {
      if (A[i][x] > h) {
        canGoOutVertical = false;
        break;
      }
    }

    return canGoOutHorizontal || canGoOutVertical;
  }

  bool Solve() {
    for (int y = 0; y < N; ++y) {
      for (int x = 0; x < M; ++x) {
        if (!CanGoOut(y, x)) {
          return false;
        }
      }
    }
    return true;
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
    if (p.Solve()) printf("YES");
    else printf("NO");
    printf("\n");
  }

  return 0;
}
