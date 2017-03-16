#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int t;
string str;
int digit_count[10];
int char_count[256];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 10; ++j) {
            digit_count[j] = 0;
        }
        for (int j = 0; j < 256; ++j)
            char_count[j] = 0;
        cin >> str;
        for (int j = 0; j < str.size(); ++j)
            ++char_count[str[j]];
        digit_count[0] = char_count['Z'];
        digit_count[2] = char_count['W'];
        digit_count[4] = char_count['U'];
        digit_count[3] = char_count['R'] - digit_count[0] - digit_count[4];
        digit_count[1] = char_count['O'] - digit_count[0] - digit_count[2] - digit_count[4];
        digit_count[8] = char_count['H'] - digit_count[3];
        digit_count[6] = char_count['X'];
        digit_count[7] = char_count['S'] - digit_count[6];
        digit_count[5] = char_count['V'] - digit_count[7];
        digit_count[9] = (char_count['N'] - digit_count[1] - digit_count[7]) / 2;
        cout << "CASE #" << i + 1 << ": ";
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < digit_count[j]; ++k)
                cout << char('0' + j);
        cout << endl;
    }
}
