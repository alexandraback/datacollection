#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long i64;

int k, c, s;

i64 f(int p)
{
    i64 ret = 0;
    for (int i = 0; i < c; ++i) ret = ret * k + min(k - 1, p + i);
    return ret;
}

int main()
{
    int dat;
    scanf("%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        scanf("%d%d%d", &k, &c, &s);
        if (s * c < k) {
            printf("Case #%d: IMPOSSIBLE\n", cas);
        } else {
            printf("Case #%d:", cas);
            for (int i = 0; i < k; i += c) printf(" %lld", f(i) + 1);
            puts("");
        }
    }
}
