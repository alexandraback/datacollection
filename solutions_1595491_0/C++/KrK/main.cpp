#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int T, N, S, p;
int lim1[Maxn], lim2[Maxn];
int best[Maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d", &N, &S, &p);
        for (int i = 0; i < N; i++) {
            int t; scanf("%d", &t);
            if (t == 0) lim1[i] = 0;
            else lim1[i] = (t - 1) / 3 + 1;
            lim2[i] = -1;
            if (2 <= t && t <= 28) lim2[i] = (t + 1) / 3 + 1;
        }
        fill(best, best + Maxn, -1); best[0] = 0;
        for (int i = 0; i < N; i++)
            for (int j = S; j >= 0; j--) if (best[j] != -1) {
                if (j < S && lim2[i] != -1) best[j + 1] = max(best[j + 1], best[j] + (lim2[i] >= p));
                if (lim1[i] >= p) best[j]++;
            }
        printf("Case #%d: %d\n", tc, best[S]);
    }
    return 0;
}
