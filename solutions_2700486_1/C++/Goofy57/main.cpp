#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define mp make_pair
using namespace std;

const int maxn = 10000;

int used[maxn][maxn];
double mas[maxn][maxn];
int mm, tofall;
int n0, k0;
int n, x, y;
int tc;

double solve(int n, int k)
{
    if (k == 0) return 1;
    if (n == 0) return !k;
    if (used[n][k] == tc) return mas[n][k];
    used[n][k] = tc;
    int falledL = k0 - k;
    int falledR = n0 - n - falledL;
    double ans = 0;
    if (falledL < tofall && falledR < tofall)
        return mas[n][k] = 0.5 * solve(n - 1, k - 1) + 0.5 * solve(n - 1, k);
    if (falledL == tofall) return mas[n][k] = solve(n - 1, k);
    return mas[n][k] = solve(n - 1, k - 1);
}
int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (tc = 1; tc <= t; tc++)
    {
        printf("Case #%d: ", tc);
        cin >> n >> x >> y;
        int k = 1;
        while (1)
        {
            int m = k + 1;
            if (m * (2 * m - 1) > n) break;
            else k++;
        }

        n -= k * (2 * k - 1);
        if (abs(x) + abs(y) < 2 * k)
        {
            printf("%.10lf\n", 1.0);
            continue;
        }
        if (abs(x) + abs(y) > 2 * k)
        {
            printf("%.10lf\n", 0.0);
            continue;
        }
        mm = 2 * k + (2 * k + 1);
        tofall = mm / 2;
        n0 = n, k0 = y + 1;

        printf("%.10lf\n", solve(n, y + 1));
    }


    return 0;
}
