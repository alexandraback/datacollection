#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1024
int T,t,n,s,ans,maxx,maxy,x[N],y[N],star[N];

namespace SMT_2D {
  //2D Segment Tree
  const int MaxX=2048,MaxY=2048;

  #include <memory.h>
  int Sx,Tx,Sy,Ty,Sum;
  int Ix,Iy,Iv;
  int Cxp,Cxq,Cyp,Cyq;
  int Qxp,Qxq,Qyp,Qyq,Max;
  int sum[MaxX*4][MaxY*4],
      max[MaxX*4][MaxY*4];

  void initialize(int l,int r,int d,int u) {
    Sx=l,Tx=r,Sy=d,Ty=u;
    memset(sum,0,sizeof(sum));
    memset(max,0,sizeof(max));
  }

  void insertY(int x,int y,int l,int r) {
    if (l<=Iyp&&Iyq<=r) {
      if (T[x][y]<Iv) T[x][y]=Iv;
      if (t[x][y]<Iv) t[x][y]=Iv;
      return;
    } else {
      if (t[x][y]<Iv) t[x][y]=Iv;
    }
    if (l==r) return;
    int m=l+r>>1;
    if (!((Iyq<l)||(m<Iyp))) insertY(x,y*2,l,m);
    if (!((Iyq<m+1)||(r<Iyp))) insertY(x,y*2+1,m+1,r);
  }

  void insertX(int x,int l,int r) {
    insertY(x,1,Sy,Ty);
    if (l==r) return;
    int m=l+r>>1;
    if (!((Ixq<l)||(m<Ixp))) insertX(x*2,l,m);
    if (!((Ixq<m+1)||(r<Ixp))) insertX(x*2+1,m+1,r);
  }

  void selectY(int x,int y,int l,int r) {
    if (l<=Qyp&&Qyq<=r)
      if (T[x][y]<T[x][y/2])
        T[x][y]=T[x][y/2];
    if (Qyp<=l&&r<=Qyq) {
      if (Max<t[x][y])
        Max=t[x][y];
      if (Max<T[x][y])
        Max=T[x][y];
      return;
    }
    if (l==r) return;
    int m=l+r>>1,res=-1;
    if (!((Qyq<l)||(m<Qyp))) selectY(x,y*2,l,m);
    if (!((Qyq<m+1)||(r<Qyp))) selectY(x,y*2+1,m+1,r);
  }

  void selectX(int x,int l,int r) {
    if (Qxp<=l&&r<=Qxq) {
      selectY(x,1,Sy,Ty,l<=Qxp&&Qxq<=r);
      return;
    }
    if (l==r) return;
    int m=l+r>>1,res=-1;
    if (!((Qxq<l)||(m<Qxp))) selectX(x*2,l,m);
    if (!((Qxq<m+1)||(r<Qxp))) selectX(x*2+1,m+1,r);
  }

  int getMax(int l,int r,int d,int u) {
    Max=0x80000000;
    Qxp=l,Qxq=r,Qyp=d,Qyq=u;
    selectX(1,Sx,Tx);
    return Max;
  }

  int getSum(int l,int r,int d,int u) {
    Sum=0;
    Qxp=l,Qxq=r,Qyp=d,Qyq=u;
    selectX(1,Sx,Tx);
    return Max;
  }

  int insert(int x,int y,int v) {
    Ix=l,Iy=d,Iv=v;
    insertX(1,Sx,Tx);
  }
}

int try2() {
  register int i,flag,res=0;
  do {
    flag=0;
    getSum(0,maxx,0,s);
    for (i=1;i<=n;i++)
      if (star[i]&&y[i]<=s) {
        s+=star[i];
        star[i]=0;
        ans+=flag=res=1;
      }
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
  freopen("B-large.in","r",stdin);
  freopen("large.out","w",stdout);

  register int i,j,k;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    scanf("%d",&n);
    maxx=maxy=0;
    for (i=1;i<=n;i++) {
      scanf("%d%d",x+i,y+i);
      if (maxx<x[i]) maxx=x[i];
      if (maxy<y[i]) maxy=y[i];
    }
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
