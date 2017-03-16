//
//  d.cpp
//  
//
//  Created by Xiang Fei Ding on 4/9/16.
//
//

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

typedef unsigned long long int ull;

int main() {
    int t;
    cin >> t;
    for (int tc = 0, k, c, s; tc < t; ++tc) {
        cin >> k >> c >> s;
        cout << "Case #" << tc + 1 << ':';
        if (k > c)
            if ((ull) ceil(k / (double) c) > s)
                cout << " IMPOSSIBLE";
            else {
                ull r, a;
                for (int start = k - 1; start >= c - 1; start -= c) {
                    r = 0; a = 1;
                    for (int i = 0; i < c; ++i, a *= k)
                        r += (start - i) * a;
                    cout << ' ' << r + 1;
                }
                if (k % c) {
                    r = 0; a = 1;
                    for (int i = c - 1; i; --i, a *= k)
                        r += i * a;
                    cout << ' ' << r + 1;
                }
            }
        else {
            // min s == 1
            ull r = 0, a = 1;
            for (int i = k - 1; i; --i, a *= k)
                r += i * a;
            cout << ' ' << r + 1;
        }
        cout << endl;
    }
    return 0;
}
