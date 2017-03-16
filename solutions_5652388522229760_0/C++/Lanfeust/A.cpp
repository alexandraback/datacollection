#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;

void solveRef(int n) {
  if (n == 0) {
    printf("INSOMNIA\n");
    return;
  }
  int cur = 0;
  set<int> seen;
  while (seen.size() < 10) {
    cur += n;
    int to_check = cur;
    while (to_check != 0) {
      seen.insert(to_check % 10);
      to_check /= 10;
    }
  }
  printf("%d\n", cur);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    fprintf(stderr, "Case #%d of %d...\n", Ti, T);
    int n;
    scanf("%d", &n);
    printf("Case #%d: ", Ti);
    solveRef(n);
  }
  return 0;
}
