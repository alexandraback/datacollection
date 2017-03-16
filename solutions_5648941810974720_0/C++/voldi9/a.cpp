#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string t[10] = {
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

void remove_letters(string& s, vector<unsigned>& vec, unsigned x) {
    for (const char c : s) {
        vec[c - 'A'] -= x;
    }
    return;
}

int main() {
    int T;
    string s;
    unsigned digits[10];
    vector<unsigned> letters;
    letters.resize(26);
    cin >> T;
    for (int i=1; i<=T; i++) {
        fill(letters.begin(), letters.end(), 0);
        fill(digits, digits + 10, 0);
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            letters[(int) s[j] - 'A']++;
        }
        // zero
        unsigned letter = letters['Z' - 'A'];
        digits[0] = letter;
        remove_letters(t[0], letters, letter);

        // six
        letter = letters['X' - 'A'];
        digits[6] = letter;
        remove_letters(t[6], letters, letter);

        // eight
        letter = letters['G' - 'A'];
        digits[8] = letter;
        remove_letters(t[8], letters, letter);

        // seven
        letter = letters['S' - 'A'];
        digits[7] = letter;
        remove_letters(t[7], letters, letter);

        // five
        letter = letters['V' - 'A'];
        digits[5] = letter;
        remove_letters(t[5], letters, letter);

        // four
        letter = letters['F' - 'A'];
        digits[4] = letter;
        remove_letters(t[4], letters, letter);

        // three
        letter = letters['R' - 'A'];
        digits[3] = letter;
        remove_letters(t[3], letters, letter);

        // three
        letter = letters['W' - 'A'];
        digits[2] = letter;
        remove_letters(t[2], letters, letter);

        // one
        letter = letters['O' - 'A'];
        digits[1] = letter;
        remove_letters(t[1], letters, letter);

        // three
        letter = letters['I' - 'A'];
        digits[9] = letter;
        remove_letters(t[9], letters, letter);

        cout << "Case #" << i << ": ";
        for (int j=0; j<10; j++) {
            while (digits[j]) {
                cout << j;
                digits[j]--;
            }
        }
        cout << endl;
    }
}