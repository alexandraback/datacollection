#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;

double p[maxn], f[maxn];

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int cass, T, a, b, i;
  double t1, t2, t3, ans;
  cin >> T;
  for(cass = 1; cass <= T; ++cass) {
    cin >> a >> b;
    f[0] = 1;
    for(i = 1; i <= a; ++i) {
      cin >> p[i];
      f[i] = f[i - 1] * p[i];
    }
    t1 = b + 2;
    t2 = (2 - f[a]) * b - a + 2 - f[a];
    ans = min(t1, t2);
    for(i = 1;i <= a; ++i) {
      t3 = f[a - i] * (2 * i + b - a + 1) + (1 - f[a - i]) * (2 * i + 2 * b - a + 2);
      ans = min(ans, t3);
    }
    printf("Case #%d: %lf\n", cass, ans);
  }
}
