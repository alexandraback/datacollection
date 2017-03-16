#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000;
const int MAXM = 1000;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T, A, B, K;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d%d%d", &A, &B, &K);
        int cnt = 0;
        for (int i = 0; i < A; ++i)
        {
            for (int j = 0; j < B; ++j)
            {
                if ((i & j) < K)
                {
                    ++cnt;
                }
            }
        }
        printf("Case #%d: %d\n", cas, cnt);
    }
    return 0;
}
