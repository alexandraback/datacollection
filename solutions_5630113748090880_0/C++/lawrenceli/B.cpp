#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

const int maxn = 55;

int n;
int freq[maxn * maxn];

void go(int casenum) {
    memset(freq, 0, sizeof(freq));
    cin >> n;
    for (int i = 0; i < 2 * n - 1; i++)
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            freq[a]++;
        }

    cout << "Case #" << casenum << ": ";
    int cnt = 0;
    for (int i = 0; i < maxn * maxn; i++)
        if (freq[i] & 1) {
            cout << i;
            cnt++;
            if (cnt < n) cout << ' ';
            else cout << '\n';
        }
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) go(i);
}
