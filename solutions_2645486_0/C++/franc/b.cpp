#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <map>
#include <stdlib.h>
#include <sstream>
using namespace std;
#define ACCEPTED 0
#define F first
#define S second
#define PI (acos(-1.0))
#define EPS (1e-11)
#define INF (1<<30)
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
/* ============================================== */
int a[10000];
int gain, e, r, n;
void dfs(int d, int E, int g){
  if(d==n){
    gain=max(gain, g);
  } else {
    for(int i=0; i<=E; i++){
      dfs(d+1, min(e, E-i+r), g+i*a[d]);
    }
  }
}
void solve(){
  int i;
  scanf("%d %d %d", &e, &r, &n);
  for(i=0; i<n; i++) scanf("%d", &a[i]);
  gain=0;
  dfs(0, e, 0);
  printf("%d\n", gain);
}

int main(){
  int t, T;
  scanf("%d", &T);
  for(t=1; t<=T; t++){ printf("Case #%d: ", t); solve(); }
  return ACCEPTED;
}
/* ============================================== */
