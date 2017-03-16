#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int T;
int x,y;
int main()
{
  //  freopen("B-small-attempt0.in","r",stdin);
  //  freopen("B-small-attempt0.out","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    int ans;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%d %d",&x,&y);
    printf("Case #%d: ",ii);
    if(x>=0)
     {
     for(i=0;i<x;i++)
      {
        printf("WE");
      }
     }
    else
     {
       x*=-1;
       for(i=0;i<x;i++)
        {
          printf("EW");
        }
     }
    if(y>=0)
     {
     for(i=0;i<y;i++)
      {
        printf("SN");
      }
     }
    else
     {
       y*=-1;
       for(i=0;i<y;i++)
        {
          printf("NS");
        }
     }
    if(ii<=T-1)printf("\n");
}
    
    scanf(" ");
    return 0;
}
