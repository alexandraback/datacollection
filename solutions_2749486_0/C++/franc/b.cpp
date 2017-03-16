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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/* ============================================== */
char sol[100000];
char dir[] = "NSEW";
int ok;
long long X, Y;
void dfs(long long x, long long y, int depth){
  if(x == X && y == Y){
    ok=1;
    sol[depth] = '\0';
  } else if(depth < 35 && labs(x)<=100 && labs(y)<=100){
    for(int i=0; ok==0 && i<4; i++){
      sol[depth] = dir[i];
      dfs(x+(depth+1)*dx[i], y+(depth+1)*dy[i], depth+1);
    }
  }
}

void solve(){
  int i, j, k, n, m, x, y, ans, mn=INF, mx=0, N;
  scanf("%Ld %Ld", &X, &Y);
  ok=0;
  dfs(0, 0, 0);
  printf("%s\n", sol);
}

int main(){
  int t, T;
  scanf("%d", &T);
  for(t=1; t<=T; t++){ printf("Case #%d: ", t); solve(); }
  return ACCEPTED;
}
/* ============================================== */
