#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

auto solve() {
    auto n = 0u;
    cin >> n;
    vector<vector<int>> l;

    for (auto i = 0u; i < 2 * n - 1; ++i) {
        vector<int> new_vec;
        for (auto j = 0u; j < n; ++j) {
            auto t = 0;
            cin >> t;
            new_vec.push_back(t);
        }
        l.push_back(move(new_vec));
    }

    std::map<int, int> count;
    for (const auto& e : l) {
        for (const auto& f : e) {
            count[f]++;
        }
    }
    for (auto it = count.cbegin(); it != count.cend(); ++it) {
        if (it->second % 2 != 0) {
            cout << " " << it->first;
        }
    }
    cout << '\n';
}

int main() {
    auto cases = 0u;
    cin >> cases;

    for (auto c = 1; c <= cases; ++c) {
        cout << "Case #" << c << ":";
        solve();
    }

    cout << flush;
    return 0;
}
