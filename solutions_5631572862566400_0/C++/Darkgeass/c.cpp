#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int maxn = 1010;
int n;
int f[maxn];
int d[maxn];
char vist[maxn];
vvi p;

int dfs(int u){
  vist[u] = 1;
  int v = f[u];
//   cout << u << ' ' << v << '\n';
  if(vist[v] and d[v] != -1){
    int sol = d[u]-d[v]+1;
    d[u] = -1;
    return sol;
  }
  else if(vist[v]) return 0;
  else{
    d[v] = d[u]+1;
    int sol = dfs(v);
    d[u] = -1;
    return sol;
  }
}

int dfs2(int u){
  int sol = 0;
//   cout << u << ' ' << p[u].size() << '\n';
  for(int i = 0; i < p[u].size(); ++i){
    int v = p[u][i];
    if(v == f[u]) continue;
    sol = max(sol,dfs2(v));
  }
  return sol+1;
}

int main(){
  int t; cin >> t;
  for(int cass = 1; cass <= t; ++cass){
    cin >> n;
    p = vvi(n);
    for(int i = 0; i < n; ++i){ cin >> f[i]; --f[i]; p[f[i]].push_back(i);}
    int mcic = 0;
    memset(vist,0,sizeof(vist));
    memset(d,-1,sizeof(d));
    for(int i = 0; i < n; ++i){
      if(vist[i]) continue;
      d[i] = 0;
      mcic = max(mcic,dfs(i));
    }
//     cout << mcic << '\n';
    int sum = 0;
    for(int i = 0; i < n; ++i){
      if(f[f[i]] == i){
	sum += dfs2(i);
      }
    }
    cout << "Case #" << cass << ": ";
    cout << max(sum,mcic) << '\n';
  }
}