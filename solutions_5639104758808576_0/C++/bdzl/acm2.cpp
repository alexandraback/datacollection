#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        int sum = s[0] - '0';
        for (int i = 1; i <= n; ++i) {
            int x = s[i] - '0';
            if (x > 0) {
                while (sum < i) {
                    ++ans;
                    ++sum;
                }
                sum += x;
            }
        }
        cout << "Case #" << test + 1 << ": ";
        cout << ans << endl;
    }

    return 0;
}
