#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int T,ii;
int n;
int a[1000111];

int reve(int x)
{
   int b[100],B;
   int i,j,k;
   B=0;
   while(x!=0)
    {
      b[B]=x%10;
      x/=10;
      B++;
    }
    k=0;
    for(i=0;i<B;i++)
     {
       k+=b[i];
       k*=10;
     }
    k/=10;
    return k;
}
int main()
{
    freopen("A-small-attempt0 (2).in","r",stdin);
    freopen("A-small-attempt0 (2)out.txt","w",stdout);
    int INF=1;    
    int i,j,k;
    int p,q,r;
    for(i=0;i<7;i++)INF*=10;
    for(i=0;i<=1000110;i++)a[i]=INF;
    a[1]=1;
    for(i=1;i<=1000000;i++)
     {
       if(a[i]+1 < a[i+1])a[i+1]=a[i]+1;
       k=reve(i);
       if(a[i]+1 < a[k])a[k]=a[i]+1;
     }
    
scanf("%d",&T);
for(ii=1;ii<=T;ii++)
{
   scanf("%d",&n);
   printf("Case #%d: %d\n",ii,a[n]);
   

}

    
    
    scanf(" ");
    return 0;
}
