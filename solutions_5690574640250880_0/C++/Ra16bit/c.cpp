#include <cstdio>
using namespace std;
int t,tt,n,m,c,d,e,cur,i,j,a[55];
int main() {
  freopen("Cs.in","r",stdin);
  freopen("Cs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d",&n,&m,&c);
    printf("Case #%d:\n",t);
    d=n*m-c;
    if (d==1) {
      for (i=0; i<n; i++,puts("")) for (j=0; j<m; j++) putchar((i==0 && j==0)?'c':'*');
      continue;
    }
    if (n==1) {
      for (j=0; j<c; j++) putchar('*');
      for (; j<m-1; j++) putchar('.');
      puts("c");
      continue;
    }
    if (m==1) {
      for (j=0; j<c; j++) puts("*");
      for (; j<n-1; j++) puts(".");
      puts("c");
      continue;
    }
    for (e=2; e<=m; e++) if (2*e<=d) {
      a[0]=a[1]=e;
      cur=d-e-e;
      for (i=2; i<n; i++) {
        if (cur==e || cur-e>1) a[i]=e; else if (cur<e && cur!=1) a[i]=cur;
          else if (cur-e==1 && e!=2) a[i]=e-1; else break;
        cur-=a[i];
      }
      if (i<n || cur>0) continue;
      for (i=0; i<n; i++,puts("")) for (j=0; j<m; j++) if (i==0 && j==0) putchar('c'); else putchar((j<a[i])?'.':'*');
      break;
    }
    if (e>m) puts("Impossible");
  }
  return 0;
}
