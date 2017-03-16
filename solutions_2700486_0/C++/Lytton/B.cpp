#include <stdio.h>
#include <iostream>
using namespace std;

int n, t, x, y;
double f[1000][1000];

double doit()
{
    int i, j, m, s;

    m = 0;
    s = 1;
    while (s < n)
    {
        m = m+2;
        s += m*2+1;
    }
    s -= m*2+1;
    n -= s;
    if (x < 0) x = -x;
    if (x+y < m) return 1.0;
    if (x+y > m) return 0;
    if (y == m)
    {
        if (n == 2*m+1) return 1;
        else return 0;
    }
    y++;
  //  cout << n << ' ' << y << endl;
    if (n < y) return 0;
    if (n >= m+y) return 1;
    for (int i = 0;i <= n;++i)
        for (int j = 0;j <= y;++j)
            f[i][j] = 0;
    f[0][0] = 1;
    for (int i = 1;i <= n;++i)
        for (int j = 0;j <= y;++j)
        {
            if (j > 0)
            f[i][j] = 0.5*f[i-1][j-1]+0.5*f[i-1][j];
            else f[i][j] = 0.5*f[i-1][j];
           // cout << i << ' ' << j << ' ' << f[i][j] << endl;
        }
    double ans = 1;
    for (int j = 0;j < y;++j)
        ans -= f[n][j];
    return ans;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    cin >> t;
    for (int w = 1;w <= t;++w)
    {
        cin >> n >> x >> y;
        printf("Case #%d: ",w);
        cout << doit() << endl;
    }
}
