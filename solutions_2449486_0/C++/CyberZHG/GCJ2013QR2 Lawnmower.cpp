#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int n, m;
int lawn[MAXN][MAXN];
bool valid[MAXN][MAXN];

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &lawn[i][j]);
            }
        }
        bool flag = true;
        memset(valid, false, sizeof(valid));
        for (int a = 1; a <= 100; ++a)
        {
            for (int i = 0; i < n; ++i)
            {
                if (lawn[i][0] <= a)
                {
                    bool tf = true;
                    for (int j = 0; j < m; ++j)
                    {
                        if (a < lawn[i][j])
                        {
                            tf = false;
                            break;
                        }
                    }
                    if (tf)
                    {
                        for (int j = 0; j < m; ++j)
                        {
                            valid[i][j] = true;
                        }
                    }
                }
            }
            for (int j = 0; j < m; ++j)
            {
                if (lawn[0][j] <= a)
                {
                    bool tf = true;
                    for (int i = 0; i < n; ++i)
                    {
                        if (a < lawn[i][j])
                        {
                            tf = false;
                            break;
                        }
                    }
                    if (tf)
                    {
                        for (int i = 0; i < n; ++i)
                        {
                            valid[i][j] = true;
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (lawn[i][j] == a && !valid[i][j])
                    {
                        flag = false;
                    }
                }
            }
        }
        printf("Case #%d: ", t);
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
