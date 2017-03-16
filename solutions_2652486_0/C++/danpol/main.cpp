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
    int r, n, m, k;
    cin >> r >> n >> m >> k;
    for (int i = 0; i < r; i++) {
        bool sol = false;
            vector <int> v(k);
        for (int i = 0; i < k; i++)
            cin >> v[i];
        for (int i = 2; i <= 5; i++)
            for (int j = 2; j <= 5; j++)
                for (int q = 2; q <= 5; q++)
                if (! sol) {
                    bool good = true;
                    for (int p = 0; p < k; p++)
                        if ((i * j * q != v[p]) && (i * j != v[p]) && (i * q != v[p]) && (j * q != v[p]) && (i != v[p]) && (j != v[p]) && (q != v[p]) && (1 != v[p]))
                        good = false;
                    if (good) {
                        cout << i << j << q << "\n";
                        sol = true;
                    }
                }

    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        cout << "Case #" << i << ": \n";
        solve();
        cout << "\n";
    }
    fflush(stdout);
    return 0;
}
