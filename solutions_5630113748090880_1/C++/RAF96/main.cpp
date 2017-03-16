#include <bits/stdc++.h>

using namespace std;

void Solve(){
    set<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (st.count(x)) {
                st.erase(x);
            } else {
                st.insert(x);
            }
        }
    }
    for (auto x : st) {
        cout << x << ' ';
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    size_t t;
    cin >> t;
    for (size_t i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        Solve();
        cout << endl;
    }
    return 0;
}
