#include <bits/stdc++.h>
#define maxN 1000000

using namespace std;

int main() {
    freopen("D-large.in", "r", stdin);
    freopen("Fractiles.out", "w", stdout);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {        
        int k, c, s;
        cin >> k >> c >> s;

        cout << "Case #" << i << ":";
        if (c == 1) {
            if (k <= s) {
                for (int j = 1; j <= k; j++)
                    cout << " " << j;
                cout << endl;            
            } else {
                cout << " IMPOSSIBLE" << endl;
            }
        } else
        if (s >= k - 1) {
            for (int j = 2; j <= k; j++)
                cout << " " << j;
            cout << endl;        
        } else {
            cout << " IMPOSSIBLE" << endl;
        }
    }

// Sub small
/*
    for (int i = 1; i <= t; i++) {        
        int k, c, s;
        cin >> k >> c >> s;

        cout << "Case #" << i << ":";
        for (int j = 1; j <= k; j++)
            cout << " " << j;
        cout << endl;        
    }
    */
}



