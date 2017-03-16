#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <string>
using namespace std;
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
const int maxn = 10;
const int maxm = 60;
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

long long gcd(long long x, long long y) {
  if (x % y == 0) return y;

  return gcd(y, x%y);
}

void solve() {
  long long a, b;
  scanf("%lld/%lld", &a,&b);
  long long x = gcd(a, b);
  a /= x;
  b /= x;
  if (a == b) {
    puts("0");
    return;
  }
  if (b & (b-1)) {
    puts("impossible");
  } else {
    int c = 0;
      while (b > a) {
        b >>= 1;
        c++;
      }
      if (c > 40) puts("impossible");
      else printf("%d\n",c);
  }
  return;
}

int main() {
  //freopen("A-small-attempt3.in", "r", stdin);
  //freopen("A-large.in", "r", stdin);
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int cas;
  scanf("%d",&cas);
  for (int i=1; i<=cas; i++) {
    printf("Case #%d: ", i);
    //init();
    //read();
    solve();
  }
  return 0;
}

