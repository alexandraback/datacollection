#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
using namespace std;
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
const int maxn = 102;
const int maxm = 10;
const int inf = 1 << 29;
int sum[maxn][maxn];
char map[maxn][maxn];
int m,n,k;
/*
void addedge(int u, int v) {
  edge[idx].v = v;
  edge[idx].next = head[u];
  head[u] = idx++;

  edge[idx].v = u;
  edge[idx].next = head[v];
  head[v] = idx++;
  return;
}

void init() {
  
}

void read() {
  scanf("%d",&n);
  for (int i=0;i<n;i++) {
    scanf("%s", map[i]);
  }
  return;
}

char tmp[maxn], fuck[maxn];

void change(int i) {
  int a = 0;
  int la = strlen(map[i]);
  int l = 0;
  while(a < la) {
    int ta = a;
    while(map[i][ta] == map[i][a]) ta++;
    tmp[l++] = map[i][a];
    a = ta;
  }
  tmp[l] = '\0';
  return;
}

bool judge() {
  change(0);
  strcpy(fuck, tmp);
  for (int i=1;i<n;i++) {
    change(i);
    if (strcmp(fuck, tmp) != 0) {
      return false;
    }
  }
  return true;
}

void make() {
  for (int i=0;i<n;i++) {
    int res = 0;
    int a = 0, l = 0;
    int la = strlen(map[i]);
    while(a < la) {
      int ta = a;
      while(map[i][ta] == map[i][a]) ta++;
      sum[i][l++] = ta - a;
      a = ta;
    }
    m = l;
  }
  return;
}

int calc(int i) {
  int res = inf;
  for (int k=1;k<=100;k++) {
    int tmp = 0;
    for (int j=0;j<n;j++) {
      tmp += ABS(k - sum[j][i]);
    }
    res = MIN(res, tmp);
  }
  return res;
}

void solve() {
  if (!judge()) {
    puts("Fegla Won");
    return;
  }

  make();

  int ans = 0;
  for (int i=0;i<m;i++) {
    ans += calc(i);
  }
  printf("%d\n",ans);
  return;
}
*/

void solve() {
  scanf("%d%d%d",&m,&n,&k);
  int ans = 0;
  for (int i=0;i<m;i++) {
    for (int j=0;j<n;j++) {
      if ((i & j) < k) ans++;
    }
  }
  printf("%d\n",ans);
  return;
}

int main() {
  //freopen("B-small-attempt0.in", "r", stdin);
  //freopen("A-large.in", "r", stdin);
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int cas;
  scanf("%d",&cas);
  for (int i=1; i<=cas; i++) {
    printf("Case #%d: ", i);
    //read();
    solve();
  }
  return 0;
}

