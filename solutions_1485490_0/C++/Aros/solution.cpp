#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 100+5, MAXM = (1<<20)+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int T, N, M, A[MAXN], B[MAXN];
long long a[MAXN], a_[MAXN], b[MAXN], b_[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++)
            scanf("%lld%d", &a[i], &A[i]);
        for (int i = 1; i <= M; i++)
            scanf("%lld%d", &b[i], &B[i]);
        long long ans = 0;
        for (int p = 0; p <= M; p++)
            for (int q = 0; q <= M; q++)
            {
                long long cnt = 0, m;
                memcpy(a_, a, sizeof(a));
                memcpy(b_, b, sizeof(b));
                int x = 1;
                for (int i = 1; i <= p; i++)
                {
                    if (B[i] == A[1])
                    {
                        m = min(a_[1], b_[i]);
                        cnt += m;
                        a_[1] -= m;
                        b_[i] -= m;
                    }
                    if (b_[i] < b[i])
                        x = i;
                }
                for (int i = x; i <= q; i++)
                {
                    if (B[i] == A[2])
                    {
                        m = min(a_[2], b_[i]);
                        cnt += m;
                        a_[2] -= m;
                        b_[i] -= m;
                    }
                    if (b_[i] < b[i])
                        x = i;
                }
                for (int i = x; i <= M; i++)
                    if (B[i] == A[3])
                    {
                        m = min(a_[3], b_[i]);
                        cnt += m;
                        a_[3] -= m;
                    }
                ans = max(ans, cnt);
            }
        printf("Case #%d: ", cas);
        printf("%lld", ans);
        printf("\n");
    }
    return 0;
}
