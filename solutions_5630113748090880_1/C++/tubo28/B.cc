#define _CRT_SECURE_NO_WARNINGS
// #define _GLIBCXX_DEBUG
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)

using vi = vector<int>;
using vii = vector < vector<int>>;

int n;
vii a;

vi solveLarge() {
    map<int, int> cnt;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            ++cnt[a[i][j]];
        }
    }
    vector<int> res;
    for (auto &e : cnt) {
        if (e.second % 2 == 1) {
            res.push_back(e.first);
        }
    }
    assert(res.size() == n);
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        a.assign(n * 2 - 1, vector<int>(n));
        for (int i = 0; i < n * 2 - 1; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> ans = solveLarge();
        printf("Case #%d:", 1 + i);
        for (int i = 0; i < n; i++) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
}