#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int solve() {
    int u;
    cin >> u;
    string s;
    cin >> s;
    int sum = 0;
    int res = 0;
    for (int i = 0; i <= u; i++) {
        int c = s[i]-'0';
        if (!c) continue;
        res = max(res, i-sum);
        sum += c;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: %d\n", t, solve());
    }
}
