#include <bits/stdc++.h>

using namespace  std;

int main() {
//    freopen("B-large.in", "r", stdin);
//    freopen("2.txt", "w", stdout);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <int> cnt(2510, 0);

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                cnt[x]++;
            }
        }

        cout << "Case #" << cs + 1 << ":";
        for (int i = 1; i <= 2500; i++) {
            if (cnt[i] % 2 == 1) {
                cout << ' ' << i;
            }
        }
        cout << endl;
    }

    return 0;
}


