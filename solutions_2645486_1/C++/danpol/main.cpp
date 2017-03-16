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
    lld m = -1;
    lld s = 0;
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
        s += v[i];
        m = max(m, v[i]);
    }
    if (r >= e) {
        cout << e * s;
        return;
    }
    v.push_back(-1);
    s = 0;
    lld res = 0;
    lld ce = e;
    for (int i = 0; i < n; i++) {
        if (v[i] > v[i + 1]) {
                int j = 0;
                for (j = i + 1; j < n; j++)
                    if ((v[j] > v[j + 1]) && (v[j] > v[i]))
                        break;
                if (j == n)
                    j = n - 1;
                if ((((j - i) * r < e) && (v[j] > v[i])) && (i != n - 1)) {
                     if (ce == e) {
                        res += min(ce, r * (j - i)) * v[i];
                        ce -= min(ce, r * (j - i));
                    }
                    else
                        if (ce + r > e) {
                            res += (e - ce - r) *v[i];
                            ce -= (e - ce - r);
                        }
                }
                else {
                    res += ce * v[i];
                    ce = 0;
                }
            }
        else {
            if (ce == e) {
                res += r * v[i];
                ce -= r;
            }
            else
               if (ce + r > e) {
                    res += (e - ce - r) *v[i];
                    ce -= (e - ce - r);
               }

        }
        ce += r;
        if (ce > e)
            ce = e;
    }
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
