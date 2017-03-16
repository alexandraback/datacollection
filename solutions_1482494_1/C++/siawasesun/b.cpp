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

const int MAX_N = 1010;

void CommonInit() {
}

struct Problem {
  int N;
  int A[MAX_N], B[MAX_N];
  bool L[MAX_N][3];

  void Input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d %d", A + i, B + i);
    }
  }

  void Solve() {
    for (int i = 0; i < N; i++) {
      L[i][1] = false;
      L[i][2] = false;
    }

    int star = 0;
    int turn = 0;
    while (true) {
      //      printf("star: %d\n", star);
      bool finished = true;
      turn++;
      for (int i = 0; i < N; i++) {
        if (!L[i][2]) {
          finished = false;
          break;
        }
      }
      if (finished) break;

      bool selected = false;
      for (int i = 0; i < N; i++) {
        if (!L[i][2] && B[i] <= star) {
          if (L[i][1]) {
            //            printf("selected: 2(1) %d\n", i);
            star += 1;
          } else {
            //            printf("selected: 2(2) %d\n", i);
            star += 2;
          }
          L[i][2] = true;
          selected = true;
          break;
        }
      }
      if (selected) continue;

      int highest = -1;
      int k = -1;
      for (int i = 0; i < N; i++) {
        if (!L[i][2] && !L[i][1] && A[i] <= star) {
          if (highest < B[i]) {
            highest = B[i];
            k = i;
          }
        }
      }
      if (highest == -1) {
        printf("Too Bad");
        return;
      } else {
        L[k][1] = true;
        //        printf("selected: 1 %d\n", k);
        star += 1;
      }
    }
    printf("%d", turn - 1);
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
