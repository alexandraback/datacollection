#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>

using namespace std;

#define MAXN 1000

int T, N;
string topics[MAXN][2];

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
      cin >> topics[i][0] >> topics[i][1];
    int best = 0;
    for (int j = 0; j < (1 << N); j++) {
      int t = __builtin_popcount(j);
      set<string> s1, s2;
      for (int k = 0; k < N; k++) {
        if ((1 << k & j) == 0) {
          s1.insert(topics[k][0]);
          s2.insert(topics[k][1]);
        }
      }
      bool valid = true;
      for (int k = 0; k < N; k++) {
        if (s1.find(topics[k][0]) == s1.end()) {
          valid = false;
          break;
        }
        if (s2.find(topics[k][1]) == s2.end()) {
          valid = false;
          break;
        }
      }
      if (valid)
        best = max(best, t);
    }
    printf("Case #%d: %d\n", t, best);
  }
  return 0;
}
