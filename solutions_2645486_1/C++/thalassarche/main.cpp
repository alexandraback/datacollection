#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    long long e, r, n;
    cin >> e >> r >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<long long> l(n, 0);
    vector<long long> h(n, e);

    vector<long long> o;
    o.reserve(n);
    for (long long i = 0; i < n; ++i) o.push_back(i);
    sort(o.begin(), o.end(), [&](long long a, long long b){
        return v[a] > v[b];
    });

    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        long long m = o[i];
        sum += v[m] * (h[m] - l[m]);
        v[m] = 0;
        long long t = l[m];
        l[m] = h[m];
        h[m] = t;
        for (unsigned j = m + 1; j < v.size(); ++j) {
            long long x = h[m] + (j - m) * r;
            if (x < h[j]) {
                h[j] = x;
            } else break;
        }
        for (long long j = m - 1; j >= 0; --j) {
            long long x = l[m] - (m - j) * r;
            if (x > l[j]) {
                l[j] = x;
            } else break;
        }
    }
    cout << sum << endl;
}

int main()
{
    long long t;
    cin >> t;
    for (long long i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
