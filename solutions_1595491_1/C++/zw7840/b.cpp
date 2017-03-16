#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long f[205][205]={0};

int main()
{
 long t,i,j,k;
 long n,x,s,p;
 
 freopen("b.in","r",stdin);
 freopen("b.out","w",stdout);
 
 scanf("%ld",&t);
 for(i=1;i<=t;i++)
   {
    printf("Case #%ld: ",i);
    memset(f,0,sizeof(f));
    scanf("%ld",&n);
    scanf("%ld",&s);
    scanf("%ld",&p);
    for(j=1;j<=s;j++)
      f[0][j]=-2000000000;
    
    for(j=1;j<=n;j++)
      {
       scanf("%ld",&x);
       if(x==0)
        f[j][0]=f[j-1][0]+(0>=p);
       else
        f[j][0]=f[j-1][0]+((x-1)/3+1>=p);
       for(k=1;k<=s;k++)
         {
          if(x==0)
           f[j][k]=f[j-1][k]+(0>=p);
          else
           f[j][k]=f[j-1][k]+((x-1)/3+1>=p);
          if(x>=2&&x<=28)
           if(x%3<2)
            f[j][k]>?=f[j-1][k-1]+(x/3+1>=p);
           else if(x%3==2)
            f[j][k]>?=f[j-1][k-1]+(x/3+2>=p);
         }
      }
    
    printf("%ld\n",f[n][s]);
   }
 
 return 0;
}
