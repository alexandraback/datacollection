#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,n,m,i,j,aa,bb,c,r;
long long a[5],b[5],x,y;
int main() {
  freopen("Cs.in","r",stdin);
  freopen("Cs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&n);
    for (m=i=0; i<n; i++) {
      scanf("%d%d%d",&aa,&c,&bb);
      for (j=0; j<c; j++) {
        a[m]=aa; b[m++]=bb+j;
      }
    }
    if (m==2 && b[0]!=b[1]) {
      if (b[0]>b[1]) swap(b[0],b[1]);
      x=(a[0]*b[1]-a[1]*b[0]+b[1]-b[0]-1)/(b[1]-b[0]);
      r=(x<360);
    } else r=0;
    printf("Case #%d: %d\n",t,r);
  }
  return 0;
}
