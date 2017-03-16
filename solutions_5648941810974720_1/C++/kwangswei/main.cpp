#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<char> keyword = {'Z', 'O', 'W', 'R', 'U', 'F', 'X', 'V', 'G', 'I'};
vector<int> orders = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
vector<string> alphabet = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

string solve(string str) {
    vector<int> count(10, 0);
    map<char, int> letters;

    for (auto c: str) {
        letters[c] += 1;
    }

    for (auto o: orders) {
        if (letters[keyword[o]] == 0)
            continue;

        auto cnt = letters[keyword[o]];

        count[o] += cnt;

        for (auto c: alphabet[o])
            letters[c] -= cnt;
    }

    string result;
    for (int i = 0; i < 10; ++i) {
        result += string(count[i], '0' + i);
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    for (int t = 1; t <= N; ++t) {
        string str;
        cin >> str;

        printf("Case #%d: %s\n", t, solve(str).data());
    }

    return 0;
}
