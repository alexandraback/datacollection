#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std; 

int64 to_int(const string& s) {
    int64 result = 0;
    int n = sz(s);
    for (int i = 0; i < n; ++i) {
        result = int64(s[i] - '0') + result * 10;
    }
    return result;
}

using TAnswer = pair<int64, pair<int64, int64>>;

TAnswer ans;
string ans1;
string ans2;

void solve(int prefixLen, string s1, string s2, bool swapped) {
    int n = sz(s1);
    for (int i = 0; i < prefixLen; ++i) {
        if (s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) {
            return;
        }
        if (s1[i] != '?') {
            s2[i] = s1[i];
        } else if (s2[i] != '?') {
            s1[i] = s2[i];
        } else {
            s1[i] = '0';
            s2[i] = '0';
        }
    }
    if (prefixLen != n) {
        if (s1[prefixLen] != '?') {
            if (s2[prefixLen] != '?') {
                if (s1[prefixLen] <= s2[prefixLen]) return;
            } else {
                if (s1[prefixLen] == '0') return;
                s2[prefixLen] = s1[prefixLen] - 1;
            }
        } else {
            if (s2[prefixLen] != '?') {
                if (s2[prefixLen] == '9') return;
                s1[prefixLen] = s2[prefixLen] + 1;
            } else {
                s1[prefixLen] = '1';
                s2[prefixLen] = '0';
            }
        }
    }
    for (int i = prefixLen + 1; i < n; ++i) {
        if (s1[i] == '?') s1[i] = '0';
        if (s2[i] == '?') s2[i] = '9';
    }
    int64 A = to_int(s1);
    int64 B = to_int(s2);
    TAnswer res = mp(A - B, mp(A, B));
    if (swapped) res = mp(A - B, mp(B, A));
    if (ans > res) {
        ans = res;
        ans1 = s1;
        ans2 = s2;
        if (swapped) {
            ans1 = s2;
            ans2 = s1;
        }
    }
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int64 n = sz(s1);

    int64 inf = 1000000000;
    inf *= inf;
    inf *= 2;
    ans = mp(inf, mp(inf, inf));
    for (int equalPrefix = 0; equalPrefix <= n; ++equalPrefix) {
        solve(equalPrefix, s1, s2, false);
        solve(equalPrefix, s2, s1, true);
    }
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
