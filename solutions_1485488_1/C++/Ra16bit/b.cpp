#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
typedef pair <double, pair <int, int> > pdii;
int t,tt,i,j,k,x,y,h,n,m,a[111][111],b[111][111],w[111][111];
double p[111][111],tm,ntm,lvl,nlvl,eps=1e-9;
priority_queue <pdii, vector <pdii>, greater <pdii> > q;
int main() {
  scanf("%d",&t);
  for (tt=1; tt<=t; tt++) {
    scanf("%d%d%d",&h,&n,&m);
    for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d",&b[i][j]);
    for (i=0; i<n; i++) for (j=0; j<m; j++) {
      scanf("%d",&a[i][j]);
      p[i][j]=1e9;
    }
    p[0][0]=0;
    q.push(make_pair(0,make_pair(0,0)));
    while (!q.empty()) {
      i=q.top().second.first;
      j=q.top().second.second;
      q.pop();
      if (w[i][j]==tt) continue; else w[i][j]=tt;
      tm=p[i][j];
      lvl=h-10*tm;
      //printf("%d %d %.2lf %.2lf\n",i,j,tm,lvl);
      for (k=0; k<4; k++) {
        x=i+dx[k];
        y=j+dy[k];
        //printf("-> %d %d\n",x,y);
        if (x<0 || x>=n || y<0 || y>=m || b[x][y]-a[x][y]<50 || b[x][y]-a[i][j]<50 || b[i][j]-a[x][y]<50) continue;
        ntm=tm;
        if (b[x][y]-lvl<50) ntm+=(50-b[x][y]+lvl)/10.0;
        //printf("%.2lf\n",ntm);
        nlvl=h-10*ntm;
        //printf("%.2lf\n",nlvl);
        if (ntm<eps && p[x][y]>0) {
          p[x][y]=0;
          q.push(make_pair(0,make_pair(x,y)));
          continue;
        }
        if (nlvl-a[i][j]<20-eps) ntm+=10; else ntm+=1;
        //printf("t=%.2lf\n",ntm);
        if (ntm<p[x][y]) {
          p[x][y]=ntm;
          q.push(make_pair(ntm,make_pair(x,y)));
        }
      }
    }
    printf("Case #%d: %.8lf\n",tt,p[n-1][m-1]);
    //return 0;
  }
  return 0;
}
