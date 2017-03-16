#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1024
int T,t,n,s,ans,x[N],y[N],star[N];

int try2() {
  register int i,flag,res=0;
  do {
    flag=0;
    for (i=1;i<=n;i++)
      if (star[i]&&y[i]<=s) {
        s+=star[i];
        //printf("Get %d stars at %d\n",star[i],i);
        star[i]=0;
        ans+=flag=res=1;
      } //else printf("%d && %d<=%d\n",star[i],y[i],s);
  } while (flag);
  return res;
}

int try1() {
  register int i,j=0,maxy=0;
  for (i=1;i<=n;i++)
    if (star[i]==2&&x[i]<=s&&maxy<y[i])
      maxy=y[j=i];
  if (!j) return 0;
  ans++,s++;
  star[j]--;
  //printf("Get 1 star at %d\n",j);
  return 1;
}

int main() {
  //freopen("in.txt","r",stdin);
  freopen("B-small-attempt1.in","r",stdin);
  freopen("small.out","w",stdout);

  register int i,j,k;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d%d",x+i,y+i);

    std::fill_n(star,n+1,2);
    for (s=ans=0;s<n*2;)
      if (!try2())
        if (!try1())
          break;

    printf("Case #%d: ",t);
    if (s==n*2) printf("%d",ans);
      else printf("Too Bad");
    putchar(10);
  }
  return 0;
}
