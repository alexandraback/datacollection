#include <cstdio>
#include <cstring>
#define N 102
#define Q 20000000
#define max(x,y) (x>y?x:y)
int T,t,n,m,h,ans;
int f[N][N],c[N][N],a[N][N],b[N][N][10001];
int top,tail,qx[Q],qy[Q],qt[Q];
const int dx[4]={0,0,1,-1},
          dy[4]={1,-1,0,0};

int conn(int x1,int y1,int x2,int y2,int h) {
  if (x2<1||n<x2||y2<1||m<y2) return 0;
  int c1=c[x1][y1],c2=c[x2][y2],
      f1=f[x1][y1],f2=f[x2][y2];
  if (c2-h<50||c2-f2<50||c2-f1<50||c1-f2<50) return 0;
  //printf("conn(%d,%d,%d,%d,%d)=1\n",x1,y1,x2,y2,h);
  return 1;
}

void dfs(int x,int y) {
  a[x][y]=1;
  //printf("Arrive at (%d,%d)\n",x,y);
  for (int i=0;i<4;i++) {
    int p=x+dx[i],q=y+dy[i];
    if (!a[p][q]&&conn(x,y,p,q,h))
      dfs(p,q);
  }
}

int main() {
  freopen("B-small-attempt1.in","r",stdin);

  register int i,j,k,x,y;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    scanf("%d%d%d",&h,&n,&m);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        scanf("%d",&c[i][j]);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        scanf("%d",&f[i][j]);

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    dfs(1,1);
    ans=0x7fffffff;
    top=tail=0;
    b[1][1][h]=1;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        if (a[i][j]) {
          qx[++tail]=i,
          qy[tail]=j,
          qt[tail]=0;
        }
    while (top<tail) {
      if (++top==Q) top=1;
      x=qx[top],
      y=qy[top];
      //printf("top=%d [%d,%d] t=%d h=%d\n",top,x,y,qt[top],h-qt[top]);
      if (x==n&&y==m) break;
      for (k=0;k<4;k++) {
        i=x+dx[k],
        j=y+dy[k];
        int hh=max(h-qt[top],0);
        if (!b[i][j][hh]&&conn(x,y,i,j,hh)) {
          b[i][j][hh]=1;
          if (++tail==Q) tail=1;
          qx[tail]=i,
          qy[tail]=j,
          qt[tail]=qt[top]+(hh-f[x][y]>=20?10:100);

        }
      }
      if (h>qt[top]) {
        qx[++tail]=x,
        qy[tail]=y,
        qt[tail]=qt[top]+1;
      }
    }
    freopen("CON","w",stdout);
    printf("Case #%d: %lf\n",t,qt[top]/10.0);
    freopen("small.out","a",stdout);
    printf("Case #%d: %lf\n",t,qt[top]/10.0);
  }
  return 0;
}
