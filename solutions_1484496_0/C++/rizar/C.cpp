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
    for (int test = 1; test <= nTests; test++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << "Case #" << test << ":\n";

        vector< pair<int, int> > all;
        for (int mask = 1; mask < (1 << n); mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) 
                if (mask & (1 << i))
                    sum += a[i];
            all.push_back(make_pair(sum, mask));
        }

        sort(all.begin(), all.end());
        int i = 0;
        for (; i + 1 < all.size() && all[i + 1].first != all[i].first; i++);

        if (i + 1 < all.size()) {
            assert(all[i].first == all[i + 1].first);
            vector<int> masks(2);
            masks[0] = all[i].second;
            masks[1] = all[i + 1].second;

            for (int p = 0; p < 2; p++) {
                vector<int> parts;
                for (int i = 0; i < n; i++)
                    if (masks[p] & (1 << i))
                        parts.push_back(a[i]);
                for (int i = 0; i < parts.size(); i++) {
                    if (i)
                        cout << ' ';
                    cout << parts[i];
                }
                cout << '\n';
            }
        }
        else
            cout << "Impossible\n";
    }

    return 0;
}


