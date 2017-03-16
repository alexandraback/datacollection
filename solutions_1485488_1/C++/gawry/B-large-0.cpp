#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int h,n,m,c[110][110],f[110][110];
bool b[110][110];
double d[110][110];
typedef pair<int,int> p2;
typedef pair<double,p2> state;
priority_queue<state> pq;
#define INF (1e20)
double calc(int x,int y,int x2,int y2){
  if(f[x][y]+50>c[x2][y2])return INF;
  if(f[x2][y2]+50>c[x2][y2])return INF;
  if(f[x2][y2]>c[x][y]-50)return INF;
  // h-10*time <= c[x2][y2]-50
  return max(0.0,(double)(h+50-c[x2][y2])/10);
}
#define EPS (1e-7)
void go(int x,int y){
  if(b[x][y])return;
  b[x][y]=true;
//  printf("went to %d %d\n",x,y);
  d[x][y]=0.0;
  pq.push(state(0.0,p2(x,y)));
  if(x){
    double r=calc(x,y,x-1,y);
    if(r<EPS)go(x-1,y);
  }
  if(y){
    double r=calc(x,y,x,y-1);
    if(r<EPS)go(x,y-1);
  }
  if(x+1<n){
    double r=calc(x,y,x+1,y);
    if(r<EPS)go(x+1,y);
  }
  if(y+1<m){
    double r=calc(x,y,x,y+1);
    if(r<EPS)go(x,y+1);
  }
}
double current_time;
void check(int x,int y,double c){
  if(c<d[x][y]){
    d[x][y]=c;
    pq.push(state(-c,p2(x,y)));
  }
}
void move(int x,int y,int x2,int y2){
  if(x2<0||y2<0||x2>=n||y2>=m)return;
  double next_time=max(current_time,calc(x,y,x2,y2));
  check(x2,y2,next_time+10);
  if(h-next_time*10>=f[x][y]+20)check(x2,y2,next_time+1);
}
void solve(){
  scanf("%d %d %d",&h,&n,&m);
  FOR(i,n)FOR(j,m)scanf("%d",&c[i][j]);
  FOR(i,n)FOR(j,m)scanf("%d",&f[i][j]);
  memset(b,0,sizeof(b));
  FOR(i,n)FOR(j,m)d[i][j]=INF;
  pq=priority_queue<state>();
  go(0,0);
  current_time=0.0;
  while(!pq.empty()){
    state s=pq.top();pq.pop();
    current_time=-s.first;
    if(s.second==p2(n-1,m-1)){
      printf("%.6lf\n",current_time+EPS);
      return;
    }
    //cout<<"time="<<current_time<<endl;
    move(s.second.first,s.second.second,s.second.first-1,s.second.second);
    move(s.second.first,s.second.second,s.second.first,s.second.second-1);
    move(s.second.first,s.second.second,s.second.first+1,s.second.second);
    move(s.second.first,s.second.second,s.second.first,s.second.second+1);
  }
}
main(){
  char in[100],out[100],*pos;
  strcpy(in,__FILE__);
  strcpy(out,__FILE__);
  pos=in;
  while(*pos!='.')pos++;
  strcpy(pos,".in");
  pos=out;
  while(*pos!='.')pos++;
  strcpy(pos,".out");
  freopen(in,"r",stdin);
  freopen(out,"w",stdout);
  int t;
  scanf("%d",&t);
  for(int tt=1;tt<=t;tt++){
    fprintf(stderr,"processing case %d\n",tt);
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
  freopen(out,"r",stdin);
  char c;while((c=getc(stdin))!=EOF)putc(c,stderr);
}

