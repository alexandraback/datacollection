#include <bits/stdc++.h>
using namespace std;
#define TR(i,v)       for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x)      cout<<#x<<" = "<<x<<endl
#define SIZE(p)       (int)(p).size()
#define MP(a,b)       make_pair((a),(b))
#define ALL(p)        (p).begin(),(p).end()
#define rep(i,n)      for(int i=0;i<(int)(n);++i)
#define REP(i,a,n)    for(int i=(a);i<(int)(n); ++i)
#define FOR(i,a,b)    for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,b,a)   for(int i=(int)(b);i>=(int)(a);--i)
#define CLR(x,y)      memset((x),(y),sizeof((x)))
typedef long long LL;
typedef pair<int,int> pii;
bool v[1000005];
int dp[1000005];
int main(){
  queue<int> q;
  q.push(1);v[1]=1;
  dp[1]=0;
  while(!q.empty()){
    int x=q.front();q.pop();
    int y;
    y=x+1;
    if(!v[y] && y<=1000000){
      v[y]=1;
      dp[y]=dp[x]+1;
      q.push(y);
    }
    char ss[30];sprintf(ss,"%d",x);reverse(ss,ss+strlen(ss));
    y=atoi(ss);
    if(!v[y] && y<=1000000){
      v[y]=1;
      dp[y]=dp[x]+1;
      q.push(y);  
    }
  }
  int T;scanf("%d",&T);
  FOR(cs,1,T){
    int n;scanf("%d",&n);
    printf("Case #%d: %d\n",cs,dp[n]+1);
  }
  return 0;
}