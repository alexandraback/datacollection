//Khagan

#include <algorithm>
#include <stdio.h>
#define  maxn      1000001
#define  pb        push_back
using    namespace std;

int T,n;
int Q[maxn];
int res[maxn];
bool used[maxn];

void bfs()
{
  Q[1]=1;
  res[1]=1;
  used[1]=true;
  for(int i=1,j=1 ; i<=j ; i++)
  {
    int x=Q[i];
    if(x+1<maxn && !used[x+1])
    {
      Q[++j]=x+1;
      res[x+1]=res[x]+1;
      used[x+1]=true;
    }
    int sum=0,y=x;
    while(y)
    {
      sum*=10;
      sum+=y%10;
      y/=10;
    }
    if(sum<maxn && !used[sum])
    {
      Q[++j]=sum;
      res[sum]=res[x]+1;
      used[sum]=true;
    }
  }
}

int main()
{
  freopen("A-small-attempt0.in","r",stdin);
  freopen("cikti.txt","w",stdout);
  bfs();
  scanf("%d",&T);
  for(int t=1 ; t<=T ; t++)
  {
    scanf("%d",&n);
    printf("Case #%d: %d\n",t,res[n]);
  }
  return 0;
}
