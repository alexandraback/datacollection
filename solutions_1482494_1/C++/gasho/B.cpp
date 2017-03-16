#include <cstdio>
#include <vector>

using namespace std;

struct Level {
  int a, b;
  Level() {}
};

int main(void) {
  int tt; scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n; scanf("%d", &n);
    vector<Level> v(n);
    for (int i = 0; i < n; ++i)
      scanf("%d %d", &v[i].a, &v[i].b);
      
    int ans = 0;
    vector<int> s1(n, 0), s2(n, 0);
    int stars = 0;
    bool c1 = true;
    while (c1) {
      c1 = false;
      bool c2 = true;
      while (c2) {
        c2 = false;
        for (int i = 0; i < n; ++i)
          if (!s2[i] && stars >= v[i].b) {
            ++stars;
            if (!s1[i])
              ++stars;
            s1[i] = s2[i] = 1;
            ++ans;
            c1 = c2 = true;
          }
      }
      int m = -1, mi = -1;
      for (int i = 0; i < n; ++i)
        if (!s1[i] && stars >= v[i].a && v[i].b > m) {
          m = v[i].b;
          mi = i;
          c1 = true;
        }
      if (mi != -1) {
        ++stars;
        s1[mi] = 1;
        ++ans;
      }
    }
    if (stars != 2 * n)
      printf("Case #%d: Too Bad\n", tc);
    else
      printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
