#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

int sign(int number) {
    return number < 0 ? -1 : 1;
}

int q_mul(int left, int right) {
    static int mul_table[4][4] = {
        {1, 2, 3, 4},
        {2, -1, 4, -3},
        {3, -4, -1, 2},
        {4, 3, -2, -1},
    };

    int sgn = sign(left) * sign(right);
    return sgn * mul_table[abs(left) - 1][abs(right) - 1];
}

int q_pow(int base, LL p) {
    p %= 4;
    int result = 1;
    for (auto i = 0; i < p; ++i)
        result = q_mul(result, base);
    return result;
}

int char_to_q(char c) {
    switch (c) {
    case 'i': return 2;
    case 'j': return 3;
    case 'k': return 4;
    default: throw exception();
    }
}

string solve(const string& s, LL X) {
    int current = 1;
    for (char c : s)
        current = q_mul(current, char_to_q(c));
    if (q_pow(current, X) != -1)
        return "NO";

    current = 1;
    bool iFound = false;
    for (int round = 0; round < 10 && round < X; ++round)
        for (char c : s) {
            current = q_mul(current, char_to_q(c));
            if (!iFound && current == 2)
                iFound = true;
            if (iFound && current == 4)
                return "YES";
        }

    return "NO";
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        size_t L;
        LL X;
        cin >> L >> X;
        string s;
        cin >> s;
        if (s.size() != L)
            throw exception();

        cout << "Case #" << t << ": " << solve(s, X) << '\n';
    }

    return 0;
}

