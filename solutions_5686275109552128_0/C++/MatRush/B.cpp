#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1111;

int a[MAXN];
int dp[MAXN];

vector<int> vv;

int brute(vector<int> v, int cnt) {
  int last = v[v.size() - 1];
  int res = last + cnt;
  if (last == 1) return res;
  for (int i = 1; i <= last / 2; ++i) {
    vector<int> vv = v;
    vv.push_back(0);
    vv[vv.size() - 2] = i;
    vv[vv.size() - 1] = last - i;
    sort(vv.begin(), vv.end());
    res = min(res, brute(vv, cnt + 1));
  }
  vector<int> vv = v;
  for (int i = 0; i < vv.size(); ++i) {
    if (vv[i] > 0) vv[i]--;
  }
  res = min(res, brute(vv, cnt + 1));
  return res;
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    int n;
    cin >> n;
    vv.clear();
    int lim = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      lim = max(lim, a[i]);
    }
    sort(a, a + n);
    int ans = INT_MAX;
    for (int mid = 1; mid <= lim; ++mid) {
      memset(dp, 0x3F, sizeof(dp));
      for (int i = 0; i <= mid; ++i) {
        dp[i] = 0;
      }
      for (int i = mid + 1; i <= lim; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
          dp[i] = min(dp[i], dp[j] + dp[i - j] + 1);
        }
      }
      int tmp = 0;
      for (int i = 0; i < n; ++i) {
        tmp += dp[a[i]];
      }
      ans = min(ans, tmp + mid);
    }
    // priority_queue<int> pq;
    // for (int i = 0; i < n; ++i) {
    //   pq.push(a[i]);
    // }
    // int ans = INT_MAX;
    // int cnt = 0;
    // int num = n;
    // while (1) {
    //   ans = min(ans, pq.top() + cnt);
    //   // cout << pq.top() + cnt << endl;
    //   ++cnt;
    //   if (pq.top() == 1) {
    //     break;
    //   } else {
    //     int maximum = pq.top();
    //     pq.pop();
    //     pq.push(maximum / 2);
    //     pq.push(maximum - maximum / 2);
    //     ++num;
    //   }
    // }
    // int tmp = ans;
    // // int tmp = brute(vv, 0);
    // // if (tmp != ans)
    // // int tmp = 0;
    printf("Case #%d: %d\n", T, ans);
  }
}