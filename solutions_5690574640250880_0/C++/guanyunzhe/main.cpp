#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55;

char map[N][N];
int x, y, m;

int main()
{
    #ifdef LOCAL
    //freopen("sub3-in.txt", "r", stdin);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int T;
    scanf("%d", &T);
    for (int ncase = 1; ncase <= T; ++ncase)
    {
        printf("Case #%d:\n", ncase);
        scanf("%d%d%d", &x, &y, &m);

        //printf("%d %d %d: %d\n", x, y, m, x * y - m);
        memset(map, '*', sizeof(map));
        for (int i = 0; i != x; ++i)
            map[i][y] = 0;

        int a, b, c, n = x * y - m;

        if ((x != 1 && y != 1) && (n == 2 || n == 3))
        {
            printf("Impossible\n");
            continue;
        }
        a = sqrt(double(n));
        b = n / a;
        if (a > x)
        {
            a = x;
            b = n / a;
        }
        if (b > y)
        {
            b = y;
            a = n / b;
        }
        for (int i = 0; i != a; ++i)
            for (int j = 0; j != b; ++j)
                map[i][j] = '.';

        c = n - a * b;
        if (c == 1 && (a == 2 || b == 2))
        {
            printf("Impossible\n");
            continue;
        }

        if (c == 1)
        {
            map[a - 1][b - 1] = '*';
            c++;
        }
        if (a < x)
            for (int i = 0; i != c; ++i)
                map[a][i] = '.';
        else
            for (int i = 0; i != c; ++i)
                map[i][b] = '.';
        map[0][0] = 'c';
        for (int i = 0; i != x; ++i)
            printf("%s\n", map[i]);
    }
    return 0;
}
