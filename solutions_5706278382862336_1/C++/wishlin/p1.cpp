#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int cas, ans;
long long p,q,com;

long long gcdx(long long x, long long y) {
  if (x==0) return y;
  else return gcdx(y%x,x);
}

int cnt_p(long long x) {
  int ret=0;
  while (x>1 && x%2==0) {x>>=1; ++ret;}
  return x==1? ret:-1;
}

int sol() {
  int up=cnt_p(q), ret=0;
  if (up<0) return -1;
  while (p<q) {
    ++ret; q>>=1;
  }
  return ret;
}

int main() {
  scanf("%d", &cas);
  for (int k=1; k<=cas; ++k) {
    scanf("%lld/%lld", &p, &q);
    com=gcdx(p,q); p/=com; q/=com;
    printf("Case #%d: ",k);
    ans=sol();
    if (ans<0) printf("impossible\n");
    else printf("%d\n",ans);
  }
  return 0;
}
