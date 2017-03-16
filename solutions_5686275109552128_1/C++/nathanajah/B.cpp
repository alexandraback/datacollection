#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int p[1005];

int main() {
  int cs = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int res = 1000000000;
    for (int i = 0; i < n; i++) {
      scanf("%d", &p[i]);
    }
    sort(p, p + n);
    for (int i = 1; i <= 1000; i++){
      int cur = 0;
      for (int j = 0; j < n; j++) {
        if (p[j] > i) {
          cur += (p[j] - 1) / i;
        }
      }
      res = min(res, cur + i);
    }
    printf("Case #%d: %d\n",++cs,  res);
  }
}
