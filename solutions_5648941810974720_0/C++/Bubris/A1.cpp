#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int letters[26];
int digits[10];

int main () {
    int t;
    cin >> t;
    string s;
    for (int k = 1; k <= t; k++) {
        cin >> s;

        for (int i = 0; i < 26; i++) {
            letters[i] = 0;
        }

        for (int i = 0; i < 10; i++) {
            digits[i] = 0;
        }

        for (int i = 0; i < s.length(); i++) {
            letters[s[i] - 'A']++;
        }

        while (letters['Z' - 'A']) {
            letters['Z'-'A']--;
            letters['E'-'A']--;
            letters['R'-'A']--;
            letters['O'-'A']--;
            digits[0]++;
        }

        while (letters['W' - 'A']) {
            letters['T'-'A']--;
            letters['W'-'A']--;
            letters['O'-'A']--;
            digits[2]++;
        }

        while (letters['G' - 'A']) {
            letters['E'-'A']--;
            letters['I'-'A']--;
            letters['G'-'A']--;
            letters['H'-'A']--;
            letters['T'-'A']--;
            digits[8]++;
        }

        while (letters['H' - 'A']) {
            letters['T'-'A']--;
            letters['H'-'A']--;
            letters['R'-'A']--;
            letters['E'-'A']--;
            letters['E'-'A']--;
            digits[3]++;
        }

        while (letters['U' - 'A']) {
            letters['F'-'A']--;
            letters['O'-'A']--;
            letters['U'-'A']--;
            letters['R'-'A']--;
            digits[4]++;
        }

        while (letters['X' - 'A']) {
            letters['S'-'A']--;
            letters['I'-'A']--;
            letters['X'-'A']--;
            digits[6]++;
        }

        while (letters['F' - 'A']) {
            letters['F'-'A']--;
            letters['I'-'A']--;
            letters['V'-'A']--;
            letters['E'-'A']--;
            digits[5]++;
        }

        while (letters['V' - 'A']) {
            letters['S'-'A']--;
            letters['E'-'A']--;
            letters['V'-'A']--;
            letters['E'-'A']--;
            letters['N'-'A']--;
            digits[7]++;
        }

        while (letters['O' - 'A']) {
            letters['O'-'A']--;
            letters['E'-'A']--;
            letters['N'-'A']--;
            digits[1]++;
        }

        while (letters['I' - 'A']) {
            letters['N'-'A']--;
            letters['I'-'A']--;
            letters['N'-'A']--;
            letters['E'-'A']--;
            digits[9]++;
        }

        cout << "Case #" << k << ": ";
        for (int i = 0; i < 10; i++) {
            while (digits[i]) {
                cout << i;
                digits[i]--;
            }
        }
        cout << endl;
    }

    return 0;
}
