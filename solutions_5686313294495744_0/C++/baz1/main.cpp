#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <utility>
#include <string>
#include <unordered_map>

//#include <gmpxx.h>

using namespace std;

typedef unsigned long long ull;

#define W_UNKNOWN   0
#define W_FAKE      1
#define W_REAL      2

struct Words {
    unordered_map<string, pair< vector<int>, int > > positions;// (nb of known (fake with no real), or -1 if has real)
    vector<string> words;
};

int main() {
    int T, N;
    cin >> T;
    string w;
    for (int i = 0; i < T;) {
        Words left, right;
        vector<int> states;
        cin >> N;
        left.words.reserve(N);
        states.resize(N, W_UNKNOWN);
        right.words.reserve(N);
        for (int k = 0; k < N; ++k) {
            cin >> w;
            left.positions[w].first.push_back(k);
            left.positions[w].second = 0;
            left.words.push_back(w);
            cin >> w;
            right.positions[w].first.push_back(k);
            right.positions[w].second = 0;
            right.words.push_back(w);
        }
        int result = 0;
        for (const pair<string, pair< vector<int>, int > > &p: right.positions) {
            if (p.second.first.size() == 1) {
                states[p.second.first.front()] = W_REAL;
                left.positions[left.words[p.second.first.front()]].second = -1;
                right.positions[p.first].second = -1;
                continue;
            }
        }
        for (const pair<string, pair< vector<int>, int > > &p: left.positions) {
            if (p.second.first.size() == 1) {
                states[p.second.first.front()] = W_REAL;
                left.positions[p.first].second = -1;
                right.positions[right.words[p.second.first.front()]].second = -1;
                continue;
            }
        }
        while (true) {
            bool act = false;
            for (auto it = left.positions.begin(); it != left.positions.end(); ++it) {
                pair< vector<int>, int > &p = it->second;
                if ((p.second >= 0) || (p.second == -2))
                    continue;
                act = true;
                for (const int &i: p.first) {
                    if (states[i] != W_UNKNOWN)
                        continue;
                    pair< vector<int>, int > &pos = right.positions[right.words[i]];
                    if (pos.second < 0) {
                        states[i] = W_FAKE;
                        ++result;
                        continue;
                    }
                    if (pos.second < (int) pos.first.size() - 1) {
                        states[i] = W_FAKE;
                        ++result;
                        ++pos.second;
                    } else {
                        states[i] = W_REAL;
                        pos.second = -1;
                    }
                }
                p.second = -2;
            }
            for (auto it = right.positions.begin(); it != right.positions.end(); ++it) {
                pair< vector<int>, int > &p = it->second;
                if ((p.second >= 0) || (p.second == -2))
                    continue;
                act = true;
                for (const int &i: p.first) {
                    if (states[i] != W_UNKNOWN)
                        continue;
                    pair< vector<int>, int > &pos = left.positions[left.words[i]];
                    if (pos.second < 0) {
                        states[i] = W_FAKE;
                        ++result;
                        continue;
                    }
                    if (pos.second < (int) pos.first.size() - 1) {
                        states[i] = W_FAKE;
                        ++result;
                        ++pos.second;
                    } else {
                        states[i] = W_REAL;
                        pos.second = -1;
                    }
                }
                p.second = -2;
            }
            if (act) continue;
            for (int k = 0; k < N; ++k) {
                if (states[k] == W_UNKNOWN) {
                    states[k] = W_REAL;
                    left.positions[left.words[k]].second = -1;
                    right.positions[right.words[k]].second = -1;
                    act = true;
                    break;
                }
            }
            if (!act) break;
        }
        cout << "Case #" << (++i) << ": " << result << endl;
    }
    return 0;
}
