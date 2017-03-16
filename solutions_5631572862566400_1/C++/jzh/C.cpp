//my magic will tear you apart!
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
const int N = 1010;
int t, f[N], dist[N], vis[N];
bool b[N];
vector<int> v[N];

int dfs(int nd, int fa) {
  if(vis[nd]) return 0;
  vis[nd] = 1;
  int sz = 1;
  int maxa = 0;
  for(int i = 0; i < v[nd].size(); i++) {
    int nd2 = v[nd][i];
    if(nd2 != fa) {
      maxa = max(maxa, dfs(nd2, nd));
    }
  }
  return sz + maxa;
}
int main() {
  if(fopen("C.in","r")) freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  cin >> t;
  for(int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    int n;
    cin >> n;
    memset(f,0,sizeof(f));
    memset(b,0,sizeof(b));
    memset(vis,0,sizeof(v));
    memset(dist, 0, sizeof(dist));
    for(int j = 1; j <= n; j++) {
      scanf("%d", f + j);
    }
    for(int j = 1; j <= n; j++) {
      if(f[f[j]] == j) {
        b[j] = 1;
      }
    }
    for(int j = 0; j < N; j++) {
      v[j].clear();
    }

    for(int j = 1; j <= n; j++) {
      v[f[j]].pb(j);
    }
    int noncyc = 0;
    for(int j = 1; j <= n; j++) {
      if(b[j]) {
        if(v[j].size() == 1 && v[f[j]].size() == 1) {
          noncyc++;
          vis[j] = 1;
          vis[f[j]] = 1;
        } else {
          vis[f[j]] = 1;
          int cval = dfs(j, -1);
          noncyc += cval;
          vis[f[j]] = 0;
        }
      }
    }
    int cyc = 0;

    for(int j = 1; j <= n; j++) {
      if(b[j]) continue;
      int cur = j;
      int cnt = 0;
      while(!vis[cur]) {
        vis[cur] = j + 5;
        dist[cur] = cnt++;
        cur = f[cur];
      }
      if(vis[cur] == j + 5) {
        cyc = max(cyc, cnt - dist[cur]);
      }
      
    }
    //cout << "2: " << cyc << " " << noncyc << endl;
    cout << max(cyc, noncyc) << endl;
  }
  return 0;
}