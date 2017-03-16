#include <bits/stdc++.h>
using namespace std;
int t,tt,x,y,i,j,c,cur,a[10];
vector<int> g[1000100];
int main() {
  freopen("Al.in","r",stdin);
  freopen("Al.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&x);
    if (x==0) {
      printf("Case #%d: INSOMNIA\n",t);
      continue;
    }
    y=0; c=10;
    for (i=1; c>0; i++) {
      y+=x;
      for (j=y; j>0; j/=10) {
        cur=j%10;
        if (a[cur]!=t) {
          a[cur]=t;
          c--;
        }
      }
    }
    printf("Case #%d: %d\n",t,y);
    fprintf(stderr,"Case #%d\n",t);
  }
  return 0;
}
