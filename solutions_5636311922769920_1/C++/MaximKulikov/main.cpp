#include <cstdio>
#include <iostream>

using namespace std;

#define PROBLEM "D-large"

long long getPossition(long long k, int i, int c) {
    long long offset = 0;
    for (int j = 0; j < c-1; ++j) {
        offset = (offset + i) * k;
        if (i < k-1) {
            ++i;
        }
    }
    return offset + i + 1;
}

void solve(long long k, int c, int s) {
    if (s * c < k) {
        cout << " IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 0, l = 0; i < s && l < k; ++i, l += c) {
        cout << " " << getPossition(k, l, c);
    }
    cout << endl;
}

int main()
{
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int k, c, s;
        cin >> k >> c >> s;
        cout << "Case #" << t << ":";
        solve(k, c, s);
    }

    return 0;
}
