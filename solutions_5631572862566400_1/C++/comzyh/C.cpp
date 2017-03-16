/*
* @Author: Comzyh
* @Date:   2016-04-16 09:33:37
* @Last Modified by:   Comzyh
* @Last Modified time: 2016-04-16 10:39:25
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int T, N;
int BFF[1009];
int used[1009];
vector<int> rtab[1009];
int maxdeep[1009];
int ans;
int dfs(int x, int deep)
{
    used[x] = deep;
    maxdeep[x] = max(maxdeep[x], deep);
    if (!used[BFF[x]])
        return dfs(BFF[x], deep + 1);
    else
        return deep - used[BFF[x]] + 1;
}
int main()
{
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            rtab[i].clear();
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &BFF[i]);
            rtab[BFF[i]].push_back(i);
        }
        ans = 0;
        memset(used, 0, sizeof(used));
        memset(maxdeep, 0, sizeof(maxdeep));
        for (int i = 1; i <= N; i++)
        {
            memset(used, 0, sizeof(used));
            ans = max(ans, dfs(i, 1));
        }
        // if (rtab[i].size() == 0)
        // for (int i = 1; i <= N; i++)
        //     printf("maxdeep[%4d] = %4d\n", i, maxdeep[i]);
        // printf("------------%d\n", ans);
        int sum = 0;
        for (int i = 1; i <= N; i++)
            if (BFF[BFF[i]] == i && i < BFF[i])
            {
                int a = i, b = BFF[i], ma = 0, mb = 0;
                for (int j = 0; j < rtab[a].size(); j ++)
                    if (rtab[a][j] != b)
                        ma = max(ma, maxdeep[rtab[a][j]]);
                for (int j = 0; j < rtab[b].size(); j ++)
                    if (rtab[b][j] != a)
                        mb = max(mb, maxdeep[rtab[b][j]]);
                // if (ma + mb + 2 > ans)
                // {
                //     printf("(%4d, %4d) ma = %4d, mb = %4d\n", a, b, ma, mb);
                // }
                sum += ma + mb + 2;
            }
        ans = max(sum, ans);
        printf("Case #%d: %d\n", TT, ans);
    }
    return 0;
}