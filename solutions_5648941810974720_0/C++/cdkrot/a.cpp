// Copyright (C) 2016 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

array<string, 10> magic = {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto T = input<uint32_t>();
    for (uint32_t t = 1; t <= T; ++t) {
        std::map<char, int> cnts;
        string str = input<string>();
        for (char ch: str) {
            cnts[ch] += 1;
        }

        vector<int> ans;
        auto process = [&ans, &cnts](int id, int cnt) {
            for (int i = 0; i != cnt; ++i) {
                ans.push_back(id);
                for (char ch: magic[id]) {
                    cnts[ch] -= 1;
                    assert(cnts[ch] >= 0);
                }
            }
        };

        process(0, cnts['Z']);
        process(2, cnts['W']);
        process(4, cnts['U']);
        process(6, cnts['X']);
        
        process(3, cnts['R']);
        process(1, cnts['O']);
        process(5, cnts['F']);
        process(7, cnts['V']);
        process(8, cnts['G']);
        process(9, cnts['E']);

        for (auto p: cnts)
            assert(p.second == 0);
        std::sort(ans.begin(), ans.end());

        cout << "Case #" << t << ": ";
        for (auto v: ans)
            cout << v;
        cout << "\n";
    }
    
    return 0;
}
