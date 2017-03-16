#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int a[500][500], b[500][500];
int n, m, t;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j]);
                b[i][j] = 100;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int minv = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] > minv) minv = a[i][j];
            }
            for (int j = 0; j < m; j++)
            {
                b[i][j] = min(b[i][j], minv);
            }
        }

        for (int j = 0; j < m; j++)
        {
            int maxv = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] > maxv) maxv = a[i][j];
            }
            for (int i = 0; i < n; i++)
            {
                b[i][j] = min(b[i][j], maxv);
            }
        }

        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != b[i][j]) ok = 0;
            }
        }

        char * s;
        if (ok) s = "YES";
        else s = "NO";

        printf("Case #%d: %s\n", tc, s);
    }
    return 0;
}
