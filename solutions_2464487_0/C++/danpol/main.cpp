#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef unsigned long long ull;

void solve() {
    ull t, r0;
    cin >> r0 >> t;
    if (t < (1 + 2 * r0)) {
        cout << "0";
        return;
    }
    ull l = 1;
    ull r = (1 << 30);
    while (r - l > 1) {
        ull n= l + (r - l) / 2;
        if (t >= ((1 + 2 * r0) * n + 2 * (n - 1) * n))
            l = n;
        else
            r = n;
    }
    cout << l;
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
