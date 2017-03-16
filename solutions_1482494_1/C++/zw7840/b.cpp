#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long hash[2005]={0};
long a[2005]={0};
long b[2005]={0};

int main()
{
 long t,i,j;
 long n;
 
 freopen("b.in","r",stdin);
 freopen("b.out","w",stdout);
 
 scanf("%ld",&t);
 
 for(i=1;i<=t;i++)
   {
    long star=0,s=0;
    
    printf("Case #%ld: ",i);
    
    memset(hash,0,sizeof(hash));
    scanf("%ld",&n);
    for(j=1;j<=n;j++)
      scanf("%ld%ld",&a[j],&b[j]);
    
    long flag=1,k=0;
    for(;flag;)
      {
       flag=0;
       
       for(j=1;j<=n;j++)
         if(star>=b[j]&&hash[j]!=2)
          {
           star+=2-hash[j];
           hash[j]=2;
           flag=1;
           s++;
          }
       if(flag)
        continue;
       for(j=1,k=0;j<=n;j++)
         if(star>=a[j]&&!hash[j])
          {
           if(!k||b[j]>b[k])
            k=j;
           flag=1;
          }
       if(flag)
        {
         star++;
         hash[k]=1;
         s++;
        }
      }
    
    for(j=1;j<=n;j++)
      if(hash[j]!=2)
       {
        printf("Too Bad");
        goto end;
       }
    
    printf("%ld",s);
    
    end:
    printf("\n");
   }
 
 return 0;
}
