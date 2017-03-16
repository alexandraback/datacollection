#include <bits/stdc++.h>
using namespace std;
const string num[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", 
    "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const double eps = 1e-6;

int res[10];
double a[27][11], tmp[11];
string s;

void gauss() {
    for (int i = 0; i < 27; i++) {
        int mn = 1e9, idx = -1;
        for (int j = i; j < 27; j++) {
            int left = 0;
            for (; left < 11; left++) {
                if (abs(a[j][left]) > eps) {
                    break;
                }
            }
            if (left < mn) {
                mn = left;
                idx = j;
            }
        }
        if (idx == -1) {
            break;
        }
        memcpy(tmp, a[i], sizeof(tmp));
        memcpy(a[i], a[idx], sizeof(a[i]));
        memcpy(a[idx], tmp, sizeof(a[idx]));

        for (int j = 0; j < 27; j++) {
            if (i != j && abs(a[j][mn]) > eps) {
                double scale = a[j][mn] / a[i][mn];
                for (int k = 0; k < 11; k++) {
                    a[j][k] -= scale * a[i][k];
                }
            }
        }
    }
}

void solve() {
    cin >> s;

    memset(a, 0, sizeof(a));
    for (char c : s) {
        ++a[c - 'A'][10];
    }
    a[26][10] = s.size();
    for (int i = 0; i < 10; i++) {
        for (char c : num[i]) {
            ++a[c - 'A'][i];
        }
        a[26][i] = num[i].size();
    }

    gauss();

    memset(res, 0, sizeof(res));
    for (int i = 0; i < 10; i++) {
        int left = 0;
        for (; left < 11; left++) {
            if (abs(a[i][left]) > eps) {
                break;
            }
        }
        if (left == 10) {
            break;
        }

        res[left] = round(a[i][10] / a[i][left]);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < res[i]; j++) {
            cout << i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
