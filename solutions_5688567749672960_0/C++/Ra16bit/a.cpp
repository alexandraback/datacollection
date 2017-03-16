#include <cstdio>
using namespace std;
const int MX=10000100;
int t,tt,fi,fr,x,y,cur,a[MX],q[MX];
int main() {
  freopen("As.in","r",stdin);
  freopen("As.out","w",stdout);
  scanf("%d",&tt);
  fi=0; q[0]=a[1]=fr=1;
  while (fi<fr) {
    x=q[fi++];
    cur=a[x]+1;
    if (x+1<MX && a[x+1]==0) {
      a[x+1]=cur; q[fr++]=x+1;
    }
    for (y=0; x>0; x/=10) y=y*10+x%10;
    if (y<MX && a[y]==0) {
      a[y]=cur; q[fr++]=y;
    }
  }
  for (t=1; t<=tt; t++) {
    scanf("%d",&x);
    printf("Case #%d: %d\n",t,a[x]);
  }
  return 0;
}
