#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<string> digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


void solve() {
    string s;
    cin >> s;
    vector<int> a(26, 0);
    for (int i = 0; i < sz(s); ++i) {
        ++a[s[i] - 'A'];
    }
    vector<int> ans(10, 0);

    ans[0] = a['Z' - 'A'];
    for (int i = 0; i < sz(digits[0]); ++i) a[digits[0][i] - 'A'] -= ans[0];

    ans[2] = a['W' - 'A'];
    for (int i = 0; i < sz(digits[2]); ++i) a[digits[2][i] - 'A'] -= ans[2];

    ans[4] = a['U' - 'A'];
    for (int i = 0; i < sz(digits[4]); ++i) a[digits[4][i] - 'A'] -= ans[4];

    ans[1] = a['O' - 'A'];
    for (int i = 0; i < sz(digits[1]); ++i) a[digits[1][i] - 'A'] -= ans[1];

    ans[6] = a['X' - 'A'];
    for (int i = 0; i < sz(digits[6]); ++i) a[digits[6][i] - 'A'] -= ans[6];

    ans[5] = a['F' - 'A'];
    for (int i = 0; i < sz(digits[5]); ++i) a[digits[5][i] - 'A'] -= ans[5];

    ans[7] = a['V' - 'A'];
    for (int i = 0; i < sz(digits[7]); ++i) a[digits[7][i] - 'A'] -= ans[7];

    ans[8] = a['G' - 'A'];
    for (int i = 0; i < sz(digits[8]); ++i) a[digits[8][i] - 'A'] -= ans[8];

    ans[9] = a['I' - 'A'];
    for (int i = 0; i < sz(digits[9]); ++i) a[digits[9][i] - 'A'] -= ans[9];

    ans[3] = a['H' - 'A'];
    for (int i = 0; i < sz(digits[3]); ++i) a[digits[3][i] - 'A'] -= ans[3];

    string result;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < ans[i]; ++j) {
            result.pb('0' + i);
        }
    }
    cout << result << endl;

}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
