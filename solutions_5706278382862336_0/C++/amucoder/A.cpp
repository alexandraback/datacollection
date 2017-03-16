#include<cstdio>
#include<algorithm>
#include<vector>


long long gcd(long long a,long long b)
{
    if(a>b) return gcd(b,a);
    if(a==0) return b;
    return gcd(b%a,a);    
}

int main()
{
int i,j,k,l,m,n,t,T;

scanf("%d",&T);

for(t=1;t<=T;t++)
    {
     long long a,b,c;
     scanf("%lld/%lld",&a,&b);
     
    // printf("GCD %lld\n",gcd(a,b));
     c= gcd(a,b);
     a/=c;
     b/=c;  
      
  //  printf("A %lld B %lld b&b %lld\n",a,b,b&(b-1));
     
     if((b&(b-1))==0)
        {
        for(i=0;a<b && i<40;i++)
            {
            a*=2;    
            }
      //  printf("A %lld B %lld, i %d\n",a,b,i);
        if(a>=b)    
            {
            printf("Case #%d: %d\n",t,i);    
            continue;
            }
        }
  //  else    
    printf("Case #%d: impossible\n",t);    
    }
    
return 0;    
}
