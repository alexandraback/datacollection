#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void precalc() {

}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int need = 0;
    int have = 0;
    for (int i = 0; i < s.size(); ++i) {
        int t = s[i] - '0';
        if (t > 0) {
            if (i > have) {
                need += i - have;
                have = i;
            }
            have += t;
        }
    }

    cout << need << endl;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    precalc();

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
