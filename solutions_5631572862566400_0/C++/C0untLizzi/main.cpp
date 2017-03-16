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

    vector<int> friends;
    for (auto i = 0u; i < n; ++i) {
        auto t = 0;
        cin >> t;
        t -= 1;
        friends.push_back(t);
    }

    std::vector<int> longest;
    for (auto i = 0; i < n; ++i) {
        vector<int> current;
        current.push_back(i);
        auto l = i;
        while (true) {
            auto t = friends[l];
            auto it = find(current.begin(), current.end(), t);
            if (it != current.end()) {
                /*if(it != current.begin()) {
valid = false;
                }*/
                auto done = true;
                for (auto j = 0; j < friends.size(); ++j) {
                    if (friends[j] == t &&
                        find(current.begin(), current.end(), j) ==
                            current.end()) {
                        done = false;
                        current.push_back(j);
                        l = j;
                        break;
                    }
                }
                if (done) {
                    break;
                }
            }
            current.push_back(t);
            l = t;
        }
        if (current.size() > longest.size() &&
            friends[current[current.size() - 1]] == current[0]) {
            longest = current;
        }
    }
    cout << longest.size() << '\n';
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
