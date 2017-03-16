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
#include <ctime>

using namespace std;

int x[1005];

int main() {
  freopen("in", "r", stdin); freopen("out", "w", stdout); freopen("log", "w", stderr);
  int tt; scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i <= 1000; ++i) x[i] = 0;
    for (int i = 0; i < a; ++i)
      for (int j = 0; j < b; ++j) ++x[i & j];
    int ans = 0;
    for (int i = 0; i < c; ++i) ans += x[i];
    printf("Case #%d: %d\n", cc, ans);
  }
  return 0;
}