#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

#define TASKNAME ""

void solve(int test_number);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}

void solve(int test_number) {
    string s;
    cin >> s;
    int cnt[10] = {0};
    int cnt_alpha[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        cnt_alpha[s[i] - 'A']++;
    }
    cnt[0] = count(s.begin(), s.end(), 'Z');
    cnt[6] = count(s.begin(), s.end(), 'X');
    cnt[2] = count(s.begin(), s.end(), 'W');
    cnt[8] = count(s.begin(), s.end(), 'G');
    cnt[4] = count(s.begin(), s.end(), 'U');
    string eng[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int known[10] = {0, 6, 2, 8, 4};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < eng[known[i]].size(); j++) {
            cnt_alpha[eng[known[i]][j] - 'A'] -= cnt[known[i]];
        }
    }
    cnt[7] = cnt_alpha['S' - 'A'];
    for (int i = 0; i < eng[7].size(); i++) {
        cnt_alpha[eng[7][i] - 'A'] -= cnt[7];
    }
    cnt[5] = cnt_alpha['V' - 'A'];
    for (int i = 0; i < eng[5].size(); i++) {
        cnt_alpha[eng[5][i] - 'A'] -= cnt[5];
    }
    cnt[3] = cnt_alpha['H' - 'A'];
    for (int i = 0; i < eng[5].size(); i++) {
        cnt_alpha[eng[3][i] - 'A'] -= cnt[3];
    }
    cnt[1] = cnt_alpha['O' - 'A'];
    for (int i = 0; i < eng[1].size(); i++) {
        cnt_alpha[eng[1][i] - 'A'] -= cnt[1];
    }
    cnt[9] = cnt_alpha['I' - 'A'];
    for (int i = 0; i < eng[9].size(); i++) {
        cnt_alpha[eng[9][i] - 'A'] -= cnt[9];
    }
    cout << "Case #" << test_number + 1 << ": ";
    for (int i = 0; i < 10; i++) {
        cout << string(cnt[i], '0' + i);
    }
    cout << endl;
}
