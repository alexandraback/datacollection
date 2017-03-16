#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,it,i,j,n,s,a[222];
double l,r,h,e,cur;
int main() {
  scanf("%d",&t);
  for (tt=1; tt<=t; tt++) {
    scanf("%d",&n);
    for (s=i=0; i<n; i++) { scanf("%d",&a[i]); s+=a[i]; }
    printf("Case #%d:",tt);
    for (j=0; j<n; j++) {
      l=0; r=1;
      for (it=0; it<200; it++) {
        h=(l+r)*0.5;
        cur=a[j]+h*s;
        for (e=i=0; i<n; i++) if (i!=j) e+=max(0.0,(cur-a[i])/s);
        if (h+e>1) r=h; else l=h;
      }
      printf(" %.10lf",(l+r)*50);
    }
    puts("");
  }
  return 0;
}
