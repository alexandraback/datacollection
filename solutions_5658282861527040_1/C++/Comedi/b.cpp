/*************************************************************************
    > File Name: b.cpp
    > Author: implus
    > Mail: 674592809@qq.com
    > Created Time: »’  5/ 4 00:19:57 2014
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson l,m,ls
#define rson m+1,r,rs

ll A, B, K;
ll ans;

ll dp[33][2][2][2];

ll gaodp(int len, int a, int b, int k){
  if(len == -1){
    return 1;
  }
  if(dp[len][a][b][k] != -1) return dp[len][a][b][k];// && !a && !b && !k) return dp[len];
  int ac = (a == 0) ? 1:((A & (1<<len)) ? 1:0), bc = (b == 0) ? 1:((B & (1<<len)) ? 1:0);
  int klimit =( K & (1<<len) ) ? 1: 0;
  ll ans = 0;
  for(int i = 0; i <= ac; i++){
    for(int j = 0; j <= bc; j++){
      if(k == 1 && ((i & j) > klimit)) continue;
      ans += gaodp(len - 1, a && (i == ac), b && (j == bc), k && ((i & j) == klimit));
    }
  }
  //if(!a && !b && !k) dp[len] = ans;
  dp[len][a][b][k] = ans;
  return ans;
}

int main(){
  int T, icase = 1;
  scanf("%d", &T);
  while(scanf("%lld%lld%lld", &A, &B, &K) == 3){
    A--; B--; K--;
    memset(dp, -1, sizeof(dp));
    printf("Case #%d: %lld\n", icase++, gaodp(30, 1, 1, 1));
  }

  return 0;
}
