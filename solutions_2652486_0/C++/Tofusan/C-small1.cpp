#include <stdio.h>
#include <stdlib.h>

int t;
bool A[1001][1001];
int B[10];
bool C[1001];
int r,m,n,k;
void init()
{
int tmp;
 for(int i=2;i<=5;i++)
 {
  for(int j=2;j<=5;j++)
  {
   for(int k=2;k<=5;k++)
   {
    tmp=(i*100)+(j*10)+k;
    C[tmp]=true;
    A[tmp][1]=true;
    A[tmp][i]=true;
    A[tmp][j]=true;
    A[tmp][k]=true;
    A[tmp][i*j]=true;
    A[tmp][i*k]=true;
    A[tmp][j*k]=true;
    A[tmp][i*j*k]=true;
   }
  }
 }     
}
void solve()
{
 for(int s=222;s<=555;s++)
    {
     if(C[s]==true)
     {
      for(int l=1;l<=k;l++)
      {
       if(A[s][B[l]]==false){break;}
       else if(l==k){printf("%d\n",s);return;}
      }
     }
    }
}
main()
{
 freopen("C-small-1-attempt0.in","r",stdin);
 freopen("C-small-1.out","w",stdout);
 scanf("%d",&t);
 init();
 for(int tests=1;tests<=t;tests++)
 {
   printf("Case #%d:\n",tests);
   scanf("%d%d%d%d",&r,&n,&m,&k);
   for(int i=1;i<=r;i++)
   {
    for(int j=1;j<=k;j++)
    {
     scanf("%d",&B[j]);
    }
    solve();
   }
 }

 return 0;
}
