#include <bits/stdc++.h>

using namespace std;

inline bool can_eq(char a, char b){
    return a=='?' || b=='?' || a == b;
}

int best_diff;
string best_s1, best_s2;

void dfs(string &s1, string &s2, int prefix_len) {
    if (prefix_len == s1.size()) {
        int diff = abs(stoi(s1) - stoi(s2));
        if (diff < best_diff or (diff == best_diff and s1 < best_s1)) {
            best_diff = diff;
            best_s1 = s1;
            best_s2 = s2;
        }
        return;
    }
    bool change_first = s1[prefix_len] == '?';
    bool change_second = s2[prefix_len] == '?';
    for (char c1='0'; c1<='9'; c1++) {
        for (char c2 = '0';  c2 <= '9'; c2++) {
            if (change_first) {
                s1[prefix_len] = c1;
            }
            if (change_second) {
                s2[prefix_len] = c2;
            }
            dfs(s1, s2, prefix_len + 1);
        }
    }
    if (change_first) {
        s1[prefix_len] = '?';
    }
    if (change_second) {
        s2[prefix_len] = '?';
    }
}

void solve(int testnum)
{
    string s1, s2;
    cin >> s1 >> s2;
    best_diff = 100500;
    dfs(s1, s2, 0);
    cout << "Case #" << testnum + 1 << ": " << best_s1 << ' ' << best_s2 << endl;
}

int main()
{
    int T;
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int testnum = 0; testnum < T; testnum++) {
        solve(testnum);
    }
}
