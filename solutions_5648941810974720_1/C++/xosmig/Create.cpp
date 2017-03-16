
#include <bits/stdc++.h>

using namespace std;

typedef int INT;
typedef long long ll;
typedef long double ld;
#define int ll

typedef pair<int, int> pii;
#define one first
#define two second

#define isize(v) static_cast<int>(v.size())

#define qfor(i, a, b) for (int i = static_cast<int>(a), _end_ = static_cast<int>(b); i < _end_; ++i)
#define fori(n) qfor(i, 0, n)
#define forj(n) qfor(j, 0, n)

#define forin(x, v) for (auto &x: v)

void solve() {
    string s;
    cin >> s;

    vector<int> cnt(300);
    forin (c, s) {
        ++cnt[c];
    }

    vector<int> ans;

    while (cnt[int('Z')] > 0) {
        --cnt[int('Z')];
        --cnt[int('E')];
        --cnt[int('R')];
        --cnt[int('O')];
        ans.push_back(0);
    }

    while (cnt[int('X')] > 0) {
        --cnt[int('S')];
        --cnt[int('I')];
        --cnt[int('X')];
        ans.push_back(6);
    }

    while (cnt[int('G')] > 0) {
        --cnt[int('E')];
        --cnt[int('I')];
        --cnt[int('G')];
        --cnt[int('H')];
        --cnt[int('T')];
        ans.push_back(8);
    }

    while (cnt[int('U')] > 0) {
        --cnt[int('F')];
        --cnt[int('O')];
        --cnt[int('U')];
        --cnt[int('R')];
        ans.push_back(4);
    }

    while (cnt[int('F')] > 0) {
        --cnt[int('F')];
        --cnt[int('I')];
        --cnt[int('V')];
        --cnt[int('E')];
        ans.push_back(5);
    }

    while (cnt[int('H')] > 0) {
        --cnt[int('T')];
        --cnt[int('H')];
        --cnt[int('R')];
        --cnt[int('E')];
        --cnt[int('E')];
        ans.push_back(3);
    }

    while (cnt[int('W')] > 0) {
        --cnt[int('T')];
        --cnt[int('W')];
        --cnt[int('O')];
        ans.push_back(2);
    }

    while (cnt[int('O')] > 0) {
        --cnt[int('O')];
        --cnt[int('N')];
        --cnt[int('E')];
        ans.push_back(1);
    }

    while (cnt[int('S')] > 0) {
        --cnt[int('S')];
        --cnt[int('E')];
        --cnt[int('V')];
        --cnt[int('E')];
        --cnt[int('N')];
        ans.push_back(7);
    }

    while (cnt[int('N')] > 0) {
        --cnt[int('N')];
        --cnt[int('I')];
        --cnt[int('N')];
        --cnt[int('E')];
        ans.push_back(9);
    }

    sort(ans.begin(), ans.end());
    forin (x, ans) {
        cout << x;
    }
    cout << endl;
}

INT main() {
    #ifdef _GLIBCXX_DEBUG
    assert(freopen("test.in", "r", stdin));
    assert(freopen("result.out", "w", stdout));
    #else
    // assert(freopen("unequal.in", "r", stdin));
    // assert(freopen("result.out", "w", stdout));
    cin.tie(0);
    #endif
    ios_base::sync_with_stdio(0);
    /// =======================================

    int n;
    cin >> n;
    fori (n) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
