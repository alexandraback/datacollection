#include <cstdio>

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int num = 1; num <= T; num++)
    {
        long long r,t;
        scanf("%lld %lld",&r,&t);
        
        
        long long bawah = 0ll;
        long long atas = 2000000000ll;
        long long res = 0ll;
        while (1)
        {
            if (atas - bawah <= 1ll)
            {
                long long paint = 2ll * atas * atas + 2 * atas * r - atas;
                if (paint <= t)
                    res = atas;
                else res = bawah;
                break;
            }
            long long mid = (atas + bawah) / 2ll;
            long long paint = 2ll * mid * mid + 2 * mid * r - mid;
            if (paint < t)
                bawah = mid;
            else if (paint > t)
                atas = mid;
            else if (paint == t) {
                res = mid;
                break;
            }
        }
        printf("Case #%d: %lld\n",num,res);
    }
    return 0;
}
