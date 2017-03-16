//Khagan

#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
#define  pb        push_back
using    namespace std;

int T,C,D,V;
int ar[5];
int dp[31];
vector<int>v;

int f(int bm , int sz)
{
  int cnt=0;
  int dp2[31];
  for(int i=0 ; i<=V ; i++)
    dp2[i]=dp[i];
  for(int i=0 ; i<sz ; i++)
    if(bm&(1<<i))
    {
      cnt++;
      int x=v[i];
      for(int j=V-x ; j>=0 ; j--)
        dp2[j+x]|=dp2[j];
    }
  for(int i=0 ; i<=V ; i++)
    if(!dp2[i])
      return -1;
  return cnt;
}

int main()
{
  freopen("C-small-attempt1.in","r",stdin);
  freopen("cikti.txt","w",stdout);
  scanf("%d",&T);
  for(int t=1 ; t<=T ; t++)
  {
    scanf("%d%d%d",&C,&D,&V);
    for(int i=0 ; i<D ; i++)
      scanf("%d",&ar[i]);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0 ; i<D ; i++)
      for(int j=V-ar[i] ; j>=0 ; j--)
        dp[j+ar[i]]|=dp[j];
    int ans=0;
    for(int i=0 ; i<=V ; i++)
      if(!dp[i])
      {
        ans++;
        for(int j=V-i ; j>=0 ; j--)
          dp[j+i]|=dp[j];
      }
    printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}
