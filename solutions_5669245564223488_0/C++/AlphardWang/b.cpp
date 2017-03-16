#include <cstdio>
#include <cstring>
using namespace std;

char cars[120][200];
int ans, n;
int cnt[128], tr[120];
bool vis[120];

void input(){
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i){
    scanf("%s", cars[i]);
  }
}
bool checkAns(){
  memset(cnt, 0, sizeof(cnt));
  char last_c = 0;
  for (int i = 0; i < n; ++ i){
    for (char* c = cars[tr[i]]; *c != '\0'; ++ c){
      if (last_c != *c) {
        if (cnt[*c] > 0) return false;
        last_c = *c;
      }
      ++ cnt[*c];
    }
  }
  return true;
}

void dfs(int d){
  if (d >= n){
    if (checkAns()) ++ ans;
  } else {
    for (int i = 0; i < n; ++ i){
      if (!vis[i]){
        tr[d] = i;
        vis[i] = true;
        dfs(d + 1);
        vis[i] = false;
      }
    }
  }
}

void solve(){
  ans = 0;
  for (int i = 0; i < n; ++ i){
    tr[i] = i;
  }
  memset(vis, 0, sizeof(vis));
  dfs(0);
}


int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ++ ca){
    input();
    solve();
    printf("Case #%d: %d\n", ca, ans);
  }
  return 0;
}