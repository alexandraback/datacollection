#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int T;
int n;
int a[1005], b[1005];
string as[1005], bs[1005];
map<string, int> mp;
int idx;

int main()
{
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-small-attempt0.out", "w", stdout);

    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int ttt = 1; ttt <= T; ++ttt) {
        cin >> n;
        mp.clear();
        idx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> as[i] >> bs[i];
            if (!mp[as[i]]) mp[as[i]] = ++idx;
            a[i] = mp[as[i]] - 1;
            if (!mp[bs[i]]) mp[bs[i]] = ++idx;
            b[i] = mp[bs[i]] - 1;
        }

        int ans = 0;
        for (int mask = (1 << n); mask--; ) {
            unsigned mask1 = 0, mask2 = 0;
            for (int i = 0; i < n; ++i) {
                if (((~mask) >> i) & 1) {
                    mask1 |= (1u << unsigned(a[i]));
                    mask2 |= (1u << unsigned(b[i]));
                }
            }
            int g = 1;
            for (int i = 0; g && i < n; ++i) {
                if ((mask >> i) & 1) {
                    if (!(mask1 & (1u << unsigned(a[i]))) || !(mask2 & (1u << unsigned(b[i]))))
                        g = 0;
                }
            }
            if (g)
                ans = max(ans, __builtin_popcount(mask));
        }

        cout << "Case #" << ttt << ": " << ans << "\n";
    }

    return 0;
}
