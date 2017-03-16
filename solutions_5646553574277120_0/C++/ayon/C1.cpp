#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);
#define AB(a) ((a)<(0) ? (-(a)) : (a))
#define EQ(a,b) ( (fabs((a)-(b))<EPS) ? (1) : (0))





typedef long long LL;
//typedef __int64 LL;




bool dp[10100];
int C,n,V;
int coins[500];


bool Done()
{
  int i;
  for(i=1;i<=V;i++)
    if(dp[i]==0)
      return 0;
  return 1;
}


void doIt()
{
  int i,j;
  for(i=1;i<=V;i++)
    if(dp[i]==0) break;
  for(j=V;j>=i;j--)
  {
    dp[j]|=dp[j-i];
  }
}



int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int i,j,k,T,cs;
    scanf("%d",&T);

    for(cs=1;cs<=T;cs++)
    {
      printf("Case #%d: ",cs);
      memset(dp,0,sizeof(dp));



      //n=coins
      scanf("%d %d %d",&C,&n,&V);

      for(i=0;i<n;i++)
      {
        scanf("%d",&coins[i]);
      }


      dp[0]=1;
      for(i=0;i<n;i++)
      {
        for(k=1;k<=C;k++)
        {
          for(j=V;j>=coins[i];j--)
          {
            dp[j]|=dp[j-coins[i]];
          }
        }
      }



      int ans=0;

      while(!Done())
      {
        for(j=1;j<=C;j++)
          doIt();
        ans++;
      }

      printf("%d\n",ans);




    }


    return 0;
}
