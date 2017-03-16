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
char l[1000111];
int d[1000111];
int D[1000111];
int ok(char ch){
  return !(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
void solve(){
  int i, j, k, n, m, x, y, ans, mn=INF, mx=0, N;
  scanf("%s %d", l, &n);
  m = strlen(l);

  ans=0;
  for(i=0; i<m; i++){
    d[0] = 0;
    for(k=1, j=i; j<m; j++, k++){
      if(ok(l[j])){
	d[k] = d[k-1]+1;
	if(d[k]>=n) break;
      }else{
	d[k] = 0;
      }
    }
    ans += (m-j);
  }

  printf("%d\n", ans);
}

int main(){
  int t, T;
  scanf("%d", &T);
  for(t=1; t<=T; t++){ printf("Case #%d: ", t); solve(); }
  return ACCEPTED;
}
/* ============================================== */
