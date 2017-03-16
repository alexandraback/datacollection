#include <cstdio>
#include <algorithm>
using namespace std;

long long cnt[15] = {1, 9, 9+9+1, 9+99+1, 99+99+1, 99+999+1, 999+999+1, 999+9999+1, 9999+9999+1, 9999+99999+1, 99999+99999+1, 99999+999999+1, 999999+999999+1, 999999+9999999+1, 9999999+9999999+1};

long long n;

long long rev(long long num)
{
    long long res = 0;
    while(num>0)
    {
        res = res*10 + num%10;
        num/=10;
    }
    return res;
}

int main()
{
    for(int i=1; i<15; ++i) cnt[i] += cnt[i-1];
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%lld", &n);
        long long ans;
        if(n<10) ans = n;
        else
        {
            long long now = 1;
            int i;
            for(i=0; now*10<=n; ++i, now*=10);
            ans = cnt[i];
            long long tmp = n-now;

            for(long long k=10; k<=n; k*=10)
            {
                long long front = n/k;
                long long back = n%k;
                if(back>0) tmp = min(tmp, rev(front)+back);
                front-=1;
                back+=k;
                if(back>0) tmp = min(tmp, rev(front)+back);
            }
            ans += tmp;
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
