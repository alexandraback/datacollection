#include <cassert>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <set>
using namespace std;

int r, n, m, k;
long long a[100];
int cnt[9];
set <long long> ok;

void dfs( int x, long long r ) {
  if (x > 8) {
    ok.insert(r);
    return;
  }
  for (int i = 0; i <= cnt[x]; i++) {
    dfs(x + 1, r);
    r *= x;
  }
}

bool check() {
  ok.clear();
  dfs(2, 1ll);
  for (int i = 0; i < k; i++)
    if (!ok.count(a[i]))
      return false;
  return true;
}

void solve() {
  for (int i = 0; i < k; i++)
    assert(scanf("%lld", &a[i]));
  memset(cnt, 0, sizeof(cnt[0]) * 9);
  for (int i = 0; i < k; i++) {
    long long t = a[i];
    int c3 = 0, c5 = 0, c7 = 0;
    // fprintf(stderr, "i=%d, t=%lld\n", i, t);
    while (t % 7 == 0)
      t /= 7, c7++;
    while (t % 5 == 0)
      t /= 5, c5++;
    while (t % 3 == 0)
      t /= 3, c3++;
    // fprintf(stderr, "i=%d\n", i);
    cnt[3] = max(cnt[3], c3);
    cnt[5] = max(cnt[5], c5);
    cnt[7] = max(cnt[7], c7);
  }
  // for (int i = 2; i <= 8; i++)
  //   fprintf(stderr, "(%d)%d%c", i, cnt[i], "\n,"[i < 8]);
  // return;
  for (cnt[6] = 0; cnt[6] <= cnt[3]; cnt[6]++) {
    cnt[3] -= cnt[6];
    for (cnt[2] = 0; cnt[2] < 3; cnt[2]++)
    for (cnt[4] = 0; cnt[4] < 3; cnt[4]++) {
      cnt[8] = n;
      for (int x = 2; x < 8; x++)
        cnt[8] -= cnt[x];
      // for (int i = 2; i <= 8; i++)
      //   printf("%d%c", cnt[i], "\n,"[i < 8]);
      if (cnt[8] < 0)
        continue;
      if (!check())
        continue;
      for (int x = 2; x <= 8; x++)
        for (int i = 0; i < cnt[x]; i++)
          printf("%d", x);
      puts("");
      return;
    }
    cnt[3] += cnt[6];
  }
}

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1 && tn == 1);
  puts("Case #1:");

  assert(scanf("%d%d%d%d", &r, &n, &m, &k) == 4);
  for (int tt = 0; tt < r; tt++) {
    solve();
  }

  return 0;
}

