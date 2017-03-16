#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

string s;
int n, a[1000010];

void solve() {
    cin >> s >> n;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') a[i] = 0;
        else
            a[i] = 1;
    }
    int len = 0, last = -1;
    long long res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (a[i] == 0) len = 0; else ++len;
        if (len >= n)
            last = i - n + 1;
        res += last + 1;
    }
    cout << res << endl;
}

int main() {

    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int T = 0, cnt = 0;
    cin >> T;
    while (T > 0) {
        --T;
        cout << "Case #" << ++cnt << ": ";
        solve();
    }
}
