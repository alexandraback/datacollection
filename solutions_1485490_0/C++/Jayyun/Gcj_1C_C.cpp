#include <stdio.h>
#include <map>
using namespace std;
__int64 a[110], b[110];
int A[110], B[110];
map<pair<__int64, __int64>, __int64> ans[110][110];
int n, m;
__int64 dfs(int i, int j, __int64 la, __int64 lb)
{
    pair<__int64, __int64> pr = make_pair(la, lb);
    if (ans[i][j].find(pr) != ans[i][j].end())
        return ans[i][j][pr];
    if (i >= n || j >= m)
        return 0;
    if (A[i] == B[j])
    {
        __int64 res;
        if (la < lb)
        {
            res = dfs(i + 1, j, a[i + 1], lb - la) + la;
        }
        else if (la > lb)
        {
            res = dfs(i, j + 1, la - lb, b[j + 1]) + lb;
        }
        else
        {
            res = dfs(i + 1, j + 1, a[i + 1], b[j + 1]) + la;
        }
        ans[i][j][pr] = res;
        return res;
    }
    else
    {
        __int64 res = dfs(i + 1, j, a[i + 1], lb);
        __int64 tmp = dfs(i, j + 1, la, b[j + 1]);
        res = res > tmp ? res : tmp;
        ans[i][j][pr] = res;
        return res;
    }
}
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c_out.txt", "w", stdout);
    int T, tcnt = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%I64d%d", &a[i], &A[i]);
        for (int i = 0; i < m; i++)
            scanf("%I64d%d", &b[i], &B[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j].clear();
        printf("Case #%d: %I64d\n", ++tcnt, dfs(0, 0, a[0], b[0]));
    }
    return 0;
}
