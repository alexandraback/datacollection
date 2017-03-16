#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <string>
using namespace std;
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
const int maxn = 102;
const int maxm = 60;
const int mod = 1000000007;
const int inf = 1 << 29;
/*
struct node {
  int v;
  int next;
}edge[maxm];
int head[maxn],val[maxn];
int m,n,idx,bj,p;
*/
/*
void init() {
  memset(head,-1,sizeof(head));
  idx = 0;
  bj = -1;
  p = -1;
  return;
}

void addedge(int u, int v) {
  edge[idx].v = v;
  edge[idx].next = head[u];
  head[u] = idx++;

  edge[idx].v = u;
  edge[idx].next = head[v];
  head[v] = idx++;
  return;
}

void read() {
  scanf("%d%d",&n,&m);
  int tmp = inf;
  for (int i=0;i<n;i++) {
    scanf("%d",&val[i]);
    if (val[i] < tmp) {
      tmp = val[i];
      bj = i;
    }
  }
  int u,v;
  for (int i=0;i<m;i++) {
    scanf("%d%d",&u,&v);
    u--;
    v--;
    addedge(u,v);
  }
  return;
}*/

char map[maxn][maxn];
bool vis[maxn], fuck[maxn];
int rec[30];
long long x;
int n, h;

int findHead() {
  return -1;
}

void read() {
  scanf("%d",&n);
  for (int i=0;i<n;i++) {
    scanf("%s", map[i]);
  }
  return;
}

int dfs(int st) {
  int ans = 0;
  bool flag = false;
  for (int i=0;i<n;i++) {
    if (vis[i]) continue;
    if (map[i][0] - 'a' == st) {
      flag = true;
      int len = strlen(map[i]);
      for (int j=0;j<len;j++) {
        int x = map[i][j] - 'a';
        if (x != st && rec[x]) return 0;
      }
      vis[i] = true;
      fuck[i] = true;
      for (int j=0;j<len;j++) {
        rec[map[i][j] - 'a']++;
      }

      ans += dfs(map[i][len-1] - 'a');

      for (int j=0;j<len;j++) {
        rec[map[i][j] - 'a']--;
      }
      vis[i] = false;
    }
  }
  if (flag == false) ans = 1;
  return ans;
}

void solve() {
  memset(vis,false,sizeof(vis));
  memset(fuck,false,sizeof(fuck));
  memset(rec,0,sizeof(rec));
  long long res = 1;
  int cnt = 0;
  for (int i=0;i<26;i++) {
    if (rec[i] == false) {
      int ans = dfs(i);
      if (ans == 0) {
        res = 0;
        break;
      }
      cnt++;
      res = (res * ans) % mod;
    }
  }
  for (int i=2;i<=cnt;i++) {
    res = (res * i) % mod;
  }
  cout << res << endl;
  return;
}

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  //freopen("A-large.in", "r", stdin);
  freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int cas;
  scanf("%d",&cas);
  for (int i=1; i<=cas; i++) {
    printf("Case #%d: ", i);
    //init();
    read();
    solve();
  }
  return 0;
}

