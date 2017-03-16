#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2555;
const int M = 1000000007;

int n;
int cnt[N];

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n * 2 - 1; i++) {
      for (int j = 0, x; j < n; j++) {
        scanf("%d", &x); cnt[x]++;
      }
    }
    vector<int> ans;
    for (int i = 1; i < N; i++) {
      if (cnt[i] & 1) { ans.push_back(i); }
    }
    sort(ans.begin(), ans.end());
    printf("Case #%d:", C);
    for (int i = 0; i < (int)ans.size(); i++) {
      printf(" %d", ans[i]);
    }
    puts("");
  }
}
