#include <cstring>
#include <string>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

long long convert(const vector<int>& l, int p) {
    long long x = 1;
    long long pow = p;
    for (int y : l) {
        x += y * pow;
        pow *= p;
    }
    return x + pow;
}

long long check(const vector<int>& l, int p) {
    long long x = convert(l, p);

    for (long long y = 2; y * y <= x; ++y) {
        if (x % y == 0) {
            return y;
        }
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    cout << convert({1,0,0,1,0,1,1,0,0,1,0,1,0,0}, 10) << endl;

    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        set<vector<int>> q;
        int n, j;
        cin >> n >> j;
        cout << "Case #" << k << ": ";
        int i = 0;
        while (i < j) {
            vector<int> l;
            for (int x = 0; x < n - 2; ++x) {
                l.push_back(rand() & 1);
            }
            if (q.count(l)) {
                continue;
            } else {
                q.insert(l);
            }
            vector<long long> div;
            for (int h = 2; h <= 10; ++h) {
                auto e = check(l, h);
                if (e == -1) {
                    break;
                } else {
                    div.push_back(e);
                }
            }
            if (div.size() == 9) {
                cout << endl;

                cout << 1;
                for (int x = l.size() - 1; x >= 0; --x) {
                    cout << l[x];
                }
                cout << "1 ";
                for (auto x : div) {
                    cout << x << " ";
                }
                ++i;
            }
        }
        cout << endl;
    }

    return 0;
}