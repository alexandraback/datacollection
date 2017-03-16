#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

template < typename T > T next() { T tmp; cin >> tmp; return tmp; }

void solve() {
    int d = next< int >();
    vector< int > p(d);
    generate(p.begin(), p.end(), next< int >);
    int mx = *max_element(p.begin(), p.end());
    int best = mx;
    for (int i = 1; i <= mx; ++i) {
        int add = 0;
        for (size_t j = 0; j < p.size(); ++j) {
            add += max((p[j] + i - 1) / i - 1, 0);
        }
        best = min(add + i, best);
    }
    cout << best << endl;
}

int main() {
    int t = next< int >();
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
