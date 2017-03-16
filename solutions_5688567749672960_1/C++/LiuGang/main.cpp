#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int gett[16];
long long n;
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("large.txt", "w", stdout) ;

    gett[1]=10;
    long long ten=10;
    for(int i=2;i<=14;i+=2)
    {
        gett[i]=gett[i-1]+2*ten-1;
        gett[i+1]=gett[i]+11*ten-1;
        ten*=10;
    }
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%I64d",&n);
        int ans=0;
        if(n<=10)ans=n;
        else
        {
            if(n%10==0)
                n--,ans++;
            long long x=10,nx=1;
            int i;
            for(i=1;i<=14;i++,x*=10)
                if(n<x*10)break;
            ans+=gett[i];
            //cout<<ans<<endl;
            long long d=0;
            for(int j=1;j<=(i+1)/2;j++)
            {
                d+=n/x*nx;
                n=n%x;
                x/=10;
                nx*=10;
            }
            //cout<<d<<" "<<n<<endl;
            ans+=n;
            if(d>1)
            ans+=d;
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
