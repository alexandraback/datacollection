#include <cstdio>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 3000;

double P[N][N];

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

double rnd(double x)
{
    if (x < 1e-15)
        return 0;
    else
        return x;
}

double D[N][N];
void init()
{
    P[0][0] = 1.0;
    for (int n = 1; n < N; n++)
    {
        P[n][0] = P[n][n] = P[n - 1][0] / 2.0;
        for (int k = 1; k < n; k++)
            P[n][k] = rnd((P[n - 1][k - 1] + P[n - 1][k]) / 2.0);
    }
}

double stup(int b, int r, int nd)
{
    memset(D, 0, sizeof(D));
    D[0][0] = 1.0;
    for (int s = 0; s <= r; s++)
    {
        for (int p = 0; p <= s; p++)
        {
            int q = s - p;
            if (p > b + 1 || q > b + 1)
                continue;
            if (p != b + 1 && q != b + 1)
                D[p + 1][q] += 0.5 * D[p][q], D[p][q + 1] += 0.5 * D[p][q];
            else if (p != b + 1)
                D[p + 1][q] += D[p][q];
            else
                D[p][q + 1] += D[p][q];
        }
    }
    double ans = 0;
    for (int p = 0; p <= r; p++)
    {
        int q = r - p;
        if (p > b + 1 || q > b + 1)
            continue;
        if (p < nd)
            continue;
        ans += D[p][q];
    }
    return ans;
}

void solve(int tc)
{
    eprintf("\n");
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    int mx = 0;
    int b = 1;
    while ((b + 2) * (b + 3) / 2 <= n)
        b += 2;
    eprintf("bottom = %d\n", b);
    int r = n - b * (b + 1) / 2;
    eprintf("r = %d\n", r);
    assert(r < N);
    double ans = 0;
    if (x + y <= b - 1 && x - y >= -b + 1)
        ans = 1.0;
    else if (x + y == b + 1 || x - y == -b - 1 && x + y <= b - 1 && x - y >= -b - 1)
    {
        if (r <= b + 1)
        {
            eprintf("type 1\n");
            int k = y + 1;
            ans = 0;
            eprintf("taking P[%d][>= %d]\n", r, k);
            for (int i = k; i <= r; i++)
                ans += P[r][i];
        }
        else
        {
            eprintf("type 2\n");
            int f = 2 * b + 3 - r;
            assert(f >= 1);
            f--;
            int k = b + 1 - y;
            eprintf("taking P[%d][< %d]\n", f, k);
            for (int i = 0; i < min(f + 1, k); i++)
                ans += P[f][i];
            double sans = stup(b, r, y + 1);
            ans = sans;
        }
    }
    else
        ans = 0.0;
    printf("Case #%d: %.10lf\n", tc, ans);
}





int main()
{
    init();
    eprintf("inited\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        solve(i + 1);
    }
}
