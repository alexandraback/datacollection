#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

// Problem B

#define MAXN 128

int c[MAXN][MAXN];
int f[MAXN][MAXN];
double t[MAXN][MAXN];

int h, n, m;

double low(int i, int j, double x)
{
    return max((double) f[i][j], h - 10*x);
}

double minmt(int i, int j, int k, int l)
{
    return max(t[i][j], (h + 50.0 - c[k][l]) / 10);
}

bool pode(const int i, const int j, const int k, const int l, const double x)
{
    //printf ("%f %f %d\n", x, low(i, j, x), c[k][l] - 50);
    if (low(i, j, x) > c[k][l] - 50 + 1e-9) { /*printf ("a\n");*/ return false;}
    if (low(k, l, x) > c[k][l] - 50 + 1e-9) { /*printf ("b\n");*/ return false;}
    if (f[k][l] > c[i][j] - 50) { /*printf ("c\n");*/ return false;}
    return true;
}

double tempo(const int i, const int j, const int k, const int l, double x)
{
    if (x < 1e-9) return x;

    if (low(i, j, x) - f[i][j] >= 20) return x+1;
    return x+10;
}

void calc(const int i, const int j)
{
    if (i > 0 && pode(i, j, i-1, j, minmt(i, j, i-1, j)))
    {
        t[i-1][j] = min(t[i-1][j], tempo(i, j, i-1, j, minmt(i, j, i-1, j)));
    }

    if (i < n-1 && pode(i, j, i+1, j, minmt(i, j, i+1, j)))
    {
        t[i+1][j] = min(t[i+1][j], tempo(i, j, i+1, j, minmt(i, j, i+1, j)));
    }

    if (j > 0 && pode(i, j, i, j-1, minmt(i, j, i, j-1)))
    {
        t[i][j-1] = min(t[i][j-1], tempo(i, j, i, j-1, minmt(i, j, i, j-1)));
    }

    //if (j < m-1) printf ("%d\n", pode(i, j, i, j+1, minmt(i, j, i, j+1)));
    if (j < m-1 && pode(i, j, i, j+1, minmt(i, j, i, j+1)))
    {
        //printf ("%f\n", tempo(i, j, i, j+1, minmt(i, j, i, j+1)));
        t[i][j+1] = min(t[i][j+1], tempo(i, j, i, j+1, minmt(i, j, i, j+1)));
    }
}

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        printf ("Case #%d: ", caso);

        scanf ("%d %d %d", &h, &n, &m);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf ("%d", &c[i][j]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf ("%d", &f[i][j]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                t[i][j] = 0x3f3f3f3f;
            }
        }
        t[0][0] = 0;

        double mint = -1;
        while (mint < 0x3f3f3f3f - 1)
        {
            //printf ("%f\n", mint);
            double cand = 0x3f3f3f3f;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (t[i][j] > mint && t[i][j] < cand)
                    {
                        cand = t[i][j];
                    }
                }
            }

            mint = cand;

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (t[i][j] <= mint)
                    {
                        calc(i, j);
                    }
                }
            }
        }

        printf ("%.7f\n", t[n-1][m-1]);

        /*
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                printf ("%f ", t[i][j]);
            }
            printf ("\n");
        }
        printf ("\n");
        */
    }

    return 0;
}

