#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = (int)(1e9);
const int MOD = (int)(1e9) + 7;

int r, c, w;

int solve() {
    cin >> r >> c >> w;
    int res = 1;
    int p = w, prv = 0;
    while (p + w <= c) {
        res++; prv = p; p += w;
    }
    int x = p - prv, y = c - p;
    if (min(x, y) == 0) res += w - 1;
    else if (x + y == w - 1) res += w - 1;
    else res += w;
    return res;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}

