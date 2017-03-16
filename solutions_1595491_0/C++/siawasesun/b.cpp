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

using namespace std;

#define ALL(a) (a).begin(), (a).end()

struct Problem {
  int N;
  int S;
  int P;
  int T[110];
  
  void Input() {
    scanf("%d %d %d", &N, &S, &P);
    for (int i = 0; i < N; i++) {
      scanf("%d", T + i);
    }
  }

  void Solve() {
    vector<int> x;
    for (int i = 0; i < N; i++) {
      x.push_back(T[i]);
    }
    sort(ALL(x));
    reverse(ALL(x));
    int restSurprise = S;
    int res = 0;
    for (int i = 0; i < x.size(); i++) {
      int minLeast = (x[i] + 2) / 3;
      if (minLeast >= P) {
        res++;
      } else if (minLeast + 1 == P && x[i] % 3 != 1 && x[i] != 0) {
        if (restSurprise > 0) {
          res++;
          restSurprise--;
        }
      }
    }
    printf("%d", res);
  }

}; // struct Problem


int main() {
  int T;
  scanf("%d", &T);
  for (int testCase = 1; testCase <= T; ++testCase) {
    printf("Case #%d: ", testCase);
    Problem p;
    p.Input();
    p.Solve();
    printf("\n");
  }

  return 0;
}
