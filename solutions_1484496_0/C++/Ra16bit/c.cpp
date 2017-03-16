#include <stdio.h>
int n,i,tt,t,q,a[22],e[2200000],u[2200000];
void print(int x) {
  bool qq=false;
  for (int i=0; i<n; i++) if (x&(1<<i)) {
    if (qq) putchar(' '); else qq=true;
    printf("%d",a[i]);
  }
  puts("");
}
void rec(int l, int s, int ms) {
  if (l==n) {
    if (u[s]==tt) {
      q=tt;
      print(e[s]);
      print(ms);
    } else {
      u[s]=tt;
      e[s]=ms;
    }
    return;
  }
  rec(l+1,s,ms);
  if (q==tt) return;
  rec(l+1,s+a[l],ms|(1<<l));
}
int main() {
  scanf("%d",&t);
  for (tt=1; tt<=t; tt++) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    printf("Case #%d:\n",tt);
    rec(0,0,0);
    if (q!=tt) puts("Impossible");
  }
  return 0;
}
