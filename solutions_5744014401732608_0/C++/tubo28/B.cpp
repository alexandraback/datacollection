#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

using namespace std;
#define all(c) begin(c), end(c)
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using pii = pair<int, int>;
#define VV(T) vector<vector<T>>

using vi = vector<int>;
using vvi = vector<vector<int>>;

// 頂点数B
// M通りつくれるか？
vvi solve(ll B, ll M) {
    vector<pair<int, int>> es;
    ll m = M;
    int last = 1;

    int k = 0; // 中間に必要な数
    while (m) {
        if (m & 1) {
            if (es.empty()) {
                // 初めてなら 0-(B-1) に直接つくる 間にk個入れる
                for (int i = 0; i <= k + 1; ++i) {
                    for (int j = i + 1; j <= k + 1; ++j) {
                        es.emplace_back(i, j != k + 1 ? j : B - 1);
                    }
                }
                last = k + 1;
            } else {
                // そうでないなら中継点 (last) o o o (B-1) に作る
                // 0->lastをつなげる
                es.emplace_back(0, last);
                for (int i = last; i <= last + k + 1; ++i) {
                    for (int j = i + 1; j <= last + k + 1; ++j) {
                        es.emplace_back(i, j != last + k + 1 ? j : B - 1);
                    }
                }
                last = last + k + 1;
            }
        }
        ++k;
        m /= 2;
    }

    if (last > B-1) return{};
    vvi res(B, vi(B));
    for (auto &e : es) {
        if (e.first >= B || e.second >= B) return{};
        res[e.first][e.second] = 1;
    }
    return res;
}


ll count(vvi mat) {
    int n = mat.size();
    vector<ll> dp(n);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j]) {
                dp[j] += dp[i];
            }
        }
    }

    return dp[n - 1];
}

int main() {
    //solve(3, 3);

    //for (int b = 2; b <= 6; ++b){
    //    for (int m = 1; m <= 20; ++m) {
    //        auto ans = solve(b, m);
    //        if (ans.size() != 0) {
    //            ll way = count(ans);
    //            if (way != m) {
    //                for (int i = 0; i < b; ++i) {
    //                    for (int j = 0; j < b; ++j) {
    //                        if(ans[i][j]) cout << i << ' ' << j << endl;
    //                    }
    //                }
    //                assert(false);
    //            }
    //        }
    //    }
    //}


    int T;
    cin >> T;
    rep(it, T) {
        ll B, M;
        cin >> B >> M;
        cout << "Case #" << it + 1 << ':';
        auto ans = solve(B, M);
        cout << ' ' << (ans.size() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        if (ans.size()) {
            for (int i = 0; i < B; ++i) {
                for (int j = 0; j < B; ++j) {
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }
    }
}