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

void topsort(const vector<vector<char>>& matrix, vector<char>& used, uint32_t v, vector<uint32_t>& order) {
    for (uint32_t u = 0; u != matrix.size(); ++u)
        if (matrix[u][v] and not used[u]) {
            used[u] = 1;
            topsort(matrix, used, u, order);
        }
    order.push_back(v);
}

uint64_t count(const vector<vector<char>>& matrix) {
    uint32_t n = matrix.size();
    vector<uint64_t> cnts(n, 0);
    cnts[0] = 1;

    for (uint32_t i = 0; i != n; ++i)
        for (uint32_t j = 0; j != n; ++j)
            if (matrix[i][j])
                assert(i < j);
    
    vector<uint32_t> order;
    vector<char> used(n, 0);
    for (uint32_t i = 0; i != n; ++i)
        if (not used[n - 1 - i]) {
            used[n - 1 - i] = 1;
            topsort(matrix, used, n - 1 - i, order);
        }
    assert(order.size() == n);
    for (uint32_t i: order)
        for (uint32_t j = 0; j != n; ++j)
            if (matrix[j][i])
                cnts[i] += cnts[j];
    return cnts[n - 1];
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t T = input<uint32_t>();
    for (uint32_t t = 1; t <= T; ++t) {
        uint64_t n, m;
        cin >> n >> m;
        if (m > (1ull << (n - 2)))
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        else {
            cout << "Case #" << t << ": POSSIBLE\n";
            vector<vector<char>> matrix(n, vector<char>(n, 0));
            for (uint32_t i = 0; i != n - 1; ++i)
                for (uint32_t j = 0; j != i; ++j)
                    matrix[j][i] = 1;
            if (m == (1ull << (n - 2)))
                for (uint32_t i = 0; i != n - 1; ++i)
                    matrix[i][n - 1] = 1;
            else {
                for (uint64_t i = 0; i != 60; ++i)
                    if (m & (1ull << i)) {
                        matrix[i + 1][n - 1] = 1;
                    }
            }
            assert(count(matrix) == m);
            for (uint32_t i = 0; i != n; ++i, cout << "\n")
                for (uint32_t j = 0; j != n; ++j)
                    cout << int(matrix[i][j]);
        }
    }
    
    return 0;
}
