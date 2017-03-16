#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int testcase = 0; testcase < T; ++testcase) {
    int N, S, p; scanf("%d%d%d", &N, &S, &p);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int t; scanf("%d", &t);
      if (t >= p + 2*max(p-1, 0)) {
        ++ans;
      } else if (S > 0 && t >= p + 2*max(p-2, 0)) {
        ++ans; --S;
      }
    }
    printf("Case #%d: %d\n", testcase+1, ans);
  }
}
