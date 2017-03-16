#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;



int solve(vector<pair<string, string>>& input) {
    int hi_count = 0;

    long hi = (1 << input.size());
    for (long i = 1; i <= hi; ++i) {
        int count = 0;
        unordered_set<string> a, b;
        vector<bool> originals(input.size(), false);
        for (size_t j = 0; j < input.size(); ++j) {
            if (i & (1 << j)) {
                a.emplace(input[j].first);
                b.emplace(input[j].second);
                originals[j] = true;
            }
        }

        for (size_t j = 0; j < input.size(); ++j) {
            if (!originals[j] && 
                a.find(input[j].first) != a.end() && 
                b.find(input[j].second) != b.end()) {
                ++count;
            }
        }
        hi_count = max(hi_count, count);
    }
    return hi_count;
}

int main() {
    int T;
    string a, b;
    int N;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        vector<pair<string, string>> words;
        while (N--) {
            cin >> a >> b;
            words.emplace_back(a, b);
        }
        cout << "Case #" << i << ": " << solve(words) << endl;
    }
    return 0;
}
