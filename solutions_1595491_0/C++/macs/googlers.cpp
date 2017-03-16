#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 101

int cs,c,i,j,s,n,p;
int A[lim],S[lim];

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d%d%d",&n,&s,&p);
    for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
      S[i]=(A[i]+2)/3;
    }
    for(i=j=0;i<n && j<s;i++)
      if(A[i] && A[i]%3!=1 && S[i]==p-1)
      {
        S[i]++;
        j++;
      }
    for(i=s=0;i<n;i++)
      s+=S[i]>=p;
    printf("Case #%d: %d\n",c,s);
  }
  return 0;
}
