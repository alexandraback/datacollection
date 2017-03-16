#include <iostream>
#include <cstdio>

using namespace std;

long long pow2[45];

long long gcd(long long a,long long b)
{
     if (a<b)
     {
        long long tmp=b;
        b=a;
        a=tmp;
     }
     if (b==0)
     {
              return a;
     }
     else
     {
         return gcd(b,a%b);
     }
}
 

int main()
{
    freopen("a.txt","r",stdin);
    freopen("a_out.txt","w",stdout);
    long long accl=1;
    for (int i=0; i<=40; i++)
    {
        pow2[i]=accl;
        accl*=2;
    }
    int n;
    long long tmp,tmp2;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%lld/%lld",&tmp,&tmp2);
        long long g=gcd(tmp,tmp2),num;
        tmp/=g;
        tmp2/=g;
        bool s=false;
        int v;
        for (int j=0; j<=40; j++)
        {
            if (tmp2==pow2[j])
            {
               s=true;
               v=j;
            }
        }
        int ans=0;
        if (v==0)
        {
           ans=1;
        }
        else
        {
            for (int j=0; j<=v; j++)
            {
                ans+=1;
                tmp2/=2;
                if (tmp>=tmp2)
                {
                   break;
                }
            }
        }
        if (!s)
        {
              printf("Case #%d: impossible\n",i+1); 
        }
        else
        {
            printf("Case #%d: %d\n",i+1,ans);
        }
    }
}
