#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int testnum) {
    int A, n;
    cin >> A >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s.begin(), s.end());
    int ans = n;
    for (int i = 0; i <= n; ++i) {
        int cur = n - i;
        int q = A;
        for (int j = 0; j < i; ++j) {
            while (q <= s[j]) {
                ++cur;
                q = q * 2 - 1;
                if (cur > ans) break;
            }
            q += s[j];
        }
        if (ans > cur) ans = cur;
    }
    cout << "Case #" << testnum << ": " << ans << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) solve(i);
    return 0;
}

