#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

#define INF (1<<28)
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

#define N 110
int C[N][N], F[N][N], dis[N][N];
bool vis[N][N];

priority_queue<pair<int,int> > P;
int q[N*N];


int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        memset(vis,0,sizeof(vis));
        int h,n,m;
        scanf("%d%d%d", &h, &n, &m);
        for (int i=0;i<n;i++){
          for (int j=0;j<m;j++){
            scanf("%d", &C[i][j]);
          }
        }
        for (int i=0;i<n;i++){
          for (int j=0;j<m;j++){
            scanf("%d", &F[i][j]);
          }
        }

        for (int i=0;i<n;i++){
          for (int j=0;j<m;j++){
            dis[i][j] = INF;
          }
        }

        // init
        dis[0][0] = 0;
        q[0] = 0;
        int qh, qt=1;
        P.push(make_pair(0, 0));
        for (qh=0;qh<qt;qh++){
          int x, y;
          x = q[qh]/m;
          y = q[qh]%m;

          for (int i=0;i<4;i++){
            int x2 = x + dx[i], y2 = y + dy[i];
            if (x2<0 || x2>=n || y2<0 || y2>=m)continue;
            if (dis[x2][y2]<INF)continue;
            if (F[x][y] > C[x2][y2]-50)continue;
            if (F[x2][y2] > C[x2][y2]-50)continue;
            if (F[x2][y2] > C[x][y]-50)continue;
            if (h > C[x2][y2]-50)continue;
 //           printf("~~~%d %d\n", x2, y2);
            int kk = x2 * m + y2;
            q[qt++] = kk;
            dis[x2][y2] = 0;
            P.push(make_pair(0, kk));
          }
        }
/*
       for (int i=0;i<n;i++){
          for (int j=0;j<m;j++){
            printf("%d ", dis[i][j]);
          }
          puts("");
        }
*/

        //dijkstra

        while (!P.empty()){
          int t = P.top().first;
          int pos = P.top().second;
          int x = pos / m, y = pos %m;
          P.pop();
          if (vis[x][y])continue;
          vis[x][y] = true;

          int curr_h = h - t;

          for (int i=0;i<4;i++){
            int x2 = x + dx[i], y2 = y + dy[i];
            if (x2<0 || x2>=n || y2<0 || y2>=m)continue;
            if (dis[x2][y2]<t)continue;
            if (F[x][y] > C[x2][y2]-50)continue;
            if (F[x2][y2] > C[x2][y2]-50)continue;
            if (F[x2][y2] > C[x][y]-50)continue;
            int t2;
            int kk = x2 * m + y2;
            // move now
            if (curr_h <= C[x2][y2]-50){
              if (curr_h-F[x][y] < 20){
                t2 = t + 100;
              }else{
                t2 = t + 10;
              }

            }else{
            // wait and move
              int diff = curr_h - C[x2][y2] + 50;
              if (diff > 0){
                t2 = t + diff;
                if (h-t2-F[x][y] < 20){
                  t2 += 100;
                }else{
                  t2 += 10;
                }
              }
            }
            dis[x2][y2] = t2;
            //printf("~%d %d\n", t2, kk);
            P.push(make_pair(t2, kk));
          }
        }
/*
        for (int i=0;i<n;i++){
          for (int j=0;j<m;j++){
            printf("%d ", dis[i][j]);
          }
          puts("");
        }
*/
        int ans = dis[n-1][m-1];
        printf("Case #%d: %lf\n",ti,ans/10.0);
    }
    return 0;
}
