#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int MaxN = 100 + 5;
int grid[MaxN][MaxN];
bool solve(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int k = 0;
            for (k = 0; k < n; k++)
            {
                if (grid[k][j] > grid[i][j])
                    break;
            }
            if (k != n)
            {
                for (k = 0; k < m; k++)
                {
                    if (grid[i][k] > grid[i][j])
                        break;
                }
                if (k != m)
                {
                    return false;
                }                
            }
        }
    }
    return true;
}
int main()
{
    int T;
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    while (scanf("%d", &T) != EOF)
    {
        for (int ca = 0; ca < T; ca++)
        {
            int n, m;
            scanf("%d%d", &n, &m);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    scanf("%d", &grid[i][j]);
                }
            }
            printf("Case #%d: %s\n", ca + 1, solve(n, m) ? "YES" : "NO");
        }
    }
                    
}
