#include <bits/stdc++.h>

using namespace std;

string name[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

bool comp(const pair <string, int>& p, const pair <string, int>& q) {
    return p.first.length() > q.first.length();
}

map < vector <int>, bool> memo;

bool brute(vector <int> rem, string s) {
    if (memo.count(rem)) {
        return false;
    }
    memo[rem] = true;
    bool ok = true;
    for (int x : rem) {
        if (x > 0)
            ok = false;
    }
    if (ok) {
        sort(s.begin(), s.end());
        cerr << s << '\n';
        cout << s << '\n';
        return true;
    }

    for (int i = 0; i <= 9; ++i) {
        bool can = true;
        map <char, int> cnt;
        for (char c : name[i]) {
            cnt[c]++;
        }
        for (auto c : cnt) {
            if (rem[c.first - 'A'] < c.second) {
                can = false;
                break;
            }
        }
        if (can) {
            vector <int> nrem = rem;
            for (auto c : cnt) {
                nrem[c.first - 'A'] -= c.second;
            }
            if (brute(nrem, s + string(1, '0' + i))) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    string s;
    cin >> s;
    vector <int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'A']++;
    }
    memo.clear();
    brute(cnt, "");
}

int main() {
    int numTests;
    cin >> numTests;
    for (int testId = 1; testId <= numTests; ++testId) {
        cerr << "Case #" << testId << ": ";
        cout << "Case #" << testId << ": ";
        solve();
    }
    return 0;
}
