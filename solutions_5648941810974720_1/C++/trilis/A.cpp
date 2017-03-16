#include <iostream>

using namespace std;

int cnt[26];
int ans[26];
int t;
string s;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int r = 0; r < t; r++) {
        cin >> s;
        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
            ans[i] = 0;
        }
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'A']++;
        }
        cnt['E' - 'A'] -= cnt['Z' - 'A'];
        cnt['R' - 'A'] -= cnt['Z' - 'A'];
        cnt['O' - 'A'] -= cnt['Z' - 'A'];
        ans[0] += cnt['Z' - 'A'];
        cnt['Z' - 'A'] -= cnt['Z' - 'A'];

        cnt['T' - 'A'] -= cnt['W' - 'A'];
        cnt['O' - 'A'] -= cnt['W' - 'A'];
        ans[2] += cnt['W' - 'A'];
        cnt['W' - 'A'] -= cnt['W' - 'A'];

        cnt['F' - 'A'] -= cnt['U' - 'A'];
        cnt['O' - 'A'] -= cnt['U' - 'A'];
        cnt['R' - 'A'] -= cnt['U' - 'A'];
        ans[4] += cnt['U' - 'A'];
        cnt['U' - 'A'] -= cnt['U' - 'A'];

        cnt['S' - 'A'] -= cnt['X' - 'A'];
        cnt['I' - 'A'] -= cnt['X' - 'A'];
        ans[6] += cnt['X' - 'A'];
        cnt['X' - 'A'] -= cnt['X' - 'A'];

        cnt['E' - 'A'] -= cnt['G' - 'A'];
        cnt['I' - 'A'] -= cnt['G' - 'A'];
        cnt['T' - 'A'] -= cnt['G' - 'A'];
        cnt['H' - 'A'] -= cnt['G' - 'A'];
        ans[8] += cnt['G' - 'A'];
        cnt['G' - 'A'] -= cnt['G' - 'A'];

        cnt['N' - 'A'] -= cnt['O' - 'A'];
        cnt['E' - 'A'] -= cnt['O' - 'A'];
        ans[1] += cnt['O' - 'A'];
        cnt['O' - 'A'] -= cnt['O' - 'A'];

        cnt['T' - 'A'] -= cnt['H' - 'A'];
        cnt['R' - 'A'] -= cnt['H' - 'A'];
        cnt['E' - 'A'] -= cnt['H' - 'A'];
        cnt['E' - 'A'] -= cnt['H' - 'A'];
        ans[3] += cnt['H' - 'A'];
        cnt['H' - 'A'] -= cnt['H' - 'A'];

        cnt['I' - 'A'] -= cnt['F' - 'A'];
        cnt['V' - 'A'] -= cnt['F' - 'A'];
        cnt['E' - 'A'] -= cnt['F' - 'A'];
        ans[5] += cnt['F' - 'A'];
        cnt['F' - 'A'] -= cnt['F' - 'A'];

        cnt['S' - 'A'] -= cnt['V' - 'A'];
        cnt['E' - 'A'] -= cnt['V' - 'A'];
        cnt['E' - 'A'] -= cnt['V' - 'A'];
        cnt['N' - 'A'] -= cnt['V' - 'A'];
        ans[7] += cnt['V' - 'A'];
        cnt['V' - 'A'] -= cnt['V' - 'A'];

        for (int i = 0; i < 26; i++) {
            ans[9] += cnt[i];
        }
        ans[9] /= 4;
        cout << "Case #" << r + 1 << ": ";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < ans[i]; j++) {
                cout << i;
            }
        }
        cout << "\n";
    }
}
