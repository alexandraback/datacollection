#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define f(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n)  f(i, 0, n)

const int N = 105;
typedef long long ll;
int n, m;
ll na[N], ta[N], nb[N], tb[N];
ll dp[N][N];

ll solve(int, int);
ll startA(int, int, ll);
ll startB(int, int, ll);

ll startA(int i, int j, ll remA) {
  ll res = solve(i + 1, j);
  ll sumB = 0;
  for(int k = j; k < m; k++) if(ta[i] == tb[k]) {
    if(remA > nb[k]) {
      remA -= nb[k];
      sumB += nb[k];
      res = max(res, sumB + solve(i + 1, k + 1));
    }
    else {
      ll remB = nb[k] - remA;
      sumB += remA;
      res = max(res, sumB + startB(i + 1, k, remB));
      break;
    }
  }
  return res;
}


ll startB(int i, int j, ll remB) {
  ll res = solve(i, j + 1);
  ll sumA = 0;
  for(int k = i; k < n; k++) if(ta[k] == tb[j]) {
    if(remB > na[k]) {
      remB -= na[k];
      sumA += na[k];
      res = max(res, sumA + solve(k + 1, j + 1));
    }
    else {
      ll remA = na[k] - remB;
      sumA += remB;
      res = max(res, sumA + startA(k, j + 1, remA));
      break;
    }
  }
  return res;
}

ll solve(int i, int j) {
  if(i >= n || j >= m) return 0;
  ll &d = dp[i][j];
  if(d != -1) return d;

  ll res = 0;
  res = max(solve(i + 1, j), solve(i, j + 1));

  if(ta[i] == tb[j]) {
    if(na[i] == nb[j]) {
      res = max(res, na[i] + solve(i + 1, j + 1));
    }
    else if(na[i] > nb[j]) {
      res = max(res, startA(i, j, na[i]));
    }
    else {
      res = max(res, startB(i, j, nb[j]));
    }
  }
  return d = res;
}

int main(){
  int T; scanf("%d", &T); for(int test = 1; test <= T; test++) {
    printf("Case #%d: ", test);
    scanf("%d %d", &n, &m);
    rep(i, n) {
      scanf("%lld %lld", &na[i], &ta[i]);
    }
    rep(i, m) {
      scanf("%lld %lld", &nb[i], &tb[i]);
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(0, 0));
  }
}
