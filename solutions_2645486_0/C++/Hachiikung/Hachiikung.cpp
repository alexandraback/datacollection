/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<utility>
using namespace std;
#define REP(i,FN) for(int i=0;i<FN;i++)
#define FOR(i,ST,FN) for(int i=ST;i<=FN;i++)
#define FORD(i,FN,ST) for(int i=FN;i>=ST;i--)
#define FORX(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();i++)
#define pause system("pause")
#define S scanf
#define P printf
#define X first
#define Y second
#define pb push_back
#define PII pair<int,int>
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN(15);

int v[MAXN],dp[MAXN][MAXN];

void solve(int t){

    int E,R,n;
    S("%d%d%d",&E,&R,&n);
    FOR(i,1,n)
     S("%d",&v[i]);

    memset(dp,-1,sizeof(dp));

    dp[0][E]=0;

    FOR(i,0,n-1)
     FOR(j,0,E)
      if(dp[i][j]!=-1)
      {
          FOR(k,0,j)
           dp[i+1][min(E,j-k+R)]=max(dp[i+1][min(E,j-k+R)],dp[i][j]+k*v[i+1]);
      }

    int ans=0;

    FOR(j,0,E)
     if(dp[n][j]!=-1)
      ans=max(ans,dp[n][j]);

    P("Case #%d: %d\n",t,ans);
}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
     solve(i);

}
