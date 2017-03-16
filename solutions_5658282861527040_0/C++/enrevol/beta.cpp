#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int cnt[1010];

int main() {
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  int tt;
  scanf("%d", &tt);
  for (int nc = 1; nc <= tt; ++nc) {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < a; ++i)
      for (int j = 0; j < b; ++j) {
        ++cnt[i & j];
        assert((i & j) <= 1000);
      }
    int ans = 0;
    for (int i = 0; i < k; ++i)
      ans += cnt[i];
    printf("Case #%d: %d\n", nc, ans);
  }
}
