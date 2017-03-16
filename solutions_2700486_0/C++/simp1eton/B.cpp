#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define MAXN 1000005
#define MAXNTRIALS 5000000
using namespace std;

typedef double LF;
int testcase,N,X,Y,H,inc,len,dp[25][25];
int tmp,val,denom,max_len;
LF ans;
bool checking;

int choose(int x,int y){
  if(dp[x][y] != 0) return dp[x][y];
  if(x == y || y == 0) dp[x][y] = 1;
  else dp[x][y] = choose(x-1,y-1) + choose(x-1,y);
  return dp[x][y];
}

void simulate(int TOT,int Q,int MAX){
 // if(checking) printf("YAY!\n");
  int cnt = 0;
  if(TOT > MAX){
    Q -= (TOT - MAX);
    TOT -= 2 * (TOT - MAX);
  }
 // if(checking) printf("TOT = %d, Q = %d, MAX = %d\n",TOT,Q,MAX);
  for(int z=0;z<MAXNTRIALS;++z){
    int t = 0;
    for(int i=0;i<TOT;++i){
      if(rand()&1) ++t;
      if(t >= Q){
        ++cnt;
        break;
      }
    }
  }
  ans = (LF)(cnt)/(LF)(MAXNTRIALS); 
}

int main(){
  srand(time(NULL));
  freopen("B-small-attempt2.in","r",stdin);
  //freopen("ans.txt","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    scanf("%d%d%d",&N,&X,&Y);
    if(X < 0) X *= -1;
    H = 1, inc = 1,len = 0;
    while(inc += 4){
      if(H + inc > N) break;
      H += inc;
      len += 2; 
    }
    ans = 0.0;
    if(X + Y <= len) ans = 1.0;
    else if(X + Y > len + 2 || (X + Y == len + 2 && (H == N || X == 0))) ans = 0.0;
    else if(H < N){
      max_len = (inc - 1)/2;
      tmp = max_len - X + 1,val = 0, denom = 0;
    //  simulate(N-H,tmp,max_len);
      for(int i=max(tmp,N-H-max_len);i<=min(max_len,N-H);++i) val += choose(N-H,i);
      for(int i=max(0,N-H-max_len);i<=min(max_len,N-H);++i) denom += choose(N-H,i);
      ans = (LF)(val) / (LF)(denom);
    }
   // if(TC == 35) printf("N = %d, X = %d, Y = %d, H = %d, tmp = %d, max_len = %d, val = %d, denom = %d\n",N,X,Y,H,tmp,max_len,val,denom);
    printf("Case #%d: %.6lf\n",TC,ans);
  }
}
