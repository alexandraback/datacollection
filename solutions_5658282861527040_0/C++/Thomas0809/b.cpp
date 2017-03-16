#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long f[44][2][2][2];
int T, a, b, c;

int calc(int u, int v, int w)
{
    if (u < v) return 0;
    if (u > v) return 1;
    return w;
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++)
    {
        scanf("%d%d%d", &a, &b, &c);
        memset(f, 0, sizeof f);
        for (int len = 0; len < 31; len++)
        {
            for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
            for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
            {
                int ni = calc(x, (a & (1 << len)) > 0, i);
                int nj = calc(y, (b & (1 << len)) > 0, j);
                int nk = calc(x & y, (c & (1 << len)) > 0, k);
                if (len == 0)
                {
                    if (i + j + k < 3) continue;
                    f[len][ni][nj][nk] += 1ll;
                }
                else
                    f[len][ni][nj][nk] += f[len - 1][i][j][k];
            }
        }
        cout << "Case #" << tt + 1 << ": " << f[30][0][0][0] << endl;
    }
}
