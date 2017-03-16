#include <bits/stdc++.h>

using namespace std;

int a, b, k;

long long dp[31][2][2][2];

long long solve(int i, bool allA, bool allB, bool allK) {
  if(i == -1) return 1;
  long long &res = dp[i][allA][allB][allK];
  if(res != -1) return res;
  res = 0;
  // 0, 0
  res += solve(i - 1, allA & (((a >> i) & 1) == 0), allB & (((b >> i) & 1) == 0), allK & (((k >> i) & 1) == 0));
  // 0, 1
  if(!allB || ((b >> i) & 1) == 1) {
    res += solve(i - 1, allA & (((a >> i) & 1) == 0), allB & (((b >> i) & 1) == 1), allK & (((k >> i) & 1) == 0));
  }
  // 1, 0
  if(!allA || ((a >> i) & 1) == 1) {
    res += solve(i - 1, allA & (((a >> i) & 1) == 1), allB & (((b >> i) & 1) == 0), allK & (((k >> i) & 1) == 0));
  }
  // 1, 1
  if((!allB || ((b >> i) & 1) == 1) && (!allA || ((a >> i) & 1) == 1) && (!allK || ((k >> i) & 1) == 1)) {
    res += solve(i - 1, allA & (((a >> i) & 1) == 1), allB & (((b >> i) & 1) == 1), allK & (((k >> i) & 1) == 1));
  }
  return res;
}

int main() {
  freopen("B-large.in", "rt", stdin);
  freopen("B-large.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int tst = 1; tst <= t; ++tst) {
    scanf("%d %d %d", &a, &b, &k);
    --a; --b; --k;
    memset(dp, -1, sizeof dp);
    printf("Case #%d: %lld\n", tst, solve(30, 1, 1, 1));
  }
  return 0;
}
