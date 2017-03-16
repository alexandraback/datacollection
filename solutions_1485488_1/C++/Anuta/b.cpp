#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>                                                                               

using namespace std;

const double inf = 1000000000.0;
const double eps = 1e-8;

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;

int T;
int n, m;
int h;

int f[150][150];
int c[150][150];

double r[150][150];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void relax(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < m && yy >= 0 && yy < n)
        {
            if (!(c[y][x] - f[yy][xx] >= 50 && c[yy][xx] - f[y][x] >= 50 && c[yy][xx] - f[yy][xx] >= 50))
                continue;
            double hh = max(0.0, h - r[y][x]*10);
            if ( c[yy][xx] - hh >= 50 )
            {
                if (r[y][x] < eps) r[yy][xx] = 0.0;
                else
                {
                    if (hh - f[y][x] > 20 - eps)
                    {
                        r[yy][xx] = min(r[yy][xx], r[y][x] + 1);
                    }
                    else
                    {
                        r[yy][xx] = min(r[yy][xx], r[y][x] + 10);
                    }
                }
            }
            else
            {
                double dt = (hh - c[yy][xx] + 50.0)/10.0;
                if (hh - dt* 10 - f[y][x] > 20-eps)
                {
                    r[yy][xx] = min(r[yy][xx], r[y][x] + 1 + dt);
                }
                else
                {
                    r[yy][xx] = min(r[yy][xx], r[y][x] + 10 + dt);
                }
            }
        }
    }
}

int main()
{
  scanf("%d", &T);
  for (int t = 0; t < T; ++t)
  {
    scanf("%d %d %d", &h, &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &c[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &f[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            r[i][j] = inf;
    r[0][0] = 0.0;

    for (int v = 0; v < n*m; ++v)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
              relax(j, i);
            }
    }
    printf("Case #%d: %.7f\n", t + 1, r[n-1][m-1]);
  }
  return 0;
}
