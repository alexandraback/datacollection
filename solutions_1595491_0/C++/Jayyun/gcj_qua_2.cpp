#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
int f[110][110];
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("gcj_qua_2.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    int tcnt = 0;
    vector<pair<int, int> > com[40];
    for (int i = 0; i < 30; i++)
        com[i].clear();
    for (int i = 0; i <= 10; i++)
        for (int j = 0; j <= 10; j++)
            for (int k = 0; k <= 10; k++)
            {
                int s = i + j + k;
                int best = max(i, max(j, k));
                int gap = max(abs(i - j), max(abs(i - k), abs(j - k)));
                int sup = -1;
                if (gap <= 1)
                    sup = 0;
                else if (gap == 2)
                    sup = 1;
                if (sup != -1)
                {                   
                    com[s].push_back(make_pair(best, sup));
                }
            }
    while (T--)
    {
        int N, S, p, ti;
        scanf("%d%d%d", &N, &S, &p);
        //printf("%d %d\n", N, S);
        memset(f, 0xff, sizeof(f));
        for (int i = 0; i <= N; i++)
            f[0][i] = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &ti);
            for (int k = 0; k < com[ti].size(); k++)
            {
                int best = com[ti][k].first;
                int sup = com[ti][k].second;
                for (int j = 0; j <= N && j <= S; j++)
                {
                    f[i][j + sup] = max(f[i][j + sup], f[i - 1][j] + (best >= p ? 1 : 0));
                }
            }
        }
        printf("Case #%d: %d\n", ++tcnt, f[N][S]);
    }
}
