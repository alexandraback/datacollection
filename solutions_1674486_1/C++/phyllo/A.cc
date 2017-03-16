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

int N;
int Adj[1005][1005];
bool visited[1005];
bool fnd;

void dfs(int p){
  if(visited[p]){
    fnd = true;
    return;
  }
  visited[p] = true;
  rep(i,N){
    if(!fnd && Adj[p][i]==1){
      dfs(i);
    }
  }
}

bool solve(){
  rep(i,N){
    rep(j,N) visited[j] = false;
    fnd = false;
    dfs(i);
    if(fnd) return true;
  }
  return false;
}


int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    cin >> N;
    rep(i,N) rep(j,N) Adj[i][j] = 0;

    rep(i,N){
      int m, tmp;
      cin >> m;
      rep(j,m){
        cin >> tmp; tmp--;
        Adj[i][tmp] = 1;
      }
    }
    printf("Case #%d: %s\n", t+1, (solve()?"Yes":"No"));
  }
  
  return 0;
}
