#include <bits/stdc++.h>

using namespace std;


main (){

    freopen("C.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;

    for (int num = 1; num <= T; ++num) {

        cout << "Case #" << num << ":\n";

        int n, j;
        cin >> n >> j;

        for (int i = 0; i < j; ++i) {

            //cout << i + 1 << ": ";

            vector <int> v;

            int x = i;

            while (x > 0) {
                v.push_back(x % 2);
                v.push_back(x % 2);
                x /= 2;
            }

            while (v.size () < n - 4) v.push_back(0);

            cout << "11";

            for (int q = v.size () - 1; q >= 0; --q) cout << v[q];

            cout << "11";

            cout << " ";
            for (int q = 2; q <= 10; ++q) cout << q + 1 << " ";

            cout << "\n";

        }

    }
}
