#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
const int maxN = 1e3+7, MAX_INT = ~0U>>1;
int T, n, t, sum, ans, a[maxN];
int main()
{
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  scanf("%d", &T);
  for (int count = 1; count <= T; count++) {
    ans = MAX_INT, t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] > t) t = a[i];
    }
    for (int i = 1; i<=t && i<ans; i++) {
      sum = 0;
      for (int j = 0; j < n; j++) sum += (a[j]-1)/i;
      if (sum+i < ans) ans = sum+i;
    }
    printf("Case #%d: %d\n", count, ans);
  }
}
