#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <sstream>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>

using namespace std;
typedef long  long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int MAXN = 400;
const int MAXM = 400;
int vis[MAXN+1][MAXN+1][MAXM+1];
int parR[MAXN+1][MAXN+1][MAXM+1];
int parC[MAXN+1][MAXN+1][MAXM+1];
//int parT[MAXN+1][MAXN+1][MAXM+1];

queue<int> qr,qc,qz;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void bfs()
{
   vis[MAXN/2][MAXN/2][1] = 1;
   //memset(parR,-1,sizeof(parR));

   for(int t = 1; t < 500; t++) {
      for(int x = 0; x < MAXN; x++) {
         for(int y = 0; y < MAXN; y++) {
            if(vis[x][y][t] == 0) continue;
            for(int i = 0; i < 4; i++) {
               int nx = x + dx[i]*t;
               int ny = y + dy[i]*t;
               int nt = t + 1;
               if(nt > 500) continue;
               if(nx < 0 || nx > MAXN || ny < 0 || ny > MAXN) {
                  continue;

               }
               if(vis[nx][ny][nt]==1) continue;
               vis[nx][ny][nt] = 1;
               parR[nx][ny][nt]=x;
               parC[nx][ny][nt]=y;
              // parT[nx][ny][nt]=t;
            }
         }
      }
   }
  /* for(int t = 0;
   qr.push(400);
   qc.push(400);
   qz.push(1);
   while(!qr.empty()) {
         int x = qr.front();
         int y = qc.front();
         int t = qz.front();
         qr.pop();
         qc.pop();
         qz.pop();
         for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]*t;
            int ny = y + dy[i]*t;
            int nt = t + 1;
            if(nt > 500) continue;
            if(nx < 0 || nx > MAXN || ny < 0 || ny > MAXN) {
               continue;

            }
            if(vis[nx][ny][nt]) continue;
            qr.push(nx);
            qc.push(ny);
            qz.push(nt);
            vis[nx][ny][nt]=1;
         }
   }
   */

}

string genPath(int x, int y, int t)
{
   string ret = "";
   while(t > 1) {
      int nx = parR[x][y][t];
      int ny = parC[x][y][t];
      int nt = t - 1;//x][y][t];
      if(x == nx) {
         if(ny > y) ret += "S";
         else ret += "N";
      }else {
         if(nx > x) ret += "W";
         else ret += "E";
      }
     // cerr<<nx<< " "<<ny<<" "<<nt<<endl;
      x = nx;
      y = ny;
      t = nt;

   }
   reverse(ret.begin(),ret.end());
   return ret;
}

int main()
{
   freopen("B-small-attempt1.in","r",stdin);
   freopen("B-small.out","w",stdout);
   bfs();
   int T;

    cerr<<"here "<<endl;
  scanf("%d",&T);
   for(int tc = 1; tc <= T; tc++) {
      int x,y;
      scanf("%d %d",&x,&y);
      x += MAXN/2;
      y += MAXN/2;
      string path = "";
      for(int t = 1; t <= 500; t++) if(vis[x][y][t]) {
         //cerr<<t<<endl;

         path = genPath(x,y,t);

         break;
      }
      cout<<"Case #"<<tc<<": "<<path<<endl;

   }
   return 0;
}

