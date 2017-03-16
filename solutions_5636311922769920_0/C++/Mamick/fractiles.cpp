#include <bits/stdc++.h>

using namespace std;
int t, k, c, s;
long long toPos(vector<long long> l) {
    long long cur = 0;
    long long mult = 1;
    for (int i = l.size() - 1; i >= 0; i--) {
        cur += l[i] * mult;
        mult *= k;
    }
    return cur;
}

int main() {
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> k >> c >> s;
        vector<long long> results;
        for (int i = 0; i < k; i += c) {
            vector<long long> tmp;
            for (int j = i; j < i + c && j < k; j++) {
                tmp.push_back(j);
            }
            results.push_back(toPos(tmp));
        }
        cout << "Case #" << test << ": ";
        if (results.size() > s) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i = 0; i < results.size(); i++) {
                cout << (results[i] + 1);
                if (i != results.size() - 1) {
                    cout << " ";
                }
            }

            cout << endl;
        }
    }
}