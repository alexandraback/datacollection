#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int n;
vl v;
void out (int t) {
    for (int l = 0; l < n; ++l) if (t & (1 << l))
        cout << v[l] << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        sort(v.begin(), v.end());
        vector<pli> ts;
        for (int mask = 1; mask < (1 << n); ++mask) {
            ll sum = 0;
            for (int l = 0; l < n; ++l) if (mask & (1 << l))
                sum += v[l];
            ts.push_back(pli(sum, mask));
        }
        sort(ts.begin(), ts.end());
        cout << "Case #" << test << ":\n";
        bool was = 0;
        for (int i = 1; i < ts.size(); ++i) if (ts[i].first == ts[i - 1].first) {
            was = 1;
            out(ts[i].second);
            out(ts[i - 1].second);
            break;
        }
        if (!was)
            cout << "Impossible";
        cout << endl;
    }
    return 0;
}
