#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long gcd(long long a,long long b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf("%lld/%lld",&a,&b);
        long long c=gcd(a,b);
        a/=c;b/=c;
        c=b;
        bool f=0;
        while(c!=1)
        {
            if(c&1)f=1;
            c>>=1;
        }
        printf("Case #%d: ",ti++);
        if(f)puts("impossible");
        else
        {
            int cnt=0;
            while(a<b)cnt++,a<<=1;
            printf("%d\n",cnt);
        }
    }
    return 0;
}
