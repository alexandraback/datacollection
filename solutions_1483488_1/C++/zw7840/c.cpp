#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long a[25]={0};

long check(long x,long y)
{
 long i,c=x;
 long o=0;
 long k;
 long s=0;
 
 for(k=1;k<=x;k*=10);
 k/=10;
 
 for(i=1;i<=8;i++)
   a[++o]=c=c/k+(c*10%(k*10));
 sort(a+1,a+o+1);
 o=unique(a+1,a+o+1)-a-1;
 for(i=1;i<=o;i++)
   if(a[i]>x&&a[i]<=y)
    s++;
 return s;
}

int main()
{
 long i,j,t;
 long x,y,a,b;
 
 freopen("c.in","r",stdin);
 freopen("c.out","w",stdout);
 
 scanf("%ld",&t);
 for(i=1;i<=t;i++)
   {
    long ans=0;
    scanf("%ld%ld",&a,&b);
    
    printf("Case #%ld: ",i);
    for(j=a;j<=b;j++)
      {
       ans+=check(j,b);
      }
    printf("%ld\n",ans);
   }
 
 return 0;
}
