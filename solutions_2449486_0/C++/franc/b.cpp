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
using namespace std;
#define ACCEPTED 0
#define F first
#define S second
#define PI (acos(-1.0))
#define EPS (1e-11)
#define INF (1<<30)
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
int lawn[100][100];
/* ============================================== */
int main(){
  int t, T, N, M, i, j, maxR[100], maxC[100], ok;
  scanf("%d", &T);
  for(t=1; t<=T; t++){
    ok=1;
    scanf("%d %d", &N, &M);
    for(j=0; j<M; j++) maxC[j]=0;
    for(i=0; i<N; i++){
      maxR[i]=0;
      for(j=0; j<M; j++){
	scanf("%d", &lawn[i][j]);
	maxR[i]=max(maxR[i], lawn[i][j]);
	maxC[j]=max(maxC[j], lawn[i][j]);
      }
    }
    
    for(i=0; ok && i<N; i++)
      for(j=0; ok && j<M; j++)
	if(lawn[i][j] < min(maxR[i], maxC[j]))
	  ok=0;
    
    if(ok) printf("Case #%d: YES\n", t);
    else printf("Case #%d: NO\n", t);
  }
  
  return ACCEPTED;
}
/* ============================================== */
