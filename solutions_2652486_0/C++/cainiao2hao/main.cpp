#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;

#define N 1000
int R, n, m, K;
bool used[N];
bool tmp[N];
int d[3];

int main()
{
    int cas;
    freopen("D:\\cdata.in","r",stdin);
    freopen("D:\\cdata.out","w",stdout);
    scanf("%d", &cas);

    printf("Case #1:\n");
    scanf("%d %d %d %d", &R, &n, &m, &K);
    while (R--)
    {
        memset(used, false, sizeof (used));
        memset(tmp, false, sizeof (tmp));
        for (int i = 0; i < K; i++)
        {
            int x;
            scanf("%d", &x);
            used[x] = true;
        }
        bool flag = false;
        for (d[0] = 2; d[0] <= m; d[0]++)
            for (d[1] = 2; d[1] <= m; d[1]++)
                for (d[2] = 2; d[2] <= m; d[2]++)
                {
                    if (flag)
                        continue;
                    memset(tmp, false, sizeof (tmp));
                    for (int i = 0; i < (1 << 3); i++)
                    {
                        int pro = 1;
                        for (int j = 0; j < 3; j++)
                            if (i & (1 << j))
                                pro *= d[j];
                        tmp[pro] = true;
                    }
                    bool ok = true;
                    for (int i = 0; i < N; i++)
                        if (used[i]&&!tmp[i])
                            ok = false;
                    if (!ok)
                        continue;
                    flag = true;
                    printf("%d%d%d\n", d[0], d[1], d[2]);
                }
    }
    return 0;
}