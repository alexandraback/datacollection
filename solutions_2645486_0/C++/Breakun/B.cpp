#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
ll E, R; int N;
ll v[10000];

int main()
{
    int T; scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++)
    {
        scanf("%lld %lld %d", &E, &R, &N);
        R = min(E, R);
        ll sum = 0LL, mval = 0LL;
        for(int i = 0; i < N; i++)
        {
            scanf("%lld", &v[i]);
            sum += v[i];
            mval = max(mval, v[i]);
        }
        printf("Case #%d: %lld\n", tt, sum * R + mval * (E - R));
    }
    return 0;
}
