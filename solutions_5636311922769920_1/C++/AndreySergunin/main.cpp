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
        long long k, c, s;
        cin >> k >> c >> s;
        if (c * s < k) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        long long cur = 0;
        long long pw = 1;
        for (long long i = 0; i < k || i % c != 0; ++i) {
            cur += min(i, k - 1) * pw;
            pw *= k;
            if ((i + 1) % c == 0) {
                cout << cur + 1 << " ";
                cur = 0;
                pw = 1;
            }
        }
        cout << endl;
    }
    return 0;
}