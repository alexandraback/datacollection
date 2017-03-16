#include <bits/stdc++.h>

using namespace std;

string s;
int counts[15];

int countLetter(char letter) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == letter) {
            count ++;
        }
    }
    return count;
}

int removes[100];
void removeChars() {
    for (int i = 0; i < s.size(); i++) {
        if (removes[s[i]] > 0) {
            removes[s[i]]--;
            s[i] = ' ';
        } 
    }
}
string strings[] = {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"
};
int order[] = {0, 2, 6, 8, 3, 4, 5, 7, 9, 1};
char chars[] = {'Z', 'W', 'X', 'G', 'H', 'R', 'F', 'V', 'I', 'O'};

int main() {
    int test;
    cin >> test;
    for (int t = 0; t < test; t++) {
        cin >> s;
        memset(counts, 0, sizeof(counts));
        memset(removes, 0, sizeof(removes));
        for (int j = 0; j < 10; j++) {
            counts[order[j]] = countLetter(chars[j]);
            for (int i = 0; i < strings[order[j]].size(); i++) {
                removes[strings[order[j]][i]] += counts[order[j]];
            }
            removeChars();
            for (int i = 0; i < 30; i++) {
                assert(removes[i] == 0);
            }
            // cout << s << endl;

        }
        cout << "Case #" << (t + 1) << ": ";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < counts[i]; j++) {
                cout << i;
            }
        }
        cout << endl;
    }
}