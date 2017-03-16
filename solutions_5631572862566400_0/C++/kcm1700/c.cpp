#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++)
  {
    int n;
    scanf("%d", &n);
    vector<int> bff(n);
    vector<int> indeg(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &bff[i]);
      bff[i]--;
      indeg[bff[i]]++;
    }
    vector<int> dp(n);
    {
      queue<int> q;
      for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
          q.push(i);
        }
      }
      while (!q.empty()) {
        int cur = q.front(); q.pop();
        int next = bff[cur];
        dp[next] = max(dp[cur] + 1, dp[next]);
        if (--indeg[next] == 0) {
          q.push(next);
        }
      }
    }
    
    vector<int> visit(n);
    int vcnt = 1;
    int ans = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
      if (visit[i]) continue;
      ++vcnt;
      int p = i;
      for (;;)
      {
        if (visit[p])
          break;
        visit[p] = vcnt;
        p = bff[p];
      }
      if (visit[p] < vcnt)
        continue;
      int cnt = 1;
      int q = p;
      for (; ; cnt++) {
        ans = max(ans, cnt);
        p = bff[p];
        if (p == q) break;
      }
      if (cnt == 2) {
        q = bff[p];
        ans2 += 2 + dp[p] + dp[q];
      }
    }
    ans = max(ans, ans2);
    printf("Case #%d: %d\n", testcase, ans);
  }
  return 0;
}