#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int CountFakes(const vector<string>& first,
               const vector<string>& second,
               unsigned mask) {
    unordered_set<string> seen_first, seen_second;

    size_t n = first.size();
    for (size_t i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            seen_first.emplace(first[i]);
            seen_second.emplace(second[i]);
        }
    }

    int fakes = 0;
    for (size_t i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            if (seen_first.count(first[i]) && seen_second.count(second[i])) {
                fakes++;
            }
        }
    }
    return fakes;
}


int MaxFakes(const vector<string>& first,
             const vector<string>& second) {
    unsigned max_mask = 1 << first.size();
    int fakes = 0;
    for (unsigned mask = 0; mask < max_mask; mask++) {
        fakes = max(fakes, CountFakes(first, second, mask));
    }
    return fakes;
}

int main() {
    int num_tests;
    cin >> num_tests;
    string t1, t2;
    for (int test = 1; test <= num_tests; test++) {
        int n_topics;
        cin >> n_topics;
        vector<string> topics1(n_topics), topics2(n_topics);
        for (int t = 0; t < n_topics; t++) {
            cin >> topics1[t] >> topics2[t];
        }
        cout << "Case #" << test << ": " << MaxFakes(topics1, topics2) << "\n";
    }
    return 0;
}
