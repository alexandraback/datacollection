#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

vector<size_t> prefix_f(const string& word) {
    vector<size_t> p(word.size());
    for (size_t i = 1; i < word.size(); ++i) {
        size_t cmp_index = p[i - 1];
        while (cmp_index && word[i] != word[cmp_index])
            cmp_index = p[cmp_index - 1];
        if (word[i] == word[cmp_index])
            ++cmp_index;
        p[i] = cmp_index;
    }
    return p;
}

double solve() {
    int K, L, S;
    cin >> K >> L >> S;
    string letters, word;
    cin >> letters >> word;

    vector<int> let(256);
    for (char c : letters)
        ++let[(unsigned char)c];
    for (char c : word)
        if (!let[(unsigned char)c])
            return 0.0;

    vector<pair<char, double>> let_p;
    for (int i = 0; i < 256; ++i)
        if (let[i])
            let_p.push_back(make_pair((char)i, double(let[i]) / K));

    vector<size_t> pi = prefix_f(word);
    /*cout << word << endl;
    for (size_t i = 0; i < p.size(); ++i)
        cout << p[i] << ' ';
    cout << endl;*/

    int max_times = 1 + (S - L) / (L - pi[L - 1]);
    double avg_times = 0.0;

    word.push_back(0);
    vector<vector<double>> f(S + 1, vector<double>(L + 1));
    f[0][0] = 1.0;
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j <= L; ++j) {
            if (f[i][j] == 0.0)
                continue;
            for (auto p : let_p) {
                char c = p.first;
                int k = j;
                while (k && word[k] != c)
                    k = pi[k - 1];
                if (word[k] == c)
                    ++k;
                f[i + 1][k] += f[i][j] * p.second;
            }
        }
    }

    for (int i = 0; i <= S; ++i)
        avg_times += f[i][L];

    return max_times - avg_times;
}

int main() {
    int tests;
    cin >> tests;
    cout << fixed << setprecision(10);
    for (int t = 1; t <= tests; ++t) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}

