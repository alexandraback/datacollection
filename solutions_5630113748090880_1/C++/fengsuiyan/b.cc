#include <bits/stdc++.h>

using namespace std;

const int N = 60;

int n;
int a[2 * N][N];
map<int, int> mp;

int main() {
  int t;
  scanf("%d", &t);
  for (int _ = 1; _ <= t; ++_) {
    scanf("%d", &n);
    mp.clear();
    vector<int> ans;
    for (int i = 0; i < 2 * n - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", a[i] + j);
        mp[a[i][j]]++;
      }
    }
    for (auto kv : mp) {
      if (kv.second & 1) {
        ans.push_back(kv.first);
      }
    }
    assert(ans.size() == n);
    sort(ans.begin(), ans.end());
    printf("Case #%d:", _);
    for (int i = 0; i < ans.size(); ++i) {
      printf(" %d", ans[i]);
    }
    putchar('\n');
  }
  return 0;
}
