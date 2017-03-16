#include <iostream>
#include <string>
#include <vector>
using namespace std;

size_t solve(const string& s) {
    vector<size_t> cnt(s.size());
    for (size_t i = 0, size = s.size(); i != size; ++i)
        cnt[i] = s[i] - '0';

    size_t result = 0;
    size_t clapping = cnt[0];
    for (size_t i = 1, size = cnt.size(); i != size; ++i) {
        if (clapping < i) {
            result += i - clapping;
            clapping = i;
        }
        clapping += cnt[i];
    }

    return result;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        size_t s_max;
        cin >> s_max;
        string s;
        cin >> s;
        if (s.size() != s_max + 1)
            throw exception();

        cout << "Case #" << t << ": " << solve(s) << '\n';
    }

    return 0;
}

