#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int maxN = 50;
ull n;
int T, dp[maxN];
ull rev(ull x) {
    ull t = 0;
    for (; x; x /= 10) t = t*10+(x%10);
    return t;
}
ull Search(ull x) {
    if (x < 21) return x;
    ull mdu = 1;
    for (ull i = x/10; i; i /= 100) mdu *= 10;
    ull step0 = x%mdu, t0 = rev(x-step0+1), v0 = rev(t0)==t0?1:0;
    mdu *= 10;
    ull step1 = x%mdu, t1 = rev(x-step1+1), v1 = rev(t1)==t1?1:0;
    //if (step0>0 && t0!=x && step1>0 && t1!=x) return min(Search(t0)+step0-v0, Search(t1)+step1-v1);
    if (step0>0 && t0!=x) {
        ull tmp = Search(t0);
        //printf("%llu: %llu->%llu + %llu\n", x, t0, tmp, step0-v0);
        return tmp+step0-v0;
    }
    //if (step1>0 && t1!=x) return Search(t1)+step1-v1;
    return Search(x-1)+1;
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    scanf("%d", &T);
    for (int count = 1; count <= T; count++) {
        scanf("%llu", &n);
        printf("Case #%d: %llu\n", count, Search(n));
    }
}
