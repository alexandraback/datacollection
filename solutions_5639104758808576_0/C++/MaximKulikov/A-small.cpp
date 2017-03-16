#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define PROBLEM "A-small-attempt0"

int solve(string& S) {
    int ret = 0, summ = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (summ < i) {
            ret = max(ret, i-summ);
        }
        summ += S[i] - '0';
    }
    return ret;
}

int main() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        string s;
        cin >> n >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }

    return 0;
}
