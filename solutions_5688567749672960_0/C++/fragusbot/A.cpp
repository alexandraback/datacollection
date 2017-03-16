#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

int get(int x) {
  int res = 0;
  while (x > 0) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return res;
}

int f[1000005];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    int n;
    scanf("%d", &n);
    memset(f, 0, sizeof f);
    f[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
      f[i] = f[i + 1];
      int j = get(i);
      if (j > i && j <= n) {
        if (f[j] < f[i]) {
          f[i] = f[j];
        }
      }
      f[i] += 1;
    }
    printf("%d\n", f[1]);
  }
  return 0;
}