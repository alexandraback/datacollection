#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {
  int TT;
  scanf("%d", &TT);
  for (int tc = 1; tc <= TT; tc++) {
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);

    long long R = 0;

    for (int a = 0; a < A; a++) {
      for (int b = 0; b < B; b++) {
        if ((a&b) < K) R++;
      }
    }
    printf("Case #%d: %lld\n", tc, R);
  }
}
