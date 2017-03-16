#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <functional>
#include <cstdint>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

#define D(x) x

using namespace std;

int main() {
    int numCases;
    cin >> numCases;
    cout.precision(7);

    for (int testCase = 1; testCase <= numCases; testCase++) {
        int K, L, S;
        cin >> K >> L >> S;
        string keyboard, target;
        cin >> keyboard >> target;

        map<char, double> freq;
        for (int i = 0; i < K; i++) {
            freq[keyboard[i]]++;
        }
        for (auto& pair : freq) {
            pair.second /= K;
        }

        map<set<int>, pair<double, int>> current, next;
        current[set<int>{0}] = make_pair(1.0, 0);
        double expected = 0.0;

        for (int i = 0; i < S; i++) {
            next.clear();
            for (auto& state_pair : current) {
                auto& state = state_pair.first;
                double p = state_pair.second.first;
                int matches = state_pair.second.second;

                for (auto& x : freq) {
                    char c = x.first;
                    set<int> next_state = {0};

                    bool matched = false;
                    for (int pos : state) {
                        if (target[pos] == c) {
                            if (pos < L-1) {
                                next_state.insert(pos+1);
                            } else {
                                matched = true;
                            }
                        }
                    }
                    next[next_state].first += p*freq[c];
                    next[next_state].second = max(next[next_state].second, matches+(matched?1:0));
                    if (matched) {
                        expected += p*freq[c];
                    }
                }
            }
            swap(current, next);
        }

        int best = 0;
        for (auto& state_pair : current) {
            best = max(best, state_pair.second.second);
        }

        cout << "Case #" << testCase << ": " << (best - expected) << endl;
    }
}
