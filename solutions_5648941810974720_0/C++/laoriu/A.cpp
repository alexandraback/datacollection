#include <bits/stdc++.h>

using namespace std;

string solve() {
    string s;
    cin >> s;
    vector<int> cntLetter(26, 0), cntDit(10, 0);
    for(int i = 0; i < s.length(); i++) cntLetter[s[i] - 'A']++;

    cntDit[0] += cntLetter['Z' - 'A'];
    cntLetter['E' - 'A'] -= cntLetter['Z' - 'A']; cntLetter['R' - 'A'] -= cntLetter['Z' - 'A']; cntLetter['O' - 'A'] -= cntLetter['Z' - 'A'];
    cntLetter['Z' - 'A'] = 0;

    cntDit[2] += cntLetter['W' - 'A'];
    cntLetter['T' - 'A'] -= cntLetter['W' - 'A']; cntLetter['O' - 'A'] -= cntLetter['W' - 'A'];
    cntLetter['W' - 'A'] = 0;

    cntDit[4] += cntLetter['U' - 'A'];
    cntLetter['F' - 'A'] -= cntLetter['U' - 'A']; cntLetter['O' - 'A'] -= cntLetter['U' - 'A']; cntLetter['R' - 'A'] -= cntLetter['U' - 'A'];
    cntLetter['U' - 'A'] = 0;

    cntDit[6] += cntLetter['X' - 'A'];
    cntLetter['S' - 'A'] -= cntLetter['X' - 'A']; cntLetter['I' - 'A'] -= cntLetter['X' - 'A'];
    cntLetter['X' - 'A'] = 0;

    cntDit[8] += cntLetter['G' - 'A'];
    cntLetter['E' - 'A'] -= cntLetter['G' - 'A']; cntLetter['I' - 'A'] -= cntLetter['G' - 'A'];
    cntLetter['H' - 'A'] -= cntLetter['G' - 'A']; cntLetter['T' - 'A'] -= cntLetter['G' - 'A'];
    cntLetter['G' - 'A'] = 0;

    cntDit[1] += cntLetter['O' - 'A'];
    cntLetter['N' - 'A'] -= cntLetter['O' - 'A']; cntLetter['E' - 'A'] -= cntLetter['O' - 'A'];
    cntLetter['O' - 'A'] = 0;

    cntDit[3] += cntLetter['R' - 'A'];
    cntLetter['T' - 'A'] -= cntLetter['R' - 'A']; cntLetter['H' - 'A'] -= cntLetter['R' - 'A'];
    cntLetter['E' - 'A'] -= cntLetter['R' - 'A']; cntLetter['E' - 'A'] -= cntLetter['R' - 'A'];
    cntLetter['R' - 'A'] = 0;

    cntDit[5] += cntLetter['F' - 'A'];
    cntLetter['I' - 'A'] -= cntLetter['F' - 'A']; cntLetter['V' - 'A'] -= cntLetter['F' - 'A']; cntLetter['E' - 'A'] -= cntLetter['F' - 'A'];
    cntLetter['F' - 'A'] = 0;

    cntDit[7] = cntLetter['V' - 'A'];
    cntDit[9] = cntLetter['I' - 'A'];

    string res = "";
    for(int i = 0; i <= 9; i++)
        for(int j = 0; j < cntDit[i]; j++) res.push_back(char(i + 48));

    return res;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int ntests;
    cin >> ntests;
    for(int tc = 1; tc <= ntests; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}
