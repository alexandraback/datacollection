#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                if (s.find(x) == s.end())
                    s.insert(x);
                else
                    s.erase(s.find(x));
            }
        }
        for (auto it = s.begin(); it != s.end(); ++it) {
            cout << *it << ' ';
        }
        cout << '\n';
    }
    return 0;
}
