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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t T = input<uint32_t>();

    for (uint32_t t = 1; t <= T; ++t) {
        uint32_t id1 = 0, id2 = 0;
        std::map<string, uint32_t> map1, map2;
        
        vector<pair<uint32_t, uint32_t>> data(input<uint32_t>());
        for (auto& v: data) {
            string s1, s2;
            cin >> s1 >> s2;
            if (map1.find(s1) == map1.end())
                map1[s1] = id1++;
            if (map2.find(s2) == map2.end())
                map2[s2] = id2++;
            v = {map1[s1], map2[s2]};
        }

        vector<uint32_t> cnt1(id1, 0), cnt2(id2, 0);
        for (auto v: data)
            cnt1[v.first] += 1, cnt2[v.second] += 1;
        
        uint32_t ans = 0;
        for (uint32_t msk = 0; msk != (1u << data.size()); ++msk) {
            uint32_t popcnt = 0;
            vector<uint32_t> cnt1_do(id1, 0), cnt2_do(id2, 0);
            for (uint32_t i = 0; i != data.size(); ++i)
                if (msk & (1u << i))
                    cnt1_do[data[i].first] += 1, cnt2_do[data[i].second] += 1, popcnt += 1;

            bool scs = true;
            for (uint32_t i = 0; i != id1 and scs; ++i)
                scs = cnt1_do[i] < cnt1[i];
            for (uint32_t i = 0; i != id2 and scs; ++i)
                scs = cnt2_do[i] < cnt2[i];
            if (scs)
                ans = max(ans, popcnt);
        }
        
        printf("Case #%u: %u\n", t, ans);
    }
    
    return 0;
}
