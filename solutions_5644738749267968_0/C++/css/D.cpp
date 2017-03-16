#include<cstdio>
#include<algorithm>
using namespace std;

int t, n, ans[2];
double w[2][1000];

int main()
{
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    for (int p = 0; p < 2; p++)
      for (int j = 0; j < n; j++) scanf("%lf", &w[p][j]);
    sort(w[0], w[0]+n);
    sort(w[1], w[1]+n);
    ans[0] = ans[1] = 0;
    for (int p = 0; p < 2; p++) {
      int x = n-1;
      for (int y = n-1; y >= 0; y--) {
        while (x>=0 && w[!p][x]>=w[p][y]) x--;
        if (x>=0) {
          ans[p]++;
          x--;
        }
      }
    }
    printf("Case #%d: %d %d\n", i, ans[0], n-ans[1]);
  }
}
