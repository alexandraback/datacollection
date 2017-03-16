#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

int n;
long long p10[maxn], mn = 2e18; 
string a, b, ra, rb;

void go(int idx, long long diff) {
    if (idx == n) {
        if (abs(diff) < mn) {
            mn = abs(diff);
            ra = a;
            rb = b;
        } else if (abs(diff) == mn) {
            if (a.compare(ra) < 0) {
                ra = a;
                rb = b;
            } else if (a.compare(ra) == 0 && b.compare(rb) < 0) {
                ra = a;
                rb = b;
            }
        }
        return;
    }

    if (diff == 0) {
        if (a[idx] == '?' && b[idx] == '?') {
            a[idx] = b[idx] = '0';
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            a[idx] = '0', b[idx] = '1';
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            a[idx] = '1', b[idx] = '0';
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            a[idx] = b[idx] = '?';
        } else if (a[idx] == '?') {
            a[idx] = b[idx];
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            if (b[idx] != '0') {
                a[idx] = b[idx] - 1;
                go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            }
            if (b[idx] != '9') {
                a[idx] = b[idx] + 1;
                go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            }
            a[idx] = '?';
        } else if (b[idx] == '?') {
            b[idx] = a[idx];
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            if (a[idx] != '0') {
                b[idx] = a[idx] - 1;
                go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            }
            if (a[idx] != '9') {
                b[idx] = a[idx] + 1;
                go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            }
            b[idx] = '?';
        } else {
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
        }
    } else {
        if (a[idx] == '?' && b[idx] == '?') {
            if (diff < 0) {
                a[idx] = '9';
                b[idx] = '0';
            } else {
                a[idx] = '0';
                b[idx] = '9';
            }
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            a[idx] = b[idx] = '?';
        } else if (a[idx] == '?') {
            if (diff < 0) {
                a[idx] = '9';
            } else {
                a[idx] = '0';
            }
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            a[idx] = '?';
        } else if (b[idx] == '?') {
            if (diff < 0) {
                b[idx] = '0';
            } else {
                b[idx] = '9';
            }
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
            b[idx] = '?';
        } else {
            go(idx + 1, diff + (a[idx] - b[idx]) * p10[n - 1 - idx]);
        }
    }
}

void solve() {
    cin >> a >> b;
    n = a.size();
    mn = 2e18;
    go(0, 0);
    cout << ra << ' ' << rb;
}

void precomp() {
    p10[0] = 1;
    for (int i = 1; i < maxn; i++) {
        p10[i] = 10 * p10[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precomp();
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
