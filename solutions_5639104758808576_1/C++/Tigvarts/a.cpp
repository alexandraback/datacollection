#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    int cur = 0;
    for (int i = 0; i <= n; ++i) {
        if (cur < i) {
            res += i - cur;
            cur = i;
        }
        cur += s[i] - '0';
    }
    cout << res;
}

int main() {
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
        printf("\n");
    }
}
