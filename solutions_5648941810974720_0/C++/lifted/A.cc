#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <cstdlib>

using namespace std;

const vector<string> kDigits = {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE",
};

const vector< vector<pair<char, int> > > kMarkers = {
    {
        {'Z', 0},
        {'W', 2},
        {'U', 4},
        {'X', 6},
        {'G', 8},
    },
    {
        {'O', 1},
        {'T', 3},
        {'F', 5},
        {'S', 7},
    },
    {
        {'N', 9},
    },
};

string PhoneNum(const string& s) {
    vector<int> letter_counts(26);
    vector<int> digit_counts(10);

    for (char c : s) {
        letter_counts[c - 'A']++;
    }

    for (const auto& ms : kMarkers) {
        for (const auto& p : ms) {
            while (letter_counts[p.first - 'A'] > 0) {
                for (char c : kDigits[p.second]) {
                    assert(letter_counts[c - 'A'] > 0);
                    letter_counts[c - 'A']--;
                }
                digit_counts[p.second]++;
            }
        }
    }

    string out;
    for (int d = 0; d < 10; d++) {
        for (int i = 0; i < digit_counts[d]; i++) {
            out.push_back(d + '0');
        }
    }
    return out;
}

int main() {
    int num_tests;
    cin >> num_tests;
    string s;
    for (int test = 1; test <= num_tests; test++) {
        cin >> s;
        cout << "Case #" << test << ": " << PhoneNum(s) << "\n";
    }
    return 0;
}
