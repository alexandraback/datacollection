#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    int e, r, n;
    cin >> e >> r >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> l(n, 0);
    vector<int> h(n, e);

    vector<int> o;
    o.reserve(n);
    for (int i = 0; i < n; ++i) o.push_back(i);
    sort(o.begin(), o.end(), [&](int a, int b){
        return v[a] > v[b];
    });

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int m = o[i];
        sum += v[m] * (h[m] - l[m]);
        v[m] = 0;
        int t = l[m];
        l[m] = h[m];
        h[m] = t;
        for (unsigned j = m + 1; j < v.size(); ++j) {
            int x = h[m] + (j - m) * r;
            if (x < h[j]) {
                h[j] = x;
            } else break;
        }
        for (int j = m - 1; j >= 0; --j) {
            int x = l[m] - (m - j) * r;
            if (x > l[j]) {
                l[j] = x;
            } else break;
        }
    }
    cout << sum << endl;
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
