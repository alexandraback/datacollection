#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

const int maxn = 1000000 + 10;
int dp[maxn], tr[maxn];
int N;

int rev_num(int x) {
  int tmp = 0;
  while (x > 0) {
    tmp = tmp * 10 + x % 10;
    x /= 10;
  }
  return tmp;
}

void pre_dp() {
  for (int i = 0; i != maxn; i++) {
    dp[i] = i + 1;
  }
  dp[1] = 1;
  tr[1] = 0;
  for (int i = 1; i < maxn; i++) {
    if (i + 1 < maxn) {
      if (dp[i] + 1 < dp[i+1]) {
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        tr[i+1] = i;
      }
    }
    int tmp = rev_num(i);
    if (tmp < maxn && tmp > i && dp[i] + 1 < dp[tmp]) {
      dp[tmp] = min(dp[tmp], dp[i] + 1);
      tr[tmp] = i;
    }
  }
}

int main()
{
  pre_dp();
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A_small.out", "w", stdout);
  int TextN;
  cin >> TextN;
  for (int TT = 1; TT <= TextN; TT++) {
    cin >> N;
    cout << "Case #" << TT << ": " << dp[N] << endl;
  }
  return 0;
}