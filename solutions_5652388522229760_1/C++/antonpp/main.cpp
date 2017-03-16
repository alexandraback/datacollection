#include <cstring>
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

set<int> f(long long n) {
    set<int> s;
    if (!n) {
        s.insert(0);
    } else {
        while (n) {
            s.insert(n % 10);
            n /= 10;
        }
    }
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        long long x;
        cin >> x;
        set<int> digits;
        int j = 1;
        cout << "Case #" << k << ": ";
        if (x == 0) {
            cout << "INSOMNIA";
        } else {
            for (; digits.size() < 10; ++j) {
                long long h = x * j;
                auto old = digits.size();
                auto ds = f(h);
                for (int d : ds) {
                    digits.insert(d);
                }
//                cout << endl << h;
//                for (auto f: digits) {
//                    cout << " " << f;
//                }
            }
            cout << x * (j - 1);
        }
        cout << endl;
    }

    return 0;
}