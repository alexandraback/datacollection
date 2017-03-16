#include<cstdio>
#include<vector>

using namespace std;

#define range(i, a, b) for(int i(a); i < (b); i++)
#define rep(i, n) range(i, 0, n)

const int MAX_N = 1005;

int n, m;
bool yes;
bool found[MAX_N];
vector<int> adj[MAX_N];

inline void dfs(int u){
  found[u] = true;
  rep(i, adj[u].size()){
    int v = adj[u][i];
    if(not found[v]){
      dfs(v);
      if(yes){
	return;
      }
    }
    else{
      yes = true;
      return;
    }
  }
}

int main(){
  int T;
  freopen("ans.txt", "w", stdout);
  scanf("%d", &T);
  range(t, 1, T + 1){
    yes = false;
    rep(i, n){
      adj[i].clear();
    }
    scanf("%d", &n);
    rep(i, n){
      scanf("%d", &m);
      rep(j, m){
	int x;
	scanf("%d", &x);
	adj[i].push_back(x - 1);
      }
    }
    rep(i, n){
      rep(j, n){
	found[j] = false;
      }
      dfs(i);
      if(yes){
	break;
      }
    }
    printf("Case #%d: %s\n", t, yes? "Yes": "No");
  }
}
