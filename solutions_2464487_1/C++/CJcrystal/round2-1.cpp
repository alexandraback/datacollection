#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int T;
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    for(int i = 1;i <= T; ++i)
    {

        long long r;
        long long t;
        scanf("%I64d%I64d",&r,&t);
        long long n = 0;
        long long l = 0,rr = 20000000000LL,m = 0;
        while(l < rr - 1)
        {
            m = (l + rr) / 2;
            long long ans1 = r * 2LL+ m * 2LL + 1;
            long long ans2 =  t / (m + 1);
            if(ans1 <= ans2)
                l = m;
            else
                rr = m;
        }
        printf("Case #%d: ",i);
        printf("%I64d\n",l + 1);

    }
    return 0;
}
