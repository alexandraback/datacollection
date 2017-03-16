#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

int main() {
  int Z;
  scanf("%d", &Z);
  for (int z=1;z<=Z;z++) {
    printf("Case #%d: ", z);
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    vector<vector<int>> G(n, vector<int>(n, 0));
    for (int i=1;i<n;i++)
      for (int j=i+1;j<n;j++)
        G[i][j] = 1;
    if ((1LL<<(n-2)) < k) printf("IMPOSSIBLE\n");
    else {
      printf("POSSIBLE\n");
      if ((1LL<<(n-2)) == k) {
        for (int i=1;i<n;i++)
          G[0][i] = 1;
      } else {
        for (int i=0;i<n-2;i++)
          if (k & (1LL<<i)) {
            G[0][n-2-i] = 1;
          }
      }
      for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++)
          printf("%d", G[i][j]);
        printf("\n");
      }

      vector<long long> cnt(n, 0);
      cnt[0] = 1;
      for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
          if (G[i][j])
            cnt[j] += cnt[i];
      // printf("%lld %lld\n", cnt[n-1], k);
      assert(cnt[n-1] == k);
    }
  }
  return 0;
}
