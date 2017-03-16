#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    string s;
    cin >> s;
    vector<char> blocks;
    for (size_t i = 0; i < s.size(); i++) {
        if (i + 1 == s.size() || s[i] != s[i + 1]) {
            blocks.push_back(s[i]);
        }
    }
    cout << (int)blocks.size() - 1 + (blocks.back() == '+' ? 0 : 1) << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
}
