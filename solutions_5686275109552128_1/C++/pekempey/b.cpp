#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int D, P[1000];
int a[1001];

int maxe(int ub) {
    for (int i = ub; i >= 1; i--) {
        if (a[i]) return i;
    }

    return 0;
}

int count(int n) {
    fill_n(a, 1001, 0);

    for (int i = 0; i < D; i++) {
        a[P[i]]++;
    }

    int sp = 0;
    int ub = 1000;

    for (;;) {
        int v = maxe(ub);
        ub = v;

        if (v <= n) {
            return v + sp;
        }

        a[n] += v / n;
        if (v % n > 0) {
            a[v % n]++;
            sp++;
        }

        a[v]--;
        sp += v / n - 1;
    }
}

int solve() {
    int mini = 10000;
    for (int i = 2; i <= 1000; i++) {
        int val = count(i);

        mini = min(mini, val);
    }

    return mini;
}

int main() {
    int q;
    cin >> q;

    for (int k = 1; k <= q; k++) {
        cin >> D;

        for (int i = 0; i < D; i++) {
            cin >> P[i];
        }

        int ans = solve();

        printf("Case #%d: %d\n", k, ans);
    }
}
