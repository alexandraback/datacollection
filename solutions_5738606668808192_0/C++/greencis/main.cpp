#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int t, n, j;

ll get(ll x, int base) {
    ll curb = 1;
    ll cur = 0;
    while (x) {
        cur += (x % 2) * curb;
        x /= 2;
        curb *= base;
    }

    for (ll i = 2; i * i <= cur; ++i) {
        ll rem = 1;
        for (int j = 0; j < n - 1; ++j)
            rem = (rem * base) % i;
        if ((cur + rem) % i == 0) return i;
    }
    return -1;
}

int main()
{
    //freopen("C-small-attempt2.in", "r", stdin);
    //freopen("C-small-attempt2.out", "w", stdout);

    cin >> t;
    int anss = 0;
    for (int ttt = 1; ttt <= t; ++ttt) {
        cin >> n >> j;
        cout << "Case #" << ttt << ":\n";
        for (unsigned i = 1; anss < j; i += 2) {
            bool good = true;
            vector<int> ans;
            for (int b = 2; b <= 10; ++b) {
                int c = get(i, b);
                if (c == -1) {
                    good = false;
                    break;
                }
                ans.push_back(c);
            }
            if (good) {
                anss++;
                string s;
                int cur = i;
                for (int z = 0; z < n; ++z) {
                    s += char(cur % 2 + 48);
                    cur /= 2;
                }
                reverse(s.begin(), s.end());
                s[0] = '1';
                cout << s;
                for (int z = 0; z < ans.size(); ++z)
                    cout << " " << ans[z];
                cout << "\n";
            }
        }
    }

    return 0;
}
