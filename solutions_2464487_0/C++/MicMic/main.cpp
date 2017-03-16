#include <iostream>
#include <cstdio>
#include <cstring>
#define Pi 3.1415927
using namespace std;


bool cal(long long r,long long t,long long num)
{
    if(num>3037000499)return false;
    long long temp=(2*r+2*(num-1))*num+num;
    if(temp<0||temp<num)return false;;
    if(t>=temp)return true;
    return false;
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int testcase;
    scanf("%d",&testcase);
    for(int z=1; z<=testcase; z++)
    {
        long long r,t;
        scanf("%lld %lld",&r,&t);
        long long low,high,mid;
        low=0;
        high=t/(2*r);
        long long res=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(cal(r,t,mid))
            {
                low=mid+1;
                res=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        printf("Case #%d: %lld\n",z,res);
    }
    return 0;
}
