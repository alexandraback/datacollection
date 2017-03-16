#include<cstdio>
#include<cstring>
#include<algorithm>
#define eps 1e-8
using namespace std;

long long r,m;

int dlcmp(double x) {return x<-eps?-1:x>eps;}

int check(long long n)
{
    double res=2*((double)n*r+(double)n*(n-1))+(double)n;

    if (dlcmp(res-m)<=0)
        return 1;
    else
        return 0;
}

int main()
{
    int t,ys;
    long long ans,right,left,mid;

    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("Asmall.out","w",stdout);

    scanf("%d",&t);
    ys=0;
    while (t--)
    {
        scanf("%lld%lld",&r,&m);

        left=0;
        right=m/(2*r+1);
        while (left<right)
        {
            mid=(left+right+1)/2;
            if (check(mid))
                left=mid;
            else
                right=mid-1;
        }

        printf("Case #%d: %lld\n",++ys,left);
    }

    return 0;
}


