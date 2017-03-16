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
#include <tuple>

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

template <typename T>
T slowpow(T a, uint32_t n) {
    T res = 1;
    for (uint32_t i = 0; i != n; ++i)
        res = res * a;
    return res;
}

string s1, s2;

string s1_best, s2_best;
int64_t best_delta;

void solve(int pos, int64_t cur_delta, int64_t pw) {
    if (abs(cur_delta) - 10 * pw > abs(best_delta))
        return;
    
    if (pos == (int)s1.size()) {
        if (abs(cur_delta) < abs(best_delta))
            best_delta = cur_delta, s1_best = s1, s2_best = s2;
    } else {
        vector<pair<char,char>> psb;
        if (s1[pos] != '?' and s2[pos] != '?')
            psb = {{s1[pos], s2[pos]}};
        else if (s1[pos] == '?' and s2[pos] == '?') {
            psb.push_back({'0', '9'});
            psb.push_back({'9', '0'});
            psb.push_back({'1', '0'});
            psb.push_back({'0', '1'});
            psb.push_back({'0', '0'});
        } else if (s1[pos] != '?') {
            for (auto ch2: vector<char>{'0', '9', char(s1[pos] - 1), s1[pos], char(s1[pos] + 1)})
                if ('0' <= ch2 and ch2 <= '9')
                    psb.push_back({s1[pos], ch2});
        } else {
            for (auto ch1: {'0', '9', char(s2[pos] - 1), s2[pos], char(s2[pos] + 1)})
                if ('0' <= ch1 and ch1 <= '9')
                    psb.push_back({ch1, s2[pos]});
        }

        std::sort(psb.begin(), psb.end());
        
        for (pair<char, char> nch: psb) {
            pair<char, char> och = {s1[pos], s2[pos]};
            std::tie(s1[pos], s2[pos]) = nch;
            
            solve(pos + 1, cur_delta + (nch.first - '0') * pw - (nch.second - '0') * pw, pw / 10);
            std::tie(s1[pos], s2[pos]) = och;
        }
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t T = input<uint32_t>();
    for (uint32_t t = 0; t != T; ++t) {
        best_delta = INT32_MAX;
        cin >> s1 >> s2;
        assert(s1.size() == s2.size());

        int pw = 1;
        for (int i = 0; i != (int)s1.size() - 1; ++i)
            pw *= 10;
        solve(0, 0, pw);
        
        cout << "Case #" << t + 1 << ": " << s1_best << " " << s2_best << "\n"; 
    }
    
    return 0;
}
