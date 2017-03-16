#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int t;
    cin >> t;
    std::string s;
    int n[26], d[10];
    for (int ti = 1; ti <= t; ++ti) {
        cout << "Case #" << ti << ": ";
        cin >> s;
        memset(n, 0, sizeof(n));
        memset(d, 0, sizeof(d));
        for (int i = 0; i < s.size(); ++i)
            n[s[i] - 'A']++;

        d[0] = n['Z' - 'A'];
        n['E' - 'A'] -= n['Z' - 'A'];
        n['R' - 'A'] -= n['Z' - 'A'];
        n['O' - 'A'] -= n['Z' - 'A'];
        n['Z' - 'A'] -= n['Z' - 'A'];

        d[2] = n['W' - 'A'];
        n['T' - 'A'] -= n['W' - 'A'];
        n['O' - 'A'] -= n['W' - 'A'];
        n['W' - 'A'] -= n['W' - 'A'];

        d[4] = n['U' - 'A'];
        n['F' - 'A'] -= n['U' - 'A'];
        n['O' - 'A'] -= n['U' - 'A'];
        n['R' - 'A'] -= n['U' - 'A'];
        n['U' - 'A'] -= n['U' - 'A'];

        d[1] = n['O' - 'A'];
        n['N' - 'A'] -= n['O' - 'A'];
        n['E' - 'A'] -= n['O' - 'A'];
        n['O' - 'A'] -= n['O' - 'A'];

        d[5] = n['F' - 'A'];
        n['I' - 'A'] -= n['F' - 'A'];
        n['V' - 'A'] -= n['F' - 'A'];
        n['E' - 'A'] -= n['F' - 'A'];
        n['F' - 'A'] -= n['F' - 'A'];

        d[6] = n['X' - 'A'];
        n['S' - 'A'] -= n['X' - 'A'];
        n['I' - 'A'] -= n['X' - 'A'];
        n['X' - 'A'] -= n['X' - 'A'];

        d[7] = n['V' - 'A'];
        n['S' - 'A'] -= n['V' - 'A'];
        n['E' - 'A'] -= n['V' - 'A'];
        n['E' - 'A'] -= n['V' - 'A'];
        n['N' - 'A'] -= n['V' - 'A'];
        n['V' - 'A'] -= n['V' - 'A'];

        d[8] = n['G' - 'A'];
        n['E' - 'A'] -= n['G' - 'A'];
        n['I' - 'A'] -= n['G' - 'A'];
        n['H' - 'A'] -= n['G' - 'A'];
        n['T' - 'A'] -= n['G' - 'A'];
        n['G' - 'A'] -= n['G' - 'A'];

        d[3] = n['T' - 'A'];
        n['H' - 'A'] -= n['T' - 'A'];
        n['R' - 'A'] -= n['T' - 'A'];
        n['E' - 'A'] -= n['T' - 'A'];
        n['E' - 'A'] -= n['T' - 'A'];
        n['T' - 'A'] -= n['T' - 'A'];

        d[9] = n['I' - 'A'];

        for (int i = 0; i <= 9; ++i)
            while (d[i]--)
                putchar('0' + i);
        putchar('\n');
    }
}
