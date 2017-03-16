#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

bool is_possible(vector<tuple<string, string>>& actual, vector<tuple<string, string>>& fake) {
    set<tuple<string, string>> s;
    for (auto x: fake)
        s.insert(x);

    if (s.size() != fake.size())
        return false;

    set<string> first, second;

    for (auto x: actual) {
        first.insert(get<0>(x));
        second.insert(get<1>(x));
    }

    for (auto x: fake) {
        if (first.find(get<0>(x)) == first.end())
            return false;
        if (second.find(get<1>(x)) == second.end())
            return false;
    }

    return true;
}

int solve(vector<tuple<string, string>> words) {
    int max_fake = 0;

    for (unsigned int i = 0; i < pow(2, words.size()); ++i) {
        vector<tuple<string, string>> actual, fake;
        for (int j = 0; j < words.size(); ++j) {
            if (i & (1 << j))
                actual.push_back(words[j]);
            else
                fake.push_back(words[j]);
        }

        if (is_possible(actual, fake)) {
            max_fake = max(max_fake, (int)fake.size());
        }
    }

    return max_fake;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        vector<tuple<string, string>> words(N);
        for (int i = 0; i < N; ++i) {
            cin >> get<0>(words[i]) >> get<1>(words[i]);
        }

        printf("Case #%d: %d\n", t, solve(words));
    }

    return 0;
}
