#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int maxn = 1024;
double wNaomi[maxn];
double wKen[maxn];

bool check(int p, int n)
{
    for (int i = p; i < n; ++i)
        if (wNaomi[i] < wKen[i - p])
            return false;
    return true;
}

void Solved()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> wNaomi[i];
    for (int i = 0; i < n; ++i)
        cin >> wKen[i];
    sort(wNaomi, wNaomi + n);
    sort(wKen, wKen + n);
    int result1 = 0, result2 = 0;
    for (int p = 0; p < n; ++p)
        if (check(p, n))
        {
            result1 = n - p;
            break;
        }
    int p2 = 0;
    result2 = n;
    for (int i = 0; i < n && p2 < n; ++i)
    {
        while (p2 < n && wKen[p2] < wNaomi[i]) ++p2;
        if (p2 == n) break;
        ++p2, --result2;
    }
    printf("%d %d\n", result1, result2);
}

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);

    int nT = 1;
    scanf("%d", &nT);
    for (int nCase = 1; nCase <= nT; ++nCase)
    {
        printf("Case #%d: ", nCase);
        Solved();
    }

    return 0;
}