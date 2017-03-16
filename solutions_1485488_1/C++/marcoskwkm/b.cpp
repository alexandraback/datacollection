#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

#define debug(args...) fprintf(stderr,args);

typedef long long lint;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 200;

int h,n,m;

int C[MAXN][MAXN],F[MAXN][MAXN];
double dist[MAXN][MAXN];
bool foi[MAXN][MAXN];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool valid(int x,int y) {
    return x>=0 && y>=0 && x<n && y<m;
}

void dfs(int x,int y) {
    foi[x][y] = 1;
    dist[x][y] = 0;
    for(int a=0;a<4;++a) {
        int nx = x+dx[a], ny = y+dy[a];
        if(valid(nx,ny) && !foi[nx][ny]) {
            if(C[nx][ny]-F[nx][ny] < 50) continue;
            if(C[nx][ny]-max(h,F[x][y]) < 50) continue;
            if(C[x][y] - max(h,F[nx][ny]) < 50) continue;
            dfs(nx,ny);
        }
    }
}
        

void dijkstra() {
    int vx,vy;
    double d;
    while(1) {
        d = LINF;
        vx = -1;
        for(int a=0;a<n;++a)
            for(int b=0;b<m;++b)
                if(!foi[a][b] && dist[a][b] < d) {
                    vx = a; vy = b;
                    d = dist[a][b];
                }
        if(vx==-1) break;
        foi[vx][vy] = 1;
        for(int a=0;a<4;++a) {
            int nx = vx+dx[a], ny = vy+dy[a];
            if(valid(nx,ny) && !foi[nx][ny]) {
                if(F[nx][ny] + 50 > C[nx][ny]) continue;
                double curH = max(h-10*d,(double)F[vx][vy]);
                double nH = max(h-10*d,(double)F[nx][ny]);
                if(C[nx][ny]-F[vx][vy] < 50 || C[vx][vy]-F[nx][ny] < 50) continue;
                double t = max( (50-(C[nx][ny]-(h-10*d)))/10,0.0);
                if(h-10*(d+t) - F[vx][vy] < 20) {
                    dist[nx][ny] = min(dist[nx][ny], d+t+10);
                }
                else dist[nx][ny] = min(dist[nx][ny], d+t+1);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        scanf("%d%d%d",&h,&n,&m);
        for(int a=0;a<n;++a)
            for(int b=0;b<m;++b)
                scanf("%d",&C[a][b]);
        for(int a=0;a<n;++a)
            for(int b=0;b<m;++b)
                scanf("%d",&F[a][b]);
        for(int a=0;a<n;++a) {
            for(int b=0;b<m;++b) {
                foi[a][b] = 0;
                dist[a][b] = INF;
            }
        }
        dfs(0,0);
        memset(foi,0,sizeof(foi));
        dijkstra();
        printf("Case #%d: %.6lf\n",t,dist[n-1][m-1]);
    }        
    return 0;
}
