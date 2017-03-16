#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void solve() {
  long long a,b,c,d;
  scanf("%lld/%lld", &a, &b);
  c=__gcd(a,b);
  a/=c;
  b/=c;
  d=log2(b);
  if ((b&(-b))!=b || d>40) {
    puts("impossible");
    return;
  }
  while (a>=2) {
    d--;
    a/=2;
  }
  printf("%lld\n", d);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
/*
*/