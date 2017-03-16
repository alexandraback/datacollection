#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

typedef long long lld;

void solve() {
    lld e, r, n;
    cin >> e >> r >> n;
    vector <lld> v(n);
    for (int i = 0; i < n ; i++)
        cin >> v[i];
    lld d[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            d[i][j] = -1;
    d[0][e] = 0;
    for (int i = 0; i < n; i++)
        for (int p = 0; p <= e; p++)
            for (int q = 0; q <= e; q++)
                if (p - q >= 0)
                d[i + 1][min(p - q + r, e)] = max(d[i + 1][min(p - q + r, e)], d[i][p] + v[i] * q);
    lld res = -1;
    for (int i = 0; i <= e; i++)
        if (res < d[n][i])
            res = d[n][i];
    cout << res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
    fflush(stdout);
    return 0;
}
