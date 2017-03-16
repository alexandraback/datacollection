#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long double> m(n, 0), k(n, 0);
    for (auto& d: m) cin >> d;
    for (auto& d: k) cin >> d;
    sort(m.begin(), m.end());
    sort(k.begin(), k.end());
    
    int p1 = n, p2 = 0;
    vector<char> b(n, true);
    for (int i = m.size() - 1; i >= 0; --i) {
        int j = 0;
        while (j < k.size() && (k[j] < m[i] || !b[j])) ++j;
        if (j >= k.size()) j = 0;
        b[j] = false;
        if (k[j] > m[i]) --p1;
    }
    
    int j = 0;
    for (int i = 0; i < m.size(); ++i) {
        while (i < m.size() && m[i] < k[j]) ++i;
        if (i < m.size()) {
            ++j;
            ++p2;
        }
    }
    
    cout << p2 << " " << p1 << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
