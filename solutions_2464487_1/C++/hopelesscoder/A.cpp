#include <cstdio>

long long maxi = 9223372036854775807ll;

long long min(long long a, long long b)
{
    if (a < b) return a;
    else return b;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int num = 1; num <= T; num++)
    {
        long long r,t;
        scanf("%lld %lld",&r,&t);
        
        
        long long temp = maxi / r;
        temp = temp / 2;
        long long bawah = 0ll;
        long long atas = min(1518500000ll,temp);
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
