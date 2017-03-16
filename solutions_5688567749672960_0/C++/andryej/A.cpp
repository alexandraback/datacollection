#include <cstdio>

typedef unsigned long long ULL;

#define INF 1000000000000000LL

ULL rev(ULL n)
{
    ULL res = 0;
    if (!(n%10)) return INF;
    while (n)
    {
        res = 10*res + n%10;
        n/=10;
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        ULL res=1;
        ULL n;
        scanf("%llu", &n);
        while(n!=1)
        {
            ULL tmp = rev(n);
            n = (tmp < n-1) ? tmp : n-1;
            //fprintf(stderr, "STEP %llu : %llu\n",res, n);
            ++res;
        }
        printf("Case #%d: %llu\n",i,res);
    }
    return 0;
}
