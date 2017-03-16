#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int T, A, N;
int motes[120];

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d %d", &A, &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &motes[i]);
    }
    sort(motes, motes + N);
//    printf("## %d -", A);
//    for (int i = 0; i < N; i++) {
//      printf(" %d", motes[i]);
//    }
//    printf("\n");
    int add = 0;
    int best = INT_MAX;
    bool possible = true;
    for (int i = 0; i < N; i++) {
      if (motes[i] >= A) {
        int cur = add + (N - i);
        if (cur < best)
          best = cur;
        int grow = A - 1;
        if (grow == 0) {
          possible = false;
          break;
        }
        while (motes[i] >= A) {
          add++;
          A += grow;
          grow = A - 1;
        }
      }
      A += motes[i];
    }
    if (possible && add < best)
      best = add;
    printf("Case #%d: %d\n", t + 1, best);
  }
}
