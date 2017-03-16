#include <cstdio>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int testcase = 0; testcase < T; ++testcase) {
    int A, B; scanf("%d%d", &A, &B);
    int highest = 1, ans = 0;
    for (int n = A; n <= B; ++n) {
      while (10*highest <= n) { highest *= 10; }
      int m = n;
      do {
        m = m/10 + m%10*highest;
        if (A <= m && m <= B && m > n) { ++ans; }
      } while (m != n);
    }
    printf("Case #%d: %d\n", testcase+1, ans);
  }
}
