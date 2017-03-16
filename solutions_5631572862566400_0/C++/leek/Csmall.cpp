#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int to[2000];
vector<int> from[2000];
bool v1[2000], v2[2000];
int num[2000];

int n;
int dfs1(int here, int notthere) {
  v1[here] = true;
  int cand = 0;
  for(int i=0; i<from[here].size(); i ++) {
    int there = from[here][i];
    if(v1[there]) continue;
    if(there == notthere) continue;
    cand = max(cand, dfs1(there, -1));
  }
  return 1+cand;
}
int dfs2(int here, int par, int cnt){
  num[here] = cnt;
  v2[here] = true;
  int there = to[here];
  int ret = 0;
  if(v2[there] && par == there) {
    for(int i=1; i<=1000; i++) v1[i] = false;
    int x = dfs1(there, here);
    int y = dfs1(here, there);
    return x + y;
  } else if (v2[there]) {
    return num[here] - num[there] +1;
  }else {
    return dfs2(there, here, cnt+1);
  }
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    scanf("%d", &n);
    for(int i=0; i<2000; i++) {
      to[i] = 0;
      from[i].clear();
      v2[i] = false; 
    }
    for(int i=1; i<=n; i++) {
      int x;
      scanf("%d", &x);
      to[i] = x;
      from[x].push_back(i);
    }
    int ret = 0;
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) v2[j] = false;
      ret = max(ret, dfs2(i, -1, 0));
    }
    printf("Case #%d: %d\n",tc,ret);


  }

  return 0;
}
