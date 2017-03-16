#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    for (int t = 0; t < test; ++t) {
        cout << "Case #" << t + 1 << ": ";
        string s;
        cin >> s;
        s += '+';
        int ans = 0;
        for (int i = 0; i < (int)s.size() - 1; ++i)
            if (s[i] != s[i + 1])
                ++ans;
        cout << ans << endl;
    }
    return 0;
}