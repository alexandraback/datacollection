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
    vector<bool> ok(v + 1, false);
    ok[0] = true;
    for(int i = 0; i < d; i++) {
        vector<int> b;
        for(int j = 0; j <= v - a[i]; j++) {
            if (ok[j]) {
                b.push_back(j + a[i]);
            }
        }
        for(int j = 0; j < b.size(); j++) ok[b[j]] = true;
    }
    int res = 0;
    for(int i = 1; i <= v; i++) {
        if (!ok[i]) {
            res++;
            vector<int> b;
            b.push_back(i);
            for(int j = 0; j <= v - i; j++) {
                if (ok[j]) {
                    b.push_back(j + i);
                }
            }
            for(int j = 0; j < b.size(); j++) ok[b[j]] = true;
        }
    }
    return res;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}

