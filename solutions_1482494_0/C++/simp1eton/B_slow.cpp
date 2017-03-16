#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
using namespace std;

int testcase,N,A[MAXN],B[MAXN],F[MAXN],S[MAXN],ans,cur,it;
int dp[12][(1<<12)];
bool used[MAXN],flag;

bool cp1(int x,int y){
  if(A[x] != A[y]) return A[x] < A[y];
  return x < y;
}

bool cp2(int x,int y){
  if(B[x] != B[y]) return B[x] < B[y];
}

int main(){
  freopen("B-small-attempt1.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    scanf("%d",&N);
    for(int i=0;i<N;++i) scanf("%d%d",&A[i],&B[i]);
    for(int i=0;i<N;++i) F[i] = S[i] = i;
    sort(F,F+N,cp1);
    sort(S,S+N,cp2);
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    ans = 10 * N;
  //  for(int i=0;i<N;++i) printf("%d %d\n",F[i],S[i]);
    for(int i=0;i<=N;++i)
      for(int a=0;a<(1<<N);++a){
        if(dp[i][a] == -1) continue;
        if(i == N) ans = min(ans,dp[i][a]);
        else{
       //   printf("dp[%d][%d] = %d\n",i,a,dp[i][a]);
          int tmp = 2*i, t1;
          for(int j=0;j<i;++j)
            if( (a & (1<<S[j])) > 0) --tmp;
          for(int j=0;j<N;++j)
            if( (a & (1<<j) ) > 0) ++tmp;
      //    printf("no. of coins = %d\n",tmp);
          if(tmp >= B[S[i]]){
       //     printf("yay can go to (%d, %d)!\n",i+1,a);
            if(dp[i+1][a] == -1 || dp[i][a] + 1 < dp[i+1][a]) dp[i+1][a] = dp[i][a] + 1;
          }
          for(int j=0;j<N;++j)
            if( (a & (1<<j) ) == 0 && tmp >= A[j]){
              t1 = (a | (1<<j));
              if(dp[i][t1] == -1 || dp[i][a] + 1 < dp[i][t1]) dp[i][t1] = dp[i][a] + 1;
            }
        }
      }
    if(ans == 10*N) printf("Case #%d: Too Bad\n",TC);
    else printf("Case #%d: %d\n",TC,ans);
  }
}
