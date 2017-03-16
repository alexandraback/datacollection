#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long long ll;
const int N = 55;

int n;
ll m;
bool go[N][N];

void solve()
{
    memset(go, 0, sizeof(go));
    scanf("%d%lld", &n, &m);

    if (m > (1LL << (n - 2)))
    {
        puts("IMPOSSIBLE");
        return;
    }

    if (m == (1LL << (n - 2)))
    {
        go[0][n - 1] = true;
        m--;
    }

    for (int i = 1; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            go[i][j] = true;

    for (int i = 0; i < n - 2; i++)
        if (m & (1LL << i))
            go[0][n - 2 - i] = true;

    puts("POSSIBLE");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d", (int)go[i][j]);
        printf("\n");
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}
