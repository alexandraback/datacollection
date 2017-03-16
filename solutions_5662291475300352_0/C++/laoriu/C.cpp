#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = (int)(1e9);
const int MOD = (int)(1e9) + 7;

long long calc(pair<int, int> a, int n) {
    return 1LL * a.second * (n - a.first);
}

int solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > a;
    for(int i = 1; i <= n; i++) {
        int d, h, m;
        cin >> d >> h >> m;
        for(int j = m; j <= m + h - 1; j++) {
            a.push_back(make_pair(d, j));
        }
    }
    if (a.size() == 0) return 0;
    if (a.size() == 1) return 0;
    if (calc(a[0], 360) > calc(a[1], 360)) swap(a[0], a[1]);
    if (calc(a[0], 720) > calc(a[1], 360)) return 0;
    return 1;
}

int main()
{
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}
