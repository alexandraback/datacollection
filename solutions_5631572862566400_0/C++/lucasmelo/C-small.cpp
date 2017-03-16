#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


#define MAX 2000
int vis[MAX];
int hei[MAX];
int nxttim;
int nxtpath;


struct {
  int path_id;
  int through;
  int len;
} dp[MAX];

int n;
int bff[MAX];

int pathlen[MAX];

void solve(int v) {
  vis[v] = 1;

  int u = bff[v];
  if (vis[u] == 2) {
    if (dp[u].path_id > 0) {
      dp[v].path_id = dp[u].path_id;
      dp[v].through = dp[u].through;
      dp[v].len = dp[u].len + 1;
    } else {
      dp[v].path_id = 0;
      dp[v].len = 1;
    }
  } else if(vis[u] == 1) {
    dp[v].path_id = 0;
    dp[v].len = hei[v] - hei[u] + 1;
    if (dp[v].len == 2) {
      dp[v].path_id = ++ nxtpath;
      dp[v].through = v;
      dp[v].len = 1;
    }
  } else {
    hei[u] = hei[v] + 1;
    solve(u);
    if (dp[u].path_id > 0) {
      dp[v].path_id = dp[u].path_id;
      if (bff[u] == v) {
        dp[v].through = v;
        dp[v].len = 1;
      } else {
        dp[v].through = dp[u].through;
        dp[v].len = dp[u].len + 1;
      }
    } else {
      dp[v].path_id = 0;
      dp[v].len = dp[u].len;
    }
  }

  vis[v] = 2;
}

int main() {
  ios :: sync_with_stdio(0);

  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {

  nxtpath =  0;
    memset(vis, 0, sizeof(vis));
    memset(hei, 0, sizeof(hei));
    memset(pathlen, 0, sizeof(pathlen));

    cin >> n;
    for(int i=0; i<n; ++i) {
      cin >> bff[i];
      --bff[i];
    }

    for(int i=0; i<n; i++) {
      if (vis[i] == 0) {
        solve(i);
      }
    }

    int plen = 0;
    int maxcircle = 0;
    for(int i=0; i<n; i++) {
      if (dp[i].path_id == 0) {
        maxcircle = max(maxcircle, dp[i].len);
      } else {
        pathlen[dp[i].through] = max( pathlen[dp[i].through], dp[i].len );
      }
    }
    for(int i=0; i<n; ++i) {
      plen += pathlen[i];
    }

    printf("Case #%d: %d\n", cn, max(plen, maxcircle));
  }
  return 0;
}
