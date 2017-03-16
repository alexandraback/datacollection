#include <bits/stdc++.h>
using namespace std;
int t,tt,k,c,s,i,j,cur;
long long e,prev;
int main() {
  freopen("Ds.in","r",stdin);
  freopen("Ds.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d",&k,&c,&s);
    printf("Case #%d:",t);
    if (c*s<k) { puts("IMPOSSIBLE"); continue; }
    prev=-1;
    for (i=0; i<s; i++) {
      for (e=j=0; j<c; j++) {
        cur=min(i*c+j,k-1);
        e=e*k+cur;
      }
      if (e!=prev) {
        prev=e;
        printf(" %I64d",e+1);
      } else break;
    }
    puts("");
    fprintf(stderr,"Case #%d\n",t);
  }
  return 0;
}
