#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int numTests; cin >> numTests;
    for (int test = 0; test < numTests; ++test) {
        int smax; cin >> smax;
        string s; cin >> s;
        int total = 0;
        int result = 0;
        for (int i = 0; i <= smax; ++i) {
            while (total < i) {
                ++result;
                ++total;
            }
            total += s[i] - '0';
        }
        cout << "Case #" << test + 1 << ": " << result << '\n';
    }
    return 0;
}
