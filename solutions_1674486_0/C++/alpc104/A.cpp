#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define N 2048
int n,b[N];
queue<int> que;
vector<int> a[N];

int bfs(int S) {
  while (!que.empty()) que.pop();
  memset(b,0,sizeof(b));
  que.push(S); b[S]=1;
  while (!que.empty()) {
    int u=que.front();
    for (int i=0;i<a[u].size();i++) {
      int v=a[u][i];
      if (b[v]==1) return 1;
      b[v]=1;
      que.push(v);
    }
    que.pop();
  }
  return 0;
}

void init() {
  cin>>n;
  for (int i=1;i<=n;i++) {
    int m,x;
    a[i].clear();
    scanf("%d",&m);
    for (int j=1;j<=m;j++) {
      scanf("%d",&x);
      a[i].push_back(x);
    }
  }
}

int main() {
  freopen("small.in","r",stdin);
  freopen("small.out","w",stdout);
  int T;
  cin>>T;
  for (int tt=1;tt<=T;tt++) {
    init();
    int q=0;
    for (int i=1;i<=n;i++)
      if (bfs(i)) {
        q=1;
        break;
      }
    printf("Case #%d: %s\n",tt,q?"Yes":"No");
  }
}
