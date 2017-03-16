#include <bits/stdc++.h>
using namespace std;

string s;

int solve() {
    cin >> s;
    int n = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] != s[i + 1]) {
            ++n;
        }
    }
    if (s[s.size() - 1] == '+') {
        return n;
    } else {
        return n + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++) {
        cout << "Case #" << i << ": " << solve() << '\n';
    }
    return 0;
}
