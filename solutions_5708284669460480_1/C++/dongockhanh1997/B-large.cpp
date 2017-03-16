#include <bits/stdc++.h>
using namespace std;

vector<int> getFail(const string &s) {
    vector<int> f (s.size());
    f[0] = -1;
    for (int i = 1, j = -1; i < (int) s.size(); ++i) {
        while (j >= 0 && s[i] != s[j + 1]) j = f[j];
        if (s[i] == s[j + 1]) ++j;
        f[i] = j;
    }
    return f;
}

double f[101][101][101];
bool possible[101][101][101];

double runTest() {
    int k; cin >> k;
    int l; cin >> l;
    int s; cin >> s;
    string keyboard; cin >> keyboard;
    string target; cin >> target;
    vector<int> fail = getFail(target);
    vector<vector<int> > next (fail.size(), vector<int>(26, 0));
    for (int match = 0; match < (int) fail.size(); ++match) {
        for (int c = 0; c < 26; ++c) {
            int j = match - 1;
            while (j >= 0 && 'A' + c != target[j + 1]) j = fail[j];
            if ('A' + c == target[j + 1]) ++j;
            next[match][c] = j + 1;
        }
    }
    memset(f, 0, sizeof f);
    memset(possible, 0, sizeof possible);
    f[0][0][0] = 1;
    possible[0][0][0] = true;
    for (int typed = 0; typed < s; ++typed) {
        for (int match = 0; match < l; ++match) {
            for (int cnt = 0; cnt <= typed; ++cnt) if (possible[typed][match][cnt]) {
                for (char foo : keyboard) {
                    int c = foo - 'A';
                    if (next[match][c] == l) {
                        f[typed + 1][fail[l - 1] + 1][cnt + 1] += f[typed][match][cnt] / keyboard.size();
                        possible[typed + 1][fail[l - 1] + 1][cnt + 1] = true;
                    } else {
                        f[typed + 1][next[match][c]][cnt] += f[typed][match][cnt] / keyboard.size();
                        possible[typed + 1][next[match][c]][cnt] = true;
                    }
                }
            }
        }
    }
    double result = 0;
    int worst = 0;
    for (int match = 0; match < l; ++match) {
        for (int cnt = 0; cnt <= s; ++cnt) if (possible[s][match][cnt]) {
            result += f[s][match][cnt] * cnt;
            worst = max(worst, cnt);
        }
    }
    return worst - result;
}

int main() {
    assert(freopen("B-large-0.in", "r", stdin));
    assert(freopen("B-large-0.out", "w", stdout));
    ios::sync_with_stdio(false);
    int numTests; cin >> numTests;
    cout << fixed << setprecision(12);
    for (int test = 0; test < numTests; ++test) {
        cout << "Case #" << test + 1 << ": " << runTest() << '\n';
    }
    return 0;
}
