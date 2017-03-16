#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int MAX_CHAR = 255;

void del(vector<int> &sum, string s, int n) {
    for (char ch : s) {
        sum[ch] -= n;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        vector<int> n_symbols(MAX_CHAR, 0);
        vector<int> answer(10, 0);
        for (char ch : s) {
            ++n_symbols[ch];
        }
        answer[0] = n_symbols['Z'];
        del(n_symbols, "ZERO", answer[0]);
        answer[2] = n_symbols['W'];
        del(n_symbols, "TWO", answer[2]);
        answer[4] = n_symbols['U'];
        del(n_symbols, "FOUR", answer[4]);
        answer[6] = n_symbols['X'];
        del(n_symbols, "SIX", answer[6]);
        answer[8] = n_symbols['G'];
        del(n_symbols, "EIGHT", answer[8]);
        answer[1] = n_symbols['O'];
        del(n_symbols, "ONE", answer[1]);
        answer[3] = n_symbols['R'];
        del(n_symbols, "THREE", answer[3]);
        answer[5] = n_symbols['F'];
        del(n_symbols, "FIVE", answer[5]);
        answer[7] = n_symbols['S'];
        del(n_symbols, "SEVEN", answer[7]);
        answer[9] = n_symbols['I'];
        del(n_symbols, "NINE", answer[9]);
        bool is_correct = true;
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            if (n_symbols[ch] != 0) {
                cout << ch << " " << n_symbols[ch] << endl;
                is_correct = false;
            }
        }
        assert(is_correct == true);
        cout << "Case #" << t << ": ";
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j < answer[i]; ++j) {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}