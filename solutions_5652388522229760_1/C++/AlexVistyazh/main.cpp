#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int getDigitsMask(int x) {
    int mask = 0;
    while (x > 0) {
        mask |= 1 << (x % 10);
        x /= 10;
    }
    return mask;
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int x;
    cin >> x;
    if (x == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }
    int mask = 0;
    for (int i = x; ; i += x) {
        mask |= getDigitsMask(i);
        if (mask == (1 << 10) - 1) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
}
