#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define PB push_back
#define SZ(X) ((int)(X.size()))
#define ALL(X) (X).begin(), (X).end()
#define FE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MOD 1000000007ll

const double PI=acos(-1.0);
const double EPS=1e-10;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vstr;
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
#define MAXN 300
static const int dr[4] = {0, -1, 0, 1};
static const int dc[4] = {-1, 0, 1, 0};

int C[MAXN][MAXN];
int F[MAXN][MAXN];
int vis[MAXN][MAXN];
double dist[MAXN][MAXN];

struct pqitem{
  int row,col;
  double time;
  int f;
  pqitem(){}
  pqitem(double t,int r,int c,int f): time(t),row(r),col(c),f(f){}
  
  bool operator<(const pqitem &o) const { return time>o.time;}
};

void solve(){
  int H=in();
  int N=in();
  int M=in();
  int i,j;
  for(i=0;i<N;i++) for(j=0;j<M;j++) C[i][j]=in();
  for(i=0;i<N;i++) for(j=0;j<M;j++) F[i][j]=in();
  for(i=0;i<=N;i++) for(j=0;j<=M;j++) vis[i][j]=0;
  for(i=0;i<=N;i++) for(j=0;j<=M;j++) dist[i][j]=1e100;
  
  priority_queue<pqitem> dj;
  
  dj.push(pqitem(0,0,0,0));
  //~dist[0][0]=0;
  
  pqitem act;
  double dt;
  int df;
  int vx,vy;
  
  while(!dj.empty()){
    act=dj.top();
    dj.pop();
    
    if(dist[act.row][act.col] < act.time) continue;
    if(vis[act.row][act.col]) continue;
    if(act.col==M-1 && act.row==N-1) break;
    vis[act.row][act.col]= true;
    //~cerr << act.row << " " << act.col << endl;
    //~
    
    
    for(i=0;i<4;i++){
      vx=act.row+dr[i];
      vy=act.col+dc[i];
      if(vx<0 || vy<0 || vx>=N || vy>=M) continue;
      if(vis[vx][vy]) continue;
      if(C[vx][vy]-F[vx][vy]<50) continue;
      if(C[vx][vy]-F[act.row][act.col]<50) continue;
      if(C[act.row][act.col]-F[vx][vy]<50) continue;
      
      if(!act.f) dt=(H-C[vx][vy]+50)*1./10.;
      else dt= ( (H-act.time*10) -C[vx][vy]+50)*1./10.;
      
      if(dt<=0){
        dt=0;
        df=act.f;
      }else{
        if(act.f>0) df=act.f;
        else df=1;
      }
      
      if(df) if( max(H-(act.time+dt)*10,0.) - F[act.row][act.col]>=20) dt+=1; else dt+=10;
      else dt=0;
      
      if(dist[vx][vy] < act.time+dt ) continue;
      
      dist[vx][vy]=act.time+dt;
      dj.push(pqitem(act.time+dt,vx,vy,df));
      
      
    }
  }
  
  //~assert(act.col==M-1 && act.row==N-1);
  
  if(act.f<0) printf("%.10lf\n",act.time);
  else printf("%.10lf\n",act.time);
  
}

int main(){
	//~freopen("B.in","r",stdin);
	//~freopen("B-small-attempt0.in","r",stdin); 
	//~freopen("B-small-attempt1.in","r",stdin); 
	//~freopen("B-small-attempt2.in","r",stdin); 
	freopen("B-large.in","r",stdin);
  freopen("Bout","w",stdout);
  //~freopen("Bout2","w",stdout);
  
  int C=in();
  for(int caso=1;caso<=C;caso++){
    cerr << caso << endl;
    printf("Case #%d: ",caso);
    solve();
  }
  
  return 0;
}


