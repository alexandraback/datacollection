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
long long a[1000000], A;
void solve(){
  int i, j, k, n, m, x, y, ans, mn=INF, mx=0, N;
  scanf("%Ld %d", &A, &N);
  for(i=0; i<N; i++){
    scanf("%Ld", &a[i]);
  }
  sort(a, a+N);
  if(A==1LL){
    printf("%d\n", N);
    return;
  }
  ans = N;
  int adds=0;
  for(i=0; i<N; i++){
    if(a[i]<A){
      A+=a[i];
      ans = min(ans, adds+N-i-1);
    } else {
      while(A<=a[i]){
	adds++;
	A+=A-1LL;
      }
      A+=a[i];
      ans = min(ans, adds+N-i-1);
    }
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
