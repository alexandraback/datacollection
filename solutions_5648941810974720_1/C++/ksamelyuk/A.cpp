#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void Reduce(vector<int>& cnt, int d) {
    for (int i = 0; i < digits[d].size(); ++i) {
        --cnt[digits[d][i] - 'A'];
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    int tests_count;
    cin >> tests_count;
    for (int test_index = 0; test_index < tests_count; ++test_index) {
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i] - 'A'];
        }
        vector<int> res;
        while (cnt['Z' - 'A']) {
            res.push_back(0);
            Reduce(cnt, 0);
        }
        while (cnt['W' - 'A']) {
            res.push_back(2);
            Reduce(cnt, 2);
        }
        while (cnt['X' - 'A']) {
            res.push_back(6);
            Reduce(cnt, 6);
        }
        while (cnt['G' - 'A']) {
            res.push_back(8);
            Reduce(cnt, 8);
        }
        while (cnt['T' - 'A']) {
            res.push_back(3);
            Reduce(cnt, 3);
        }
        while (cnt['R' - 'A']) {
            res.push_back(4);
            Reduce(cnt, 4);
        }
        while (cnt['F' - 'A']) {
            res.push_back(5);
            Reduce(cnt, 5);
        }
        while (cnt['S' - 'A']) {
            res.push_back(7);
            Reduce(cnt, 7);
        }
        while (cnt['O' - 'A']) {
            res.push_back(1);
            Reduce(cnt, 1);
        }
        while (cnt['I' - 'A']) {
            res.push_back(9);
            Reduce(cnt, 9);
        }
        sort(res.begin(), res.end());

        cout << "Case #" << test_index + 1 << ": ";
        for (int d : res) {
            cout << d;
        }
        cout << "\n";
    }
    return 0;
}
