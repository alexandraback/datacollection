#include <bits/stdc++.h>

using namespace std;

vector <int> cands;

void brute(int idx, const string& s, int n) {
    if (idx == s.size()) {
        cands.push_back(n);
        return;
    }
    if (s[idx] == '?') {
        for (int d = 0; d <= 9; ++d) {
            brute(idx + 1, s, n * 10 + d);
        }
    } else {
        brute(idx + 1, s, n * 10 + (s[idx] - '0'));
    }
}
void solve() {
    string c, j;
    cin >> c >> j;
    cands.clear();
    brute(0, c, 0);
    vector <int> a = cands;
    cands.clear();
    brute(0, j, 0);
    vector <int> b = cands;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int bestDiff = (int)1e9, bestC = (int)1e9, bestJ = (int)1e9;
    for (int x : a) {
        int id = lower_bound(b.begin(), b.end(), x) - b.begin();
        if (id < b.size()) {
            int curDiff = abs(x - b[id]);
            if (curDiff < bestDiff) {
                bestDiff = curDiff;
                bestC = x;
                bestJ = b[id];
            } else if (curDiff == bestDiff) {
                if (x < bestC) {
                    bestC = x;
                    bestJ = b[id];
                } else if (x == bestC) {
                    bestJ = min(bestJ, b[id]);
                }
            }
        }

        if (id > 0) {
            --id;
            int curDiff = abs(x - b[id]);
            if (curDiff < bestDiff) {
                bestDiff = curDiff;
                bestC = x;
                bestJ = b[id];
            } else if (curDiff == bestDiff) {
                if (x < bestC) {
                    bestC = x;
                    bestJ = b[id];
                } else if (x == bestC) {
                    bestJ = min(bestJ, b[id]);
                }
            }
        }
    }
    string cc = to_string(bestC);
    while (cc.size() < c.size()) cc = "0" + cc;
    string jj = to_string(bestJ);
    while (jj.size() < j.size()) jj = "0" + jj;
    cerr << cc << ' ' << jj << '\n';
    cout << cc << ' ' << jj << '\n';
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
