#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int n, a[111], E, r;
long long res, sum;

void rec(int i, int e) {
    if (i == n + 1) {
        res = max(res, sum);
        return;
    }
    for (int j = 0; j <= e; j++) {
        sum += a[i] * j;
        rec(i + 1, min(e - j + r, E));
        sum -= a[i] * j;
    }
}

int main() {

    freopen("B2.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int T, cnt = 0;
    cin >> T;
    while (T > 0) {
        cout << "Case #" << ++cnt << ": ";
        cin >> E >> r >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        res = 0; sum = 0;
        rec(1, E);
        cout << res << endl;
        --T;
    }
}
