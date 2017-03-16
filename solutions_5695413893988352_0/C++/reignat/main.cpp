#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

typedef long long int ll;
const int MAXN = 100003;

using namespace std;

bool check(int num, string &pat) {
    for (int i = (int)pat.size() - 1; i >= 0; --i) {
        if (pat[i] == '?'){
            num /= 10;
            continue;
        }
        if ((int)(pat[i] - '0') != (num % 10)) return false;
        num /= 10;
    }
    return true;
}

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s1, s2;
        cin >> s1 >> s2;
        int lims = (int)s1.size() == 3 ? 1000 : (int)s1.size() == 2 ? 100 : 10;
        int mindif = 10000;
        for (int k1 = 0; k1 < lims; ++k1)
            for (int k2 = 0; k2 < lims; ++k2)
                if (check(k1, s1) && check(k2, s2))
                    mindif = min(mindif, abs(k1 - k2));
        int ans1, ans2;
        for (int k1 = 0; k1 < lims; ++k1) {
            bool found = false;
            for (int k2 = 0; k2 < lims; ++k2) {
                if (check(k1, s1) && check(k2, s2) && abs(k1 - k2) == mindif) {
                    found = true;
                    ans1 = k1;
                    ans2 = k2;
                    break;
                }
            }
            if (found) break;
        }
        string res1, res2;
        res1 = to_string(ans1);
        res2 = to_string(ans2);
        while (res1.size() < s1.size()) {
            res1 = "0" + res1;
        }
        while (res2.size() < s2.size()) {
            res2 = "0" + res2;
        }
        cout << "Case #" << t << ": " << res1 << " " << res2 << '\n';
    }
    return 0;
}