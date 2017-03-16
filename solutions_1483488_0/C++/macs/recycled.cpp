#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"

int cs,c,a,b,i,j,k,s,x;
int P[]={1,10,100,1000,10000,100000,1000000,10000000};
int B[2000001];

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d%d",&a,&b);
    memset(B,0,sizeof B);
    for(i=a,j=s=0;i<=b;i++)
    {
      while(P[j+1]<=i)
          j++;
      for(k=0,x=i;k<j;k++)
      {
        x=x/10+x%10*P[j];
        if(x>i && x<=b && B[x]<i)
        {
          s++;
          B[x]=i;
        }
      }
    }
    printf("Case #%d: %d\n",c,s);
  }
  return 0;
}
