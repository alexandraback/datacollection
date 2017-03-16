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
        string s;
        cin >> s;
        int ans = 0;
        bool prev = false;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '-') {
                if (prev) {
                    continue;
                } else {
                    prev = true;
                    if (j != 0) {
                        ++ans;
                    }
                }
            } else {
                if (prev) {
                    ++ans;
                    prev = false;
                } else {
                    continue;
                }
            }
        }
        if (prev) {
            ++ans;
        }
        cout << "Case #" << k << ": " << ans;
        cout << endl;
    }

    return 0;
}