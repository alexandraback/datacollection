#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

#define MAXN 1024

int n;
int one[MAXN];
int two[MAXN];
int pd[2*MAXN];
char marca[2*MAXN][MAXN];

int bt(int stars)
{
    if (stars < 0) return INF;
    if (pd[stars] >= 0) return pd[stars];

    pd[stars] = INF;
    int level = -1;
    int m1 = bt(stars - 1);
    for (int j = 0; j < n; ++j)
    {
        if (marca[stars-1][j] == 0 && one[j] <= stars-1 && m1 + 1 < pd[stars])
        {
            pd[stars] = m1 + 1;
            level = j;
        }
        if (marca[stars-1][j] == 1 && two[j] <= stars-1 && m1 + 1 <= pd[stars])
        {
            pd[stars] = m1 + 1;
            level = j;
        }
    }
    for (int i = 0; i < n && level >= 0; ++i)
    {
        marca[stars][i] = marca[stars-1][i];
    }
    if (level >= 0) marca[stars][level]++;

    level = -1;
    int m2 = bt(stars - 2);
    for (int j = 0; j < n; ++j)
    {
        if (marca[stars-2][j] == 0 && two[j] <= stars-2 && m2 + 1 <= pd[stars])
        {
            pd[stars] = m2 + 1;
            level = j;
        }
    }
    for (int i = 0; i < n && level >= 0; ++i)
    {
        marca[stars][i] = marca[stars-2][i];
    }
    if (level >= 0) marca[stars][level]++;

    return pd[stars];
}

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        printf ("Case #%d: ", caso);

        scanf ("%d", &n);

        for (int i = 0; i < n; ++i)
        {
            scanf ("%d %d", &one[i], &two[i]);
        }

        memset(pd, -1, sizeof(pd));
        memset(marca, 0, sizeof(marca));

        pd[0] = 0;

        for (int i = 0; i < n; ++i)
        {
            if (one[i] == 0)
            {
                pd[1] = 1;
                marca[1][i] = 1;
                break;
            }
        }

        bt(2*n);

        //for (int i = 0; i <= 2*n; ++i) printf ("%d ", pd[i]); printf ("\n");

        if (pd[2*n] < INF) printf ("%d\n", pd[2*n]);
        else printf ("Too Bad\n");
    }

    return 0;
}

