#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

auto solve() {
    string in;
    cin >> in;

    string res;
    auto e = in.cend();
    for (auto it = in.cbegin(); it != e; ++it) {
        if (*it < res[0]) {
            res += *it;
        } else {
            res = *it + res;
        }
    }
    cout << res << '\n';
}

int main() {
    auto cases = 0u;
    cin >> cases;

    for (auto c = 1; c <= cases; ++c) {
        cout << "Case #" << c << ": ";
        solve();
    }

    cout << flush;
    return 0;
}
