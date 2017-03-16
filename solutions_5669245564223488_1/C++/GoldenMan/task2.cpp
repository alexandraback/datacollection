#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

const long long MD = 1000 * 1000 * 1000 + 7;

int solve(int test) {
    ///  Reading and test for validity each string
    int n;
    scanf("%d", &n);
    string s;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int fi[256];
        for (unsigned char c = 'a'; c <= 'z'; ++c) {
            fi[c] = -1;
        }
        for (size_t j = 0; j < s.length(); ++j) {
            if (fi[s[j]] == -1) {
                fi[s[j]] = j;
            } else {
                if (fi[s[j]] + 1 < j) {
                    cout << "Case #" << test << ": 0" << endl;
                    return 0;
                } else {
                    fi[s[j]] = j;
                }
            }
        }
        v.push_back(s);
    }
    /// Determining splash strings and left && right sizes
    bool is_splash[256];
    int left_sz[256];
    int right_sz[256];
    for (int i = 0; i < n; ++i) {
        is_splash[i] = true;
        for (size_t j = 0; j < v[i].length(); ++j) {
            if (v[i][j] != v[i][0]) {
                is_splash[i] = false;
                break;
            }
        }
        if (is_splash[i]) {
            left_sz[i] = right_sz[i] = v[i].length();
            continue;
        }
        left_sz[i] = 1;
        right_sz[i] = 1;
        if (v[i].length() < 2) {
            continue;
        }
        size_t j = 1;
        while (v[i][j] == v[i][0]) {
            ++j;
            ++left_sz[i];
        }
        j = v[i].length() - 2;
        while (v[i][j] == v[i][v[i].length() - 1]) {
            --j;
            ++right_sz[i];
        }
    }
    /// Testing for all this music in the strings
    int music[256];
    for (unsigned char c = 'a'; c <= 'z'; ++c) {
        music[c] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (is_splash[i]) {
            continue;
        }
        for (size_t j = left_sz[i]; j < v[i].length() - right_sz[i]; ++j) {
            music[v[i][j]] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < v[i].length(); ++j) {
            int cur = music[v[i][j]];
            if (cur == -1) {
                continue;
            }
            if (cur != i) {
                cout << "Case #" << test << ": 0" << endl;
                return 0;
            }
        }
    }
    /// Calculating splashes, lefts ans rights count for each letter
    int splash_cnt[256];
    int left_cnt[256];
    int right_cnt[256];
    for (unsigned char c = 'a'; c <= 'z'; ++c) {
        splash_cnt[c] = left_cnt[c] = right_cnt[c] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (is_splash[i]) {
            splash_cnt[v[i][0]]++;
        } else {
            ++left_cnt[v[i][0]];
            ++right_cnt[v[i][v[i].length() - 1]];
        }
    }
    for (unsigned char c = 'a'; c <= 'z'; ++c) {
        if (left_cnt[c] > 1 || right_cnt[c] > 1) {
            cout << "Case #" << test << ": 0" << endl;
            return 0;
        }
    }
    /// Making char-pairs
    long long mult = 1;
    int out_splashed = 0;
    for (unsigned char c = 'a'; c <= 'z'; ++c) {
        if (left_cnt[c] == 0 && right_cnt[c] == 0 && splash_cnt[c] != 0) {
            ++out_splashed;
        }
        for (int i = 0; i < splash_cnt[c]; ++i) {
            mult = (mult * (i + 1)) % MD;
        }
    }
    vector<pair<char, char>> cp;
    for (int i = 0; i < n; ++i) {
        if (is_splash[i]) {
            continue;
        }
        cp.push_back(make_pair(v[i][0], v[i][v[i].length() - 1]));
    }
    n = cp.size();
    /// Making chains;
    int chains = out_splashed;
    unsigned long long ans = mult;
    for (unsigned c = 'a'; c <= 'z'; ++c) {
        if (left_cnt[c] > 0 && right_cnt[c] > 0) {
            int li = 0;
            int ri = 0;
            for (int i = 0; i < n; ++i) {
                if (cp[i].first == c) {
                    ri = i;
                }
                if (cp[i].second == c) {
                    li = i;
                }
            }
            if (cp[li].first == cp[ri].second) {
                cout << "Case #" << test << ": " << 0 << endl;
                return 0;
            }
            pair<char, char> tmp = make_pair(cp[li].first, cp[ri].second);
            swap(cp[li], cp[n - 2]);
            swap(cp[ri], cp[n - 1]);
            cp[n - 2] = tmp;
            cp.pop_back();
            n = cp.size();
        }
    }
    chains += n;
    for (int i = 0; i < chains; ++i) {
        ans = (ans * (i + 1)) % MD;
    }
    cout << "Case #" << test << ": " << ans << endl;
    return 0;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; ++_) {
        solve(_ + 1);
    }
    return 0;
}
