#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int T;
int x,y;
int n;
int A[1000111];
int B[1000111];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    int ans;
    int a,b;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%d %d",&x,&y);
    printf("Case #%d: ",ii);
    a=x+y;
    b=x-y;
    int aa,bb;
    aa=abs(a);
    bb=abs(b);
    aa=max(aa,bb);
    k=0;
    for(t=1;;t++)
     {
       k+=t;
       if(k>=aa)
        {
          if(k%2==aa%2)break;
          else
           {
             t++;
             break;
           }
        }
     }
    n=t;
//    printf(">>>  %d %d  %d\n",a,b,n);
    k=a;
    for(i=n;i>=1;i--) 
     {
       if(k>=0)
        {
          A[i]=2;
          k-=i;
        }
       else 
        {
          A[i]=1;
          k+=i;
        }
     }

    k=b;
    for(i=n;i>=1;i--) 
     {
       if(k>=0)
        {
          B[i]=2;
          k-=i;
        }
       else 
        {
          B[i]=1;
          k+=i;
        }
     }
    for(i=1;i<=n;i++)
     {
       if(A[i]==1 and B[i]==1)printf("W");
       if(A[i]==1 and B[i]==2)printf("S");
       if(A[i]==2 and B[i]==1)printf("N");
       if(A[i]==2 and B[i]==2)printf("E");
     }
     
    if(ii<=T-1)printf("\n");
}
    
    scanf(" ");
    return 0;
}
