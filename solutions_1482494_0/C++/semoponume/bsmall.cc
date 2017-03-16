#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <map>
#include <string>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define AUTO(it, expr) __typeof__(expr) it = (expr)
#define FOR(it, c) for (AUTO(it, (c).begin()); (it) != (c).end(); ++(it))

int a[11], b[11];

map<pair<string, int>, int> memo;

bool finished(const string& s) {
    FOR (it, s)
        if (*it != 2)
            return false;
    return true;
}

const int INF = 1<<28;

int recur(string& s, int n) {
    if (finished(s)) return 0;
    if (memo.count(make_pair(s, n))) return memo[make_pair(s, n)];
    int opt = INF;
    REP (i, s.size()) {
        if (n >= a[i] && s[i] == 0) {
            s[i] = 1;
            opt = min(opt, 1 + recur(s, n + 1));
            s[i] = 0;
        }
        if (n >= b[i] && s[i] < 2) {
            char old = s[i];
            s[i] = 2;
            opt = min(opt, 1 + recur(s, n + 2 - old));
            s[i] = old;
        }
    }
    memo[make_pair(s, n)] = opt;
    return opt;
}

int main() {
    int t;
    cin >> t;
    REP (i, t) {
        int n;
        cin >> n;
        REP (j, n) {
            cin >> a[j] >> b[j];
        }
        memo.clear();
        string s(n, (char) 0);
        int ans = recur(s, 0);
        printf ("Case #%d: ", i+1);
        if (ans >= INF) puts ("Too Bad");
        else printf("%d\n", ans);
    }
}
