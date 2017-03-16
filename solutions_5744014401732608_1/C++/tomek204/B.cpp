#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll b, m;

void solve() {
  scanf("%lld%lld", &b, &m);
  if (m > (1LL<<(b-2))) {
    printf("IMPOSSIBLE\n");
    return;
  }
  printf("POSSIBLE\n");
  for (ll i = 0; i < b-1; i++) {
    for (ll j = 0; j < b-1; j++) {
      printf("1");
    }
    if (m&(1<<i)) printf("1");
    else printf("0");
    printf("\n");
  }
  for (ll i = 0; i < b; i++) printf("0");
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  for (int ct = 1; ct <= t; ct++) {
    printf("Case #%d: ", ct);
    solve();
  }
  return 0;
}
