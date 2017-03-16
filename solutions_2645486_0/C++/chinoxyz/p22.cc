#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;




int T;
int E, R, N;
int v[10009];

int dp[1000][1000];
int fun(int pos, int e){
  if(pos >= N) return 0;
  int res = 0, m = 0;
  if(dp[pos][e] != -1) return dp[pos][e];
  for(int i = 0; i <= e; i++){
    m = fun(pos+1, min((e-i)+R, E)) + i*v[pos];
    if(m > res) res = m;
  }
  dp[pos][e] = res;
  return res;
}


int main(){
  int res;
  scanf("%d\n", &T);
  for(int t  = 0; t < T; t++){
    scanf("%d %d %d\n", &E, &R, &N);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++){
      scanf("%d", &v[i]);
    }
    
    res = 0;
    res = fun(0, E);
    //printf("%d %d %d %d) ", E, R, N, v[0]);
    printf("Case #%d: %d\n", t+1, res);
    //break;
  }
}
