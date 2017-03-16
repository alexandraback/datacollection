#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef __int64 lld;

bool ok(lld q) {
  while (q>1 && (~q&1)) q >>= 1;
  return q==1;
}

int get(lld x) {
  int ret = 0;
  while (x) {
    x >>= 1;
    ret ++;
  }
  return ret;
}

bool work(lld p,lld q) {
  if (!ok(q)) {
    return false;
  }
  int len = get(q);
  p <<= 40-len;
  printf("%d\n",40-get(p));
  return true;
}

int main() {
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int cas,ca = 0;
  scanf("%d",&cas);
  while (cas--) {
    lld p,q;
    scanf("%I64d/%I64d",&p,&q);
    lld g = __gcd(p,q);
    p /= g;
    q /= g;
    printf("Case #%d: ",++ca);
    if (!work(p,q)) puts("impossible");
  }
  return 0;
}
