#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <cstring>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <queue>
#include <iterator>

typedef long long LL;
typedef long double LD;

using namespace std;

int main() {
#ifndef LOCAL
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

    int nTests;
    cin >> nTests;
    for (int test = 0; test < nTests; test++) {
        int n;
        cin >> n;

        int x = 0;
        vector<int> ps(n);
        for (int i = 0; i < n; i++) {
            cin >> ps[i];
            x += ps[i];
        }

        cout << "Case #" << test + 1 << ":";
        for (int i = 0; i < n; i++) {
            LD left = 0, right =  1;
            for (int it = 0; it < 80; it++) {
                LD middle = (left + right) / 2;
                LD level = ps[i] + middle * x;

                LD sum = 0;
                for (int j = 0; j < n; j++)
                    sum += max(0.0L, level - ps[j]);

                if (sum > x)
                    right = middle;
                else
                    left = middle;
            }
            cout << ' ' << 100 * left;
        }
        cout << '\n';
    }

    return 0;
}


