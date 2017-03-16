#include <bits/stdc++.h>

using namespace std;

map<char,int> cnt;
string result;

void decrease(char symbol, string s, char add) {
    while (cnt[symbol] > 0) {
        result += add;
        for (int j = 0; j < (int)s.size(); ++j) {
            --cnt[s[j]];
        }
    }
}

void Solve() {
    string s;
    cin >> s;
    cnt.clear();
    for (int i = 0; i < (int)s.size(); ++i) {
        ++cnt[s[i]];
    }
    result = "";

    // ZERO
    decrease('Z', "ZERO", '0');
    decrease('X', "SIX", '6');
    decrease('W', "TWO", '2');
    decrease('G', "EIGHT", '8');
    decrease('H', "THREE", '3');
    decrease('R', "FOUR", '4');
    decrease('F', "FIVE", '5');
    decrease('V', "SEVEN", '7');
    decrease('O', "ONE", '1');
    decrease('N', "NINE", '9');
    sort(result.begin(), result.end());
    cout << result << '\n';
}

int main() {
    int z;
    cin >> z;
    for (int i = 1; i <= z; ++i) {
        cout << "Case #" << i << ": ";
        Solve();
    }
    return 0;
}
