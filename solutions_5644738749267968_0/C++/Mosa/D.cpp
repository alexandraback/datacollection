#include <bits/stdc++.h>

using namespace std;

int n;
long long a[1000], b[1000];

int main() {
  freopen("D-small-attempt0.in", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  int t; scanf("%d", &t);
  for(int tst = 1; tst <= t; ++tst) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
      int z; scanf("%d.%lld", &z, a + i);
      a[i] *= 100000;
    }
    for(int i = 0; i < n; ++i) {
      int z; scanf("%d.%lld", &z, b + i); b[i] *= 100000;
    }
    sort(a, a + n); reverse(a, a + n);
    sort(b, b + n); reverse(b, b + n);
    int dw = 0;
    for(int i = 0, j = 0; i < n; ++i) {
      while(j < n && b[j] > a[i]) ++j;
      if(j < n) ++dw, ++j;
    }
    int w = 0;
    int m = n;
    for(int i = 0; i < n; ++i, --m) {
      if(b[0] < a[i]) w++;
      else {
        int j = 0;
        while(j < m && b[j] > a[i]) ++j;
        b[--j] = -1;
        sort(b, b + m); reverse(b, b + m);
      }
    }
    printf("Case #%d: %d %d\n", tst, dw, w);
  }
  return 0;
}
