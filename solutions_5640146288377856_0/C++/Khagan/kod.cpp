//Khagan

#include <algorithm>
#include <stdio.h>
using    namespace std;

int T,R,C,W;

int f(int x , int sol , int sag)
{
  if(sag==x+1)
    return W;
  else
    return W+1;
}

int main()
{
  freopen("A-small-attempt0.in","r",stdin);
  freopen("cikti.txt","w",stdout);
  scanf("%d",&T);
  for(int t=1 ; t<=T ; t++)
  {
    scanf("%d%d%d",&R,&C,&W);
    int ans=0,cnt=0;
    for(int i=1 ; i<=R ; i++)
      for(int j=W ; j<=C ; j+=W)
      {
        ans=max(ans,cnt+f(j,j-W,min(j+W,C+1)));
        cnt++;
      }
    printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}
