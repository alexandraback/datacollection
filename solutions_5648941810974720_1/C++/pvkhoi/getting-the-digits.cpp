#include <bits/stdc++.h>

using namespace std;

#define sz(a) int(a.size())

void solve(string s) {
    int n = sz(s);
    vector <int> cnt(26, 0), res(10, 0);
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'A']++;
    res[0] = cnt['Z' - 'A'];
    res[2] = cnt['W' - 'A'];
    res[3] = cnt['H' - 'A'] - cnt['G' - 'A'];
    res[4] = cnt['R' - 'A'] - cnt['Z' - 'A'] - cnt['H' - 'A'] + cnt['G' - 'A'];
    res[5] = cnt['V' - 'A'] - cnt['S' - 'A'] + cnt['X' - 'A'];
    res[6] = cnt['X' - 'A'];
    res[7] = cnt['S' - 'A'] - cnt['X' - 'A'];
    res[8] = cnt['G' - 'A'];
    res[1] = cnt['O' - 'A'] - res[0] - res[2] - res[4];
    res[9] = (cnt['N' - 'A'] - res[1] - res[7]) / 2;
    for (int i = 0; i <= 9; i++)
    for (int j = 0; j < res[i]; j++) cout << i;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        string s; cin >> s;
        cout << "Case #" << i << ": ";
        solve(s);
        cout << endl;
    }
    
    return 0;
}
