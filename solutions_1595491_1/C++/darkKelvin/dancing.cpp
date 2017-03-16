#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105

using namespace std;

int n,surprise,req;
int pt[MAXN];

int maxp[MAXN][2];
int dp[MAXN][MAXN];

inline void relax(int &x,int val) { if(val>x) x=val; }

inline int solve() {
   for(int i=0;i<n;i++) {
      if(pt[i]==0) {
         maxp[i][0]=maxp[i][1]=0;
         continue;
      }
      if(pt[i]==1) {
         maxp[i][0]=maxp[i][1]=1;
         continue;
      }
      if(pt[i]%3) maxp[i][0]=pt[i]/3+1;
      else maxp[i][0]=pt[i]/3;
      maxp[i][1]=(pt[i]-2)/3+2;
   }
   memset(dp,0,sizeof(dp));
   for(int i=0;i<n;i++) {
      for(int j=0;j<=surprise;j++) {
         relax(dp[i+1][j],dp[i][j]+(maxp[i][0]>=req?1:0));
         relax(dp[i+1][j+1],dp[i][j]+(maxp[i][1]>=req?1:0));
      }
   }
   return dp[n][surprise];
}

int main(void)
{
   int t,cas=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d %d %d",&n,&surprise,&req);
      for(int i=0;i<n;i++)
         scanf("%d",pt+i);
      printf("Case #%d: %d\n",cas++,solve());
   }
   return 0;
}
