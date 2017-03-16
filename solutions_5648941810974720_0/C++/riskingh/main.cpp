#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int cnt[300];
int dgt[10];

void solve() {
    memset(cnt, 0, 300 * sizeof(int));
    memset(dgt, 0, 10 * sizeof(int));

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
        cnt[s[i]]++;

    int n;

    // (Z)ERO
    n = 0;
    dgt[n] = cnt['Z'];
    cnt['Z'] -= dgt[n];
    cnt['E'] -= dgt[n];
    cnt['R'] -= dgt[n];
    cnt['O'] -= dgt[n];

    // T(W)O
    n = 2;
    dgt[n] = cnt['W'];
    cnt['T'] -= dgt[n];
    cnt['W'] -= dgt[n];
    cnt['O'] -= dgt[n];

    // SI(X)
    n = 6;
    dgt[n] = cnt['X'];
    cnt['S'] -= dgt[n];
    cnt['I'] -= dgt[n];
    cnt['X'] -= dgt[n];

    // (S)EVEN
    n = 7;
    dgt[n] = cnt['S'];
    cnt['S'] -= dgt[n];
    cnt['E'] -= dgt[n];
    cnt['V'] -= dgt[n];
    cnt['E'] -= dgt[n];
    cnt['N'] -= dgt[n];

    // EI(G)HT
    n = 8;
    dgt[n] = cnt['G'];
    cnt['E'] -= dgt[n];
    cnt['I'] -= dgt[n];
    cnt['G'] -= dgt[n];
    cnt['H'] -= dgt[n];
    cnt['T'] -= dgt[n];

    // FI(V)E
    n = 5;
    dgt[n] = cnt['V'];
    cnt['F'] -= dgt[n];
    cnt['I'] -= dgt[n];
    cnt['V'] -= dgt[n];
    cnt['E'] -= dgt[n];

    // (T)HREE
    n = 3;
    dgt[n] = cnt['T'];
    cnt['T'] -= dgt[n];
    cnt['H'] -= dgt[n];
    cnt['R'] -= dgt[n];
    cnt['E'] -= dgt[n];
    cnt['E'] -= dgt[n];

    // FOU(R)
    n = 4;
    dgt[n] = cnt['R'];
    cnt['F'] -= dgt[n];
    cnt['O'] -= dgt[n];
    cnt['U'] -= dgt[n];
    cnt['R'] -= dgt[n];

    // (O)NE
    n = 1;
    dgt[n] = cnt['O'];
    cnt['O'] -= dgt[n];
    cnt['N'] -= dgt[n];
    cnt['E'] -= dgt[n];

    // N(I)NE
    n = 9;
    dgt[n] = cnt['I'];
    cnt['N'] -= dgt[n];
    cnt['I'] -= dgt[n];
    cnt['N'] -= dgt[n];
    cnt['E'] -= dgt[n];

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < dgt[i]; ++j)
            cout << i;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, T;
    for (cin >> T, t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
