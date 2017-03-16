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

#define MAXN 128

typedef unsigned long long ll;

int n, m;
int A[MAXN], B[MAXN];
ll a[MAXN], b[MAXN];
ll p[MAXN][MAXN];
ll ar[MAXN][MAXN];
ll br[MAXN][MAXN];

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        printf ("Case #%d: ", caso);

        scanf ("%d %d", &n, &m);
        ++n; ++m;

        for (int i = 1; i < n; ++i)
        {
            scanf ("%lld %d", &a[i], &A[i]);
        }

        for (int i = 1; i < m; ++i)
        {
            scanf ("%lld %d", &b[i], &B[i]);
        }

        /*
        for (int i = 1; i < n - 1; ++i)
        {
            while (i < n-1 && A[i] == A[i+1])
            {
                a[i] += a[i+1];
                --n;
                for (int j = i+1; j < n; ++j)
                {
                    a[j] = a[j+1];
                    A[j] = A[j+1];
                }
            }
        }

        for (int i = 1; i < m - 1; ++i)
        {
            while (i < m-1 && B[i] == B[i+1])
            {
                b[i] += b[i+1];
                --m;
                for (int j = i+1; j < m; ++j)
                {
                    b[j] = b[j+1];
                    B[j] = B[j+1];
                }
            }
        }
        */

        /*
        for (int i = 0; i < n; ++i)
        {
            printf ("(%lld, %d) ", a[i], A[i]);
        }
        printf ("\n");
        for (int i = 0; i < m; ++i)
        {
            printf ("(%lld, %d) ", b[i], B[i]);
        }
        printf ("\n");
        */

        memset(p, 0, sizeof(p));
        memset(ar, 0, sizeof(ar));
        memset(br, 0, sizeof(br));

        for (int i = 0; i < n; ++i)
        {
            ar[i][0] = a[i];
            br[i][0] = b[i];
        }
        for (int i = 0; i < m; ++i)
        {
            ar[0][i] = a[i];
            br[0][i] = b[i];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (A[i] == B[j])
                {
                    br[i][j] = b[j] - min(ar[i][j-1], b[j]);
                    ar[i][j] = ar[i][j-1] - min(ar[i][j-1], b[j]);
                    p[i][j] = p[i][j-1] + min(ar[i][j-1], b[j]);

                    ll k = min(a[i], br[i-1][j]);
                    if (p[i-1][j] + k > p[i][j])
                    {
                        ar[i][j] = a[i] - k;
                        br[i][j] = br[i-1][j] - k;
                        p[i][j] = p[i-1][j] + k;
                    }
                    else if (p[i-1][j] + k == p[i][j] && (a[i] - k > ar[i][j] || br[i-1][j] - k > br[i][j]))
                    {
                        ar[i][j] = a[i] - k;
                        br[i][j] = br[i-1][j] - k;
                        p[i][j] = p[i-1][j] + k;
                    }

                    k = min(a[i], b[j]);
                    if (p[i-1][j-1] + k > p[i][j])
                    {
                        ar[i][j] = a[i] - k;
                        br[i][j] = b[j] - k;
                        p[i][j] = p[i-1][j-1] + k;
                    }
                    else if (p[i-1][j-1] + k == p[i][j] && (a[i] - k > ar[i][j] || b[i] - k > br[i][j]))
                    {
                        ar[i][j] = a[i] - k;
                        br[i][j] = b[j] - k;
                        p[i][j] = p[i-1][j-1] + k;
                    }
                }
                else
                {
                    br[i][j] = b[j];
                    ar[i][j] = ar[i][j-1];
                    p[i][j] = p[i][j-1];

                    if (p[i-1][j] > p[i][j])
                    {
                        ar[i][j] = a[i];
                        br[i][j] = br[i-1][j];
                        p[i][j] = p[i-1][j];
                    }
                    else if (p[i-1][j] == p[i][j] && a[i] >= ar[i][j] && br[i-1][j] >= br[i][j])
                    {
                        ar[i][j] = a[i];
                        br[i][j] = br[i-1][j];
                        p[i][j] = p[i-1][j];
                    }

                    if (p[i-1][j-1] >= p[i][j])
                    {
                        ar[i][j] = a[i];
                        br[i][j] = b[j];
                        p[i][j] = p[i-1][j-1];
                    }
                }
            }
        }
        
        /*
        printf ("\n");
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                printf ("%2llu ", p[i][j]);
            }
            printf ("\n");
        }
        printf ("\n");
        */

        printf ("%llu\n", p[n-1][m-1]);
    }

    return 0;
}

