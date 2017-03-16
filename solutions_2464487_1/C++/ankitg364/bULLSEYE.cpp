#include<iostream>
#include<stdio.h>
#include<climits>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>

using namespace std;

int t;
long long r,l,ans;

long long fun(long long beg,long long en)
{
    if(beg==en)
        return beg;
    long long mid=(beg+en)/2;
    long long temp=(2*r*mid+2*mid*mid-mid);
    if(temp<l)
        return fun(mid+1,en);
    else
        return fun(beg,mid);
}

int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%I64d%I64d",&r,&l);
        long long beg=1;
        long long en=min(1000000000LL,l/r);
        long long ans=fun(beg,en);
        if((2*r*ans+2*ans*ans-ans)>l)
            ans--;
        printf("Case #%d: %I64d\n",i,ans);
    }
    return 0;
}
