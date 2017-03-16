// pre-written code {{{
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <iostream>
#include <cassert>
#include <set>
#define FOR(i,n) for(int _n=n,i=0;i<_n;++i)
#define FR(i,a,b) for(int _b=b,i=a;i<_b;++i)
#define CL(x) memset(x,0,sizeof(x))
#define PN printf("\n");
#define MP make_pair
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define FORSZ(i,v) FOR(i,v.size())
#define FORIT(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
///////////////////////////////////////////////////////////////////////////////////
// }}}

int H;
int a[100][100], b[100][100];
int n,m;
int t[100][100];
bool v[100][100];
bool f[100][100];
int dx[]={+1,-1,0,0};
int dy[]={0,0,+1,-1};

bool dnu(int x, int y){
  return (0<=x && x<n && 0<=y && y<m);
}

void solve(){
 scanf("%d %d %d",&H,&n,&m);
 FOR(i,n) FOR(j,m) scanf("%d",&a[i][j]);
 FOR(i,n) FOR(j,m) scanf("%d",&b[i][j]);
 CL(v); CL(t); CL(f);
 priority_queue<pair<int, pair<int,int> > > tah;
 tah.push(MP(0,MP(0,0)));
 int h = H;
 while(!tah.empty()){
   int time = -tah.top().first;
   int x = tah.top().second.first;
   int y = tah.top().second.second;
   tah.pop();
   //printf("%d %d %d\n",x,y, time);
   if(!f[x][y]){
      f[x][y] = true;
      v[x][y] = true;
      t[x][y] = time;      
      //rozsirit sa dalej..
      FOR(i,4) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(!dnu(xx,yy)) continue;        
        if(a[xx][yy] < 50 + b[xx][yy]) continue;
        if(a[x][y] < 50 + b[xx][yy]) continue;
        if(a[xx][yy] < 50 + b[x][y]) continue;         
        int ntime = time;
        ntime = max(ntime, H - ( a[xx][yy] - 50) );            
        ntime = max(ntime, H - ( a[x][y] - 50) );
        //pocitame, ci tam je voda alebo nie..
        //printf("hrntime: %d %d %d\n",xx,yy,ntime);
        if(ntime != 0)
        if(ntime <= H - (b[x][y] + 20)) ntime += 10; else ntime +=100;
        if(!v[xx][yy] || (ntime < t[xx][yy]) ) {
          v[xx][yy] = true;
          t[xx][yy] = ntime;
          tah.push(MP(-ntime,MP(xx,yy)));
        }
      }
   }
 }
 int ret = t[n-1][m-1];
 printf("%d.%d\n",ret/10,ret%10);
}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
