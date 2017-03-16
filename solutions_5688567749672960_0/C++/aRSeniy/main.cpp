#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

long long Int(const vector<int>& v) {
    long long x = 0;
    for (int i = 0; i < v.size(); ++i) {
        x = x * 10LL + v[i];
    }
    return x;
}

vector<int> Digits(long long x) {
    vector<int> v;
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    if (v.empty()) v.push_back(0);
    return v;
}

long long nxt(long long x) {
    vector<int> d = Digits(x);
    reverse (d.begin(), d.end());
    return Int(d);
}

vector<int> d;
void precalc(bool b) {
    int n = 1000000;
    d.assign(n + 1, 0);

    if (b) {
        d[1] = 1;
        for (int i = 1; i <= n; ++i) {
            int nx = i + 1;
            if (nx <= n) {
                if (d[nx] == 0) d[nx] = d[i] + 1;
                else d[nx] = min(d[nx], d[i] + 1);
            }
            nx = nxt(i);
            if (nx <= n && nx > i) {
                if (d[nx] == 0) d[nx] = d[i] + 1;
                else d[nx] = min(d[nx], d[i] + 1);
            }

            if (i % 10000 == 0) cerr << i << endl;
        }

        ofstream PC("precalc");
        for (int i = 0; i < d.size(); ++i) {
            PC << d[i] << endl;
        }
    } else {
        ifstream PC("precalc");
        for (int i = 0; i < d.size(); ++i) {
            PC >> d[i];
        }
    }
}

void solve() {
    int n;
    cin >> n;

    cout << d[n] << endl;
}

int main() {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    precalc(false);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        cerr << test << endl;
        solve();
    }
    return 0;
}
