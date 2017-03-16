#include <iostream>
using namespace std;
using ll = long long;
using ld = long double;

ll get(ll i, ll C, ll K, ll m) {
  //printf("gets(%d,%d,%d,%d)\n",i,C,K,m);
  ll s = 0;
  ll x = 1;
  for (int j = i+C-1; j >= i; --j) {
    if (j < i+m) {
      s += j*x;
    }
    x*=K;
  }
  return s+1;
}

void solve(ll K, ll C, ll S) {
  if (S*C < K) {
    printf("IMPOSSIBLE\n");
    return;
  }
  int i;
  for (i = 0; i < K-C; i+=C) {
    printf("%lld ", get(i, C, K, C));
  }
  printf("%lld\n", get(i,C,K,K-i));
  return;
}

int main() {
  int T, K, C, S;
  scanf("%d",&T);
  for (int i = 1; i <= T; ++i) {
    scanf("%d%d%d",&K,&C,&S);
    printf("Case #%d: ",i);
    solve(K,C,S);
  }
  return 0;
}
