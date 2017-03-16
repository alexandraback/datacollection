#include <stdio.h>
#include <iostream>
using namespace std;

const int fx[4] = {0,0,-1,1};
const int fy[4] = {-1,1,0,0};

int n,m,k, T;
int ans;
int a[100][100];
int x[100];
int y[100];
bool flag[100][100];

int check()
{
    int l = 1;
    int r = 0;

    for (int i = 0;i < n;++i)
        for (int j = 0;j < m;++j)
            flag[i][j] = false;
    for (int i = 0;i < n;++i)
    {
        if (!flag[i][0] && a[i][0] == 0)
        {
            flag[i][0] = true;
            ++r;
            x[r] = i;
            y[r] = 0;
        }
        if (!flag[i][m-1] && a[i][m-1] == 0)
        {
             flag[i][m-1] = true;
            ++r;
            x[r] = i;
            y[r] = m-1;
        }
    }
     for (int i = 0;i < m;++i)
    {
        if (!flag[0][i] && a[0][i] == 0)
        {
            flag[0][i] = true;
            ++r;
            x[r] = 0;
            y[r] = i;
        }
        if (!flag[n-1][i] && a[n-1][i] == 0)
        {
             flag[n-1][i] = true;
            ++r;
            x[r] = n-1;
            y[r] = i;
        }
    }
    while (l <= r)
    {
        int x1, y1;
        for (int i = 0;i < 4;++i)
        {
            x1 = x[l] + fx[i];
            y1 = y[l] + fy[i];
            if (x1 >= 0 && x1 < n && y1 >=0 && y1 < m
                    && !flag[x1][y1] && a[x1][y1] == 0)
                {
                    ++r;
                    flag[x1][y1] = true;
                    x[r] = x1;
                    y[r] = y1;
                }
        }
        ++l;
    }

    int ret = 0;
    for (int i = 0;i < n;++i)
        for (int j = 0;j < m;++j)
            if (!flag[i][j])
                ++ret;
    return ret;
}

void doit()
{
    int p;

    scanf("%d%d%d", &n, &m, &k);
    ans = k;
    for (int i = 0;i <= (1 << (n*m))-1;++i)
    {
      //  printf("%d\n", i);
        int tmp = i;
        p = 0;
        for (int j = 0;j < n;++j)
            for (int k = 0;k < m;++k)
            {
                a[j][k] = tmp % 2;
                tmp = tmp/2;
                p += a[j][k];
            }
        if (p >= ans) continue;

      //  printf("%d\n", i);
        if (check() >= k) ans = p;
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("C-small.in","r", stdin);
    freopen("C.out","w",stdout);

    scanf("%d", &T);
    for (int q = 1;q <= T;++q)
    {
        printf("Case #%d: ", q);
        doit();
    }
}
