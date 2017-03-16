#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = (int)(1e9);
const int MOD = (int)(1e9) + 7;

int solve() {
    int c, d, v;
    cin >> c >> d >> v;
    vector<int> a(d, 0);
    for(int i = 0; i < d; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, res = 0;
    long long j = 0;
    while (j < v) {
        while ((i < d) && (a[i] <= j + 1)) {
            j += 1LL * a[i] * c;
            i++;
        }
        if (j >= v) break;
        res++;
        j += 1LL * (j + 1) * c;
    }
    return res;
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("vuong.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}

