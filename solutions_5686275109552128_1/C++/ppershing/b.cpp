#include <stdio.h>
#include <algorithm>

#define FOR(q, n) for (int q=0; q<n; q++)

#define MAX 2000


void solve(int testcase) {
  int n;
  scanf("%d", &n);
  int data[MAX];
  FOR(i, n) scanf("%d", &data[i]);
  std::sort(data, data+n);
  int best=data[n-1];
  FOR(x, best) {
    if (!x) continue;
    // 
    int splits = 0;
    FOR(i, n) {
      // 0..x - 0
      // x..2x - +1
      // 2x..3x - +2
      if (data[i] > x) splits += (data[i] - 1) / x;
    }
    if (x + splits < best) best = x + splits;

  }
  printf("Case #%d: %d\n", testcase+1, best);
}


int main() {
  int T;
  scanf("%d", &T);
  FOR(i, T) solve(i);

}
