#include<stdio.h>
#include<map>
#include<queue>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int dx[4]={1,0,0,-1}, dy[4]={0,-1,1,0};

struct Data{
    int d,x,y,w;
    Data(int d,int x,int y,int w):d(d),x(x),y(y),w(w){}
    bool operator < (const Data &a)const{ return d < a.d; }
    bool operator > (const Data &a)const{ return d > a.d; }
};


int H,n,m,c[200][200],f[200][200];
double ans;
int d[105][105][1005];

priority_queue<Data, vector<Data>, greater<Data> > Q;

void relax(int x,int y,int w,int dd){
    if (d[x][y][w]==-1 || d[x][y][w] > dd){
        d[x][y][w] = dd;
        Q.push(Data(dd,x,y,w));
    }
}

void fill(int x,int y){
    d[x][y][H]=0;
    Q.push(Data(0,x,y,H));
    FOR(i,0,4){
        int nx=x+dx[i],ny=y+dy[i];
        if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if (d[nx][ny][H]>=0) continue;
        // check moving condition
        if (!(max(H, max(f[x][y], f[nx][ny])) + 50 <= c[nx][ny] && f[nx][ny]+50<=c[x][y])) continue;
        fill(nx,ny); 
    }
}

int main(){
    int ca; scanf("%d",&ca);
    FOE(tt,1,ca){
        scanf("%d%d%d",&H,&n,&m);
        FOR(i,0,n) FOR(j,0,m) scanf("%d",&c[i][j]);
        FOR(i,0,n) FOR(j,0,m) scanf("%d",&f[i][j]);

        while (!Q.empty()) Q.pop();

        // find starting point
        memset(d,-1,sizeof(d));
        fill(0,0);

        ans = -10000;
        while (!Q.empty()){
            int x=Q.top().x,y=Q.top().y,w=Q.top().w,dd=Q.top().d;
            if (x==n-1 && y==m-1){ ans = dd; break; }
            Q.pop();
            if (d[x][y][w] < dd) continue;

            if (w > 0) 
                relax(x,y, w-1, d[x][y][w]+1);
            FOR(i,0,4){
                int nx=x+dx[i],ny=y+dy[i];
                if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
                // check moving condition
                if (!(max(w, max(f[x][y], f[nx][ny]))+50<=c[nx][ny] && f[nx][ny] + 50 <= c[x][y])) continue;
                int cost = 0;
                if (w >= f[x][y]+20) cost = 10;
                else cost = 100;
                relax(nx,ny,max(0,w-cost),dd+cost);
            }
        }
        printf("Case #%d: %.5f\n",tt,ans/10);
    }
    return 0;
}
