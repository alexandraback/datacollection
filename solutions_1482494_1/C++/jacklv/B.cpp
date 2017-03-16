
#include <cstdio>
#include <cstring>
#include <algorithm>
const int N =1024;
int T,t,n,s,ans,x[N],y[N],ghost[N];

int doo2() {
  register int i,flag,res=0;
  do {
    flag=0;
    for (i=1;i<=n;i++)
      if (ghost[i]&&y[i]<=s) {
        s+=ghost[i];
        //printf("Get %d ghosts at %d\n",ghost[i],i);
        ghost[i]=0;
        ans+=flag=res=1;
      } //else printf("%d && %d<=%d\n",ghost[i],y[i],s);
  } while (flag);
  return res;
}

int doo1() {
  register int i,j=0,maxy=0;
  for (i=1;i<=n;i++)
    if (ghost[i]==2&&x[i]<=s&&maxy<y[i])
      maxy=y[j=i];
  if (!j) return 0;
  ans++,s++;
  ghost[j]--;
  //printf("Get 1 ghost at %d\n",j);
  return 1;
}

int main() {

 freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
  register int i,j,k;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d%d",x+i,y+i);

    std::fill_n(ghost,n+1,2);
    for (s=ans=0;s<n*2;)
      if (!doo2())
        if (!doo1())
          break;

    printf("Case #%d: ",t);
    if (s==n*2) printf("%d",ans);
      else printf("Too Bad");
    putchar(10);
  }
  return 0;
}

