#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

void solve() {
  int n;
  scanf("%d", &n);
  vector<pii> hikers;

  for (int i = 0; i < n; ++i) {
    int d, h, m;
    scanf("%d%d%d", &d, &h, &m);
    for (int j = 0; j < h; ++j)
      hikers.push_back({d, -(m + j)});
  }

  sort(hikers.begin(), hikers.end());
  for (int i = 0; i < (int)hikers.size(); ++i)
    hikers[i].second *= -1;

  llint ans = (int)hikers.size();

  for (int i = 0; i < (int)hikers.size(); ++i) {
    llint t = i;
    llint tm = (llint)hikers[i].second * (360 - hikers[i].first);

    for (int j = 0; j < (int)hikers.size(); ++j) {
      if (j == i) continue;
      llint cnt = 0;
      llint tm2 = tm - (llint)hikers[j].second * (360 - hikers[j].first);
      if (tm2 < 0) {
        if (j > i) ++t;
        continue;
      }
      if (j < i) cnt++;
      cnt += tm2 / (360LL * hikers[j].second);
      t += cnt;
    }

    ans = min(ans, t);
  }

  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}

