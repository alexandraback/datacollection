#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<set>
#include<map>
using namespace std;

long long int gcd(long long int u,long long int v) {
return (v != 0)?gcd(v, u%v):u;
}
int main()
{
   freopen("A-large.in","r",stdin);
    //freopen("input.txt","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,ti;
    cin>>ti;
    for(t=1;t<=ti;t++)
    {
        long long int p,q;
        scanf("%lld/%lld",&p,&q);
       long long int ans=1,num=gcd(p,q);
        p/=num;
        q/=num;
         if(p==1 && q==1)
         {
             printf("\nCase #%d: 0",t);
             continue;
         }
         int flag=0;
        if( (float)log2(q)!=(int)log2(q))
        {
            printf("\nCase #%d: impossible",t);
        }
        else
        {
        while(q>0)
        {   num=gcd(p,q);
              p/=num;
        q/=num;
        if(2*p>=q)
        {
            flag=1;
            break;
        }
        else
        {
            ans++;
            q/=2;
        }
        }
       if(flag)
            printf("\nCase #%d: %lld",t,ans);
       else
        printf("\nCase #%d: impossible",t);
        }
    }
        return 0;
    }
