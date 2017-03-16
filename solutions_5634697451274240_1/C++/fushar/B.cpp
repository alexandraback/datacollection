#include <bits/stdc++.h>
using namespace std;

int T;
string S;

char flip[256];
map<tuple<string, char, bool>, int> dp;

int DP(string s, char goal, bool flipped) {
    if (all_of(s.begin(), s.end(), [goal](char c) {return c == goal;})) {
        return 0;
    }
    if (dp.count(make_tuple(s, goal, flipped))) {
        return dp[make_tuple(s, goal, flipped)];
    }

    int res = 999999999;
    if (!flipped) {
        string t = s;
        reverse(t.begin(), t.end());
        res = DP(t, goal, true) + 1;
    }

    if (s.back() == goal) {
        res = min(res, DP(s.substr(0, s.size()-1), goal, false));
    } else {
        res = min(res, DP(s.substr(0, s.size()-1), flip[goal], false) + 1);
    }

    return dp[make_tuple(s, goal, flipped)] = res;
}

int main() {
    flip['+'] = '-';
    flip['-'] = '+';

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> S;
        dp.clear();
        cout << "Case #" << tc << ": " << DP(S, '+', 0) << endl;
    }
}
