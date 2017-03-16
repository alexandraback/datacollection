#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(string &str, int i, int j) {
    if (i > j) return;

    char big = str[i];
    int loc = i;

    for (int k = i + 1; k <= j; k++) {
        if (str[k] >= big) {
            big = str[k];
            loc = k;
        }
    }

    cout << big;
    solve(str, i, loc - 1);

    for (int k = loc + 1; k <= j; k++)
        cout << str[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        string str;
        cin >> str;

        cout << "Case #" << tc << ": ";
        solve(str, 0, str.size() - 1);
        cout << "\n";
    }

    return 0;
}

