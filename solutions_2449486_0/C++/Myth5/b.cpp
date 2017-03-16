#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;

int n, m, r[maxn], c[maxn], a[maxn][maxn];

bool check()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != min(r[i], c[j]))
                return false;
    return true;
}

int main()
{
    freopen("b1.in", "r", stdin);
    freopen("b1.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            r[i] = 0;
        for (int j = 1; j <= m; ++j)
            c[j] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                if (a[i][j] > r[i])
                    r[i] = a[i][j];
                if (a[i][j] > c[j])
                    c[j] = a[i][j];
            }
        printf("%s", check() ? "YES" : "NO");
        printf("\n");
    }
    
    return 0;
}
