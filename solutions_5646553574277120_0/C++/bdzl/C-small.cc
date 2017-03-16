#include <bits/stdc++.h>
using namespace std;

void AddToKnapsack(int val, vector<int>& used, int lim)
{
    for (int i = lim; i >= 0; --i) {
        if (used[i] && i + val <= lim) {
            used[i + val] = 1;
        }
    }
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int c, d, v;
        cin >> c >> d >> v;
        vector<int> a(d);
        for (int i = 0; i < d; ++i) {
            cin >> a[i];
        }
        vector<int> used(v + 1, 0);
        used[0] = 1;
        for (int i = 0; i < d; ++i) {
            AddToKnapsack(a[i], used, v);
        }
        int ans = 0;
        for (int i = 1; i <= v; ++i) {
            if (!used[i]) {
                AddToKnapsack(i, used, v);
                ++ans;
            }
        }
        cout << "Case #" << test + 1 << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
