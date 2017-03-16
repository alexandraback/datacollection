#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int T,n,m,h,f[200][200],c[200][200],b[200][200];
double d[200][200];
int que[100000][2];
const int vec[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
double check(int x1,int y1, int x2, int y2){
    if(x2<0 || y2<0 || x2>=n || y2>=m) return 1e10;
    if(c[x2][y2]-f[x2][y2]<50) return 1e10;
    if(c[x2][y2]-f[x1][y1]<50) return 1e10;
    if(c[x1][y1]-f[x2][y2]<50) return 1e10;

    double x=0;
    if(c[x2][y2]-h<50) x=(h-c[x2][y2]+50)/10.0;
   // if(c[x1][y1]-h<50) x=max((h-c[x1][y1]+50)/10.0,x);
    return x;
}
void bfs(){
    int x=0,y=1;
    que[0][0]=que[0][1]=0;
    while(x<y){
        int p=que[x][0],q=que[x][1];
        for(int k=0;k<4;++k){
            int i=p+vec[k][0], j=q+vec[k][1];
            if(check(p,q,i,j)<1e-7 && b[i][j]==0){
                b[i][j]=1;
                d[i][j]=0;
                que[y][0]=i;
                que[y][1]=j;
                ++y;
            }
            if(check(p,q,i,j)<1e9){
                double t=check(p,q,i,j);
                if(h-t*10-f[p][q]>20-1e-7) t+=1;
                    else t+=10;
                if(d[i][j]>t) d[i][j]=t;
            }
        }
        ++x;
    }
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&T);
    for(int cs=1;cs<=T; ++cs){
        scanf("%d%d%d",&h,&n,&m);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j) scanf("%d",&c[i][j]);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j) scanf("%d",&f[i][j]);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                d[i][j]=1e10;
        memset(b,0,sizeof(b));
        b[0][0]=1;
        d[0][0]=0;
        bfs();
        while(b[n-1][m-1]==0){
            int x,y;
            double w=1e9;
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j)
                    if(b[i][j]==0 && d[i][j]<w){
                        w=d[i][j];
                        x=i;y=j;
                    }
            b[x][y]=1;
            for(int k=0;k<4;++k){
                int i=x+vec[k][0], j=y+vec[k][1];
                if(b[i][j]==0){
                    double t=max(check(x,y,i,j),w);
                    if(t>1e9)continue;
                    if(h-t*10-f[x][y]>20-1e-7) t+=1;
                        else t+=10;
                    if(d[i][j]>t) d[i][j]=t;
                }
            }
        }

        printf("Case #%d: %.6f\n",cs,d[n-1][m-1]);
    }
    return 0;
}
