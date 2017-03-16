#include <iostream>
#include <string>

using namespace std;

const int NMAX = 8;

string ans;
string zip[NMAX];
bool g[NMAX][NMAX];
bool vis[NMAX];
int pre[NMAX];
int N;

void dfs(int cur, int num = 0, string path = "", bool back = false){
  if(!back){
    vis[cur] = true;
    ++num;
    path += zip[cur];
  }

  // for(int i = 0; i < num; ++i)
  //   cout << "  ";
  // cout << cur << " : " << back << " : " << path  << endl;

  if(num == N){
    // cout << path << " < " << ans << endl;
    if(path < ans)
      ans = path;
    vis[cur] = false;
    return;
  }

  if(pre[cur] != -1){
    dfs(pre[cur], num, path, true);
    // cout << "back end @ " << cur << endl;
  }

  for(int i = 0; i < N; ++i){
    if(g[cur][i] && !vis[i]){
      pre[i] = cur;
      dfs(i, num, path);
      pre[i] = -1;
    }
  }

  if(!back)
    vis[cur] = false;
}

int main(void){
  int T;
  cin >> T;
  for(int t = 0; t < T; ++t){
    int M;
    cin >> N >> M;

    fill_n(pre, N, -1);
    for(int i = 0; i < N; ++i){
      cin >> zip[i];
      fill_n(g[i], N, false);
    }

    for(int i = 0; i < M; ++i){
      int f, t;
      cin >> f >> t;
      g[f-1][t-1] = g[t-1][f-1] = true;
    }

    fill_n(vis, N, false);

    ans = "";
    for(int i = 0; i < N; ++i)
      ans += "99999";
    for(int i = 0; i < N; ++i){
      dfs(i);
    }

    cout << "Case #" << t+1 << ": " << ans << endl;
  }

  return 0;
}
