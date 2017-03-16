/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int H,N,M;
#define MAXN 222
int F[MAXN][MAXN], C[MAXN][MAXN];
long long dp[MAXN][MAXN];
bool done[MAXN][MAXN];
priority_queue< pair<long long, pair<int,int> > > pq;

void add(int x, int y, long long d){
  if(!done[x][y] && d < dp[x][y]){
    dp[x][y] = d;
    pq.push(make_pair(-d, make_pair(x,y)));
  }
}

void go(int x,int y,int nx,int ny){
  if(nx < 0 || ny < 0 || nx >= N || ny >= M || C[nx][ny] < 50 + F[x][y] || C[nx][ny] < 50 + F[nx][ny] || C[x][y] < 50 + F[nx][ny]) return;
  long long d = dp[x][y];
  if(C[nx][ny] - H < 50) d = max(d,(long long)H - (C[nx][ny] - 50));
  if(H-max(d,0LL) >= F[x][y] + 20) d += 10;
  else d += 100;
  add(nx, ny, d);
}

bool print;
long long solve(){
  REP(i,N) REP(j,M){ done[i][j] = false; dp[i][j] = 1000000000000000LL; }
  while(!pq.empty()) pq.pop();
  add(0,0,-200000000);
  while(!pq.empty()){
    int x = pq.top().second.first, y = pq.top().second.second;
    pq.pop();
    if(done[x][y]) continue;
    done[x][y] = true;
    if(x == N-1 && y == M-1) return dp[x][y];
    FOR(dx, -1, 1) FOR(dy, -1, 1) if(dx * dx + dy * dy == 1) go(x,y,x+dx,y+dy);
  }
}

int main(int argc, char *argv[]){
  int T;
  scanf("%d",&T);
  REP(t,T){
    scanf("%d%d%d",&H,&N,&M);
    REP(i,N) REP(j,M) scanf("%d",&(C[i][j]));
    REP(i,N) REP(j,M) scanf("%d",&(F[i][j]));
    long long ans = max(0LL,solve()); 
    printf("Case #%d: %lld.%lld\n",t+1,ans/10,ans%10);
  }
  return 0;
}
