#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 2000001

int i,j,k,cs,c,n,s;
bool f;
vector <int> V[lim];
int A[21];

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&A[i]);
    for(i=0;i<lim;i++)
      V[i].clear();
    for(i=0;i<1<<n;i++)
    {
      for(j=s=0;j<n;j++)
        if(i&1<<j)
          s+=A[j];
      V[s].push_back(i);
    }
    for(i=0;i<lim && V[i].size()<=1;i++);
    printf("Case #%d:\n",c);
    if(i<lim)
      for(k=0;k<2;k++)
      {
        for(j=s=f=0;j<n;j++)
          if(V[i][k]&1<<j)
          {
            if(f)
              printf(" ");
            f=1;
            printf("%d",A[j]);
          }
        printf("\n");
      }
    else
      printf("Impossible\n");
    cout<<flush;
  }
  return 0;
}
