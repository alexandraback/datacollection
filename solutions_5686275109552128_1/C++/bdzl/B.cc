#include <bits/stdc++.h>
using namespace std;

const int kMaxP = 1e3;

vector<vector<int> > need_to_dec;

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    need_to_dec.resize(kMaxP + 1, vector<int>(kMaxP + 1));
    for (int j = 1; j <= kMaxP; ++j) {
        need_to_dec[1][j] = 0;
    }
    for (int i = 2; i <= kMaxP; ++i) {
        for (int j = i; j <= kMaxP; ++j) {
            need_to_dec[i][j] = 0;
        }
        for (int j = 1; j < i; ++j) {
            need_to_dec[i][j] = i;
            for (int dx = 1; dx < i; ++dx) {
                need_to_dec[i][j] = min(need_to_dec[i][j], need_to_dec[i - dx][j] + need_to_dec[dx][j] + 1);
            }
        }
    }

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ans = max(ans, a[i]);
        }
        mx = ans;
        for (int up = 1; up <= mx; ++up) {
            int cur_ans = 0;
            for (int i = 0; i < n; ++i) {
                cur_ans += need_to_dec[a[i]][up];
            }
            ans = min(ans, cur_ans + up);
        }
        cout << "Case #" << test << ": ";
        cout << ans << endl;
    }

    return 0;
}
