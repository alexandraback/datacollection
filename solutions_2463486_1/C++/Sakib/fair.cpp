#include <stdio.h>
#include <iostream>
#include <math.h>
#define ll long long int
#define M 10000000

using namespace std;

ll rev(ll x)
{
    ll r=0;

    while(x)
    {
        r=r*10+x%10;
        x/=10;
    }

    return r;
}

bool check(ll x)
{
    return ( (x==rev(x)) && (x*x==rev(x*x)));
}

ll num[50];

int main()
{
    ll i,j,k,sz=0,a,b;
    int t,T,r;

    for(i=1;i<=M;i++)
    {
        if(check(i)) num[sz++]=i*i;
    }

    //for(i=0;i<sz;i++) cout<<num[i]<<" "<<(ll)sqrt(num[i])<<endl;

   // cout<<sz<<endl;

   freopen("C-large-1.in","r",stdin);
   freopen("fair-out-large1.txt","w",stdout);

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        cin>>a>>b;

        for(r=i=0;i<sz;i++)
        {
            if(num[i]>b) break;

            if(num[i]>=a) r++;
        }

        printf("Case #%d: %d\n",t,r);
    }

    return 0;
}
