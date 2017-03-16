#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

long long r,t;

bool enough(long long n,long long t)
{
    long long y=t-n;
    if (y/(2*n)>=r+n-1) return true;
    else return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    int cas=1;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld",&r,&t);
        long long l=1,r=10000000000ll;
        while (l<r)
        {
            long long mid=(l+r+1)/2;
            if (!enough(mid,t)) r=mid-1;
            else l=mid;
        }
        printf("Case #%d: %lld\n",cas++,l);
    }
}
