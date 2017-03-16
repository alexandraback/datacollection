#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

#define N 1010
bool ans;
int n;
int a[N][N];
bool vis[N];

int dfs(int u){
  vis[u] = true;

  for (int v=0;v<n;v++){
    if (a[u][v]){
      if (vis[v]){
        ans = 1;
      }else{
        dfs(v);
      }
    }
  }
  return 0;
}

int main(){
  int tt; scanf("%d",&tt);
  for (int ti=1;ti<=tt;ti++){
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    ans = false;
    for (int i=0;i<n;i++){
      int t; scanf("%d", &t);
      for (int j=0;j<t;j++){
        int x; scanf("%d", &x);
        a[i][x-1] = 1;
      }
    }

    for (int i=0;i<n;i++){
      if (!vis[i]){
        memset(vis, 0, sizeof(vis));
        dfs(i);
      }
    }

    printf("Case #%d: %s\n",ti, ans?"Yes":"No");
  }
  return 0;
}

