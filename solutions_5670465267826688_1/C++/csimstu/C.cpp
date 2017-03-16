#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

// 1 - '1', 2 - 'i', 3 - 'j', 4 - 'k'
const int TAB[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 2, 3, 4}, 
  {0, 2, -1, 4, -3},
  {0, 3, -4, -1, 2},
  {0, 4, 3, -2, -1}
};

int abs(int x) {
  return x > 0 ? x : -x;
}

int mul(int a, int b) {
  int neg = (a < 0) ^ (b < 0);
  return (neg ? -1 : 1) * TAB[abs(a)][abs(b)];
}

int S[10010];

int powMul(int x, ll n) {
  int res = n & 1 ? x : 1;
  for (n >>= 1; n; n >>= 1) {
    x = mul(x, x);
    if (n & 1)
      res = mul(res, x);
  }
  return res;
}

bool solve() {
  int L;
  ll X;
  cin >> L >> X;
  char str[10010];
  scanf("%s", str);
  for (int i = 0; i < L; i++) {
    if (str[i] == 'i') S[i] = 2;
    if (str[i] == 'j') S[i] = 3;
    if (str[i] == 'k') S[i] = 4;
  }
  int S_val = 1;
  for (int i = 0; i < L; i++)
    S_val = mul(S_val, S[i]);
  int S_pow = powMul(S_val, X);
  if (S_pow != -1) return false;
  vector<int> pre(L, 0), suf(L, 0);
  map<int, pair<int,int>> memo_pre, memo_suf;
  for (int i = -1; i < L; i++) {
    int tmp;
    if (i == -1) tmp = 1;
    else if (i == 0) tmp = pre[i] = S[i];
    else tmp = pre[i] = mul(pre[i-1], S[i]);
    int req_cnt = 0;
    int acc = 1;
    for (; req_cnt < 20; req_cnt++) {
      if (mul(acc, tmp) == 2) {  // i
        break;
      }
      acc = mul(acc, S_val);
    }
    if (mul(acc, tmp) == 2) {
      if (!memo_pre.count(tmp))
        memo_pre[tmp] = make_pair(i, req_cnt);
    }
  }
  for (int i = L; i >= 0; i--) {
    int tmp;
    if (i == L) tmp = 1;
    else if (i == L - 1) tmp = suf[i] = S[i];
    else tmp = suf[i] = mul(S[i], suf[i+1]);
    int req_cnt = 0;
    int acc = 1;
    for (; req_cnt < 20; req_cnt++) {
      if (mul(tmp, acc) == 4) {  // k
        break;
      }
      acc = mul(S_val, acc);
    }
    if (mul(tmp, acc) == 4) {
      if (!memo_suf.count(tmp))
        memo_suf[tmp] = make_pair(i, req_cnt);
    }
  }

  for (auto pir_pre : memo_pre)
    for (auto pir_suf : memo_suf) {
      int l = pir_pre.second.first, r = pir_suf.second.first;
      int used_cnt = pir_pre.second.second + pir_suf.second.second + 1;
      if (l >= r) used_cnt++;
      if (used_cnt <= X)
        return true;
    }
  return false;
}
int main() {
  freopen("t.in", "r", stdin);
  freopen("t.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    printf("Case #%d: %s\n", tc, solve() ? "YES" : "NO");
  }
}
