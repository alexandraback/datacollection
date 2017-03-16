#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
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
vector<int> adj[1005];
int visited[1005];
int ret_cycle;
int ret_branch_p, ret_branch_q;

void dfs_cycle(int p, int v){
  rep(i,adj[v].size()){
    int next = adj[v][i];
    if(next == p) continue;
    if(visited[next] != -1){
      ret_cycle = max(ret_cycle, visited[v]+1);
    }else{
      visited[next] = visited[v]+1;
      dfs_cycle(v, next);
    }
  }
}

int get_cycle(vector<int> v, int root){
  rep(i,N) adj[i].clear();
  rep(i,N){
    adj[v[i]].push_back(i);
    visited[i] = -1;
  }
  ret_cycle = 0;

  visited[root] = 0;
  dfs_cycle(-1, root);

  return ret_cycle;
}

void dfs_branch(int& ret, int p, int v){
  ret = max(ret, visited[v]);
  rep(i,adj[v].size()){
    int next = adj[v][i];
    if(next == p) continue;
    if(visited[next] == -1){
      visited[next] = visited[v]+1;
      dfs_branch(ret, v, next);
    }
  }
}

int get_branch(vector<int> v, int p, int q){
  rep(i,N) adj[i].clear();
  rep(i,N){
    adj[v[i]].push_back(i);
    visited[i] = -1;
  }
  ret_branch_p = 0;
  ret_branch_q = 0;

  visited[p] = 0;
  visited[q] = 0;
  dfs_branch(ret_branch_p, q, p);
  dfs_branch(ret_branch_q, p, q);
  
  return ret_branch_p + ret_branch_q + 2;
}

int solve(vector<int> v){
  int ret = 1;
  rep(i,v.size()){
    ret = max(ret, get_cycle(v, i));
  }
  rep(i,v.size()){
    if(i == v[v[i]] && i < v[i]){
      ret = max(ret, get_branch(v, i, v[i]));
    }
  }

  return ret;
}

int solve_greedy(vector<int> v){
  vector<int> w;
  rep(i,N) w.push_back(i);
  int ret = 0;
  do {
    REP(i,1,N){
      int m = i+1;
      bool flg = true;
      rep(j,m){
        if((v[w[j]]==w[(j+1)%m] || v[w[j]]==w[(j-1+m)%m])){
          ;
        }else{
          flg = false;
        }
      }
      if(flg) ret = max(ret, m);
    }

  }while(next_permutation(ALLOF(w)));

  return ret;
}


int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    cin >> N;
    vector<int> v;
    rep(i,N){
      int a;
      cin >> a;
      a--;
      v.push_back(a);
    }
    ll ret = solve_greedy(v);
    cout << "Case #" << t+1 << ": " << ret << endl;
  }
  
  return 0;
}

