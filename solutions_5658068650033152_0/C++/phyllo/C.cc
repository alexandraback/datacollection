#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

int N, M, K;
int vx[4] = {-1,1,0,0};
int vy[4] = {0,0,-1,1};

int field[25][25];
int cnt[25][25];
int ret;

int need(){
  rep(i,M) rep(j,N) cnt[i][j] = 0;
  rep(i,M) rep(j,N){
    rep(k,4){
      int nx = j + vx[k];
      int ny = i + vy[k];
      if(0<=nx&&nx<N && 0<=ny&&ny<M && field[ny][nx]==1){
        cnt[i][j]++;
      }
    }
  }
  int res = 0;
  rep(i,M) rep(j,N){
    if(field[i][j]==1 && cnt[i][j] != 4){
      res++;
    }
  }
  return res;
}


void dfs(int x, int y, int k){
  int res = need();
  if(k == K){
    /*
    rep(i,M){
      rep(j,N){
        cerr << field[i][j];
      }
      cerr << endl;
    }
    cerr << "==> " << res << endl;
    cerr << endl;
    */
    if(res < ret){
      ret = res;
    }
    return;
  }

  if(x+1==N && y+1==M){
    return;
  }

  if(x+1<=N){
    field[y][x]=1;
    dfs(x+1, y, k+1);
    field[y][x]=0;
    dfs(x+1, y, k);
  }
  if(x+1==N){
    field[y][x]=1;
    dfs(0, y+1, k+1);
    field[y][x]=0;
    dfs(0, y+1, k);
  }

}


int solve(){
  if(K==1) return 1;
  if(K==2) return 2;
  if(K==3) return 3;
  if(K==4) return 4;
  if(K==5) return 4;
  
  int n = N/2, m = M/2;
  ret = M*N;
  rep(i,M) rep(j,N) field[i][j] = 0;
  dfs(0, 0, 0);
  return ret;
}

int main(){
  int T;
  cin >> T;

  for(int t=0; t<T; t++){
    cin >> N >> M >> K;
    
    cout << "Case #" << t+1 << ": " << solve() << endl;
  }
  
  return 0;
}
