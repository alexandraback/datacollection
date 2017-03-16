#include <bits/stdc++.h>
using namespace std;

const int kAlphabetSize = 26;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int k, l, s;
        cin >> k >> l >> s;
        swap(l, s);
        string sk;
        string ss;
        cin >> sk >> ss;
        int sc[kAlphabetSize];
        for (int c = 0; c < kAlphabetSize; ++c) {
            sc[c] = 0;
        }
        for (int i = 0; i < k; ++i) {
            ++sc[sk[i] - 'A'];
        }
        double ans = 1.0;
        for (int j = 0; j < s; ++j) {
            int c = ss[j] - 'A';
            ans = ans * (1.0 * sc[c] / k);
        }
        ans *= (l - s + 1);
        int max_amount = 0;
        string sl;
        sl.resize(l);
        for (int i = 0; i < l; ++i) {
            sl[i] = '?';
        }
        for (int i = 0; i + s - 1 < l; ++i) {
            bool good = true;
            for (int j = 0; j < s; ++j) {
                if (sl[i + j] == '?' || sl[i + j] == ss[j]) {
                    continue;
                }
                good = false;
            }
            if (good) {
                for (int j = 0; j < s; ++j) {
                    sl[i + j] = ss[j];
                }
                ++max_amount;
            }
        }
        for (int i = 0; i < s; ++i) {
            if (sc[ss[i] - 'A'] == 0) {
                max_amount = 0;
            }
        }
        ans = max_amount - ans;
        cout << "Case #" << test + 1 << ": ";
        cout << ans << endl;
    }
    return 0;
}
