#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cout << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

// bool bit(int64 mask, int k) {
//     return ((1LL << k) & mask) != 0;
// }

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCount;
    cin >> testCount;
    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        int r, n, m, k;
        cin >> r >> n >> m >> k;
        cout << "Case #" << testNumber << ":" << endl;
        for (int t = 0; t < r; ++t) {
            cerr << "Case " << t << endl;
            vector<int> a(k);
            for (int i = 0; i < k; ++i)
                cin >> a[i];

            bool div2 = false, div3 = false, div5 = false, div4 = false, div8 = false, div16 = false, div32 = false, div64 = false;
            bool div9 = false, div27 = false;
            bool div25 = false, div125 = false;
            for (int i = 0; i < k; ++i) {
                div3 |= a[i] % 3 == 0;
                div9 |= a[i] % 9 == 0;
                div27 |= a[i] % 27 == 0;
                div5 |= a[i] % 5 == 0;
                div25 |= a[i] % 25 == 0;
                div125 |= a[i] % 125 == 0;
                div2 |= a[i] % 2 == 0;
                div4 |= a[i] % 4 == 0;
                div8 |= a[i] % 8 == 0;
                div16 |= a[i] % 16 == 0;
                div32 |= a[i] % 32 == 0;
                div64 |= a[i] % 64 == 0;
            }

            vector<int> count(m + 1);
            if (div32 && !div64 || div8 && !div16 || div2 && !div4)
                count[2] = 1;
            if (div64) count[4] = 3;
            else if (div32) {
                count[4] = 2;
                count[2] = 1;
            } else if (div16) {
                if (count[2] != 0) {
                    count[4] = 1;
                    count[2] = 2;
                } else {
                    count[4] = 2;
                }
            } else if (div8) {
                count[4] = 1;
            } else if (div4) {
                if (count[2] != 0) {
                    count[2] = 2;
                } else {
                    count[4] = 1;
                }
            }
            if (div27)
                count[3] = 3;
            else if (div9)
                count[3] = 2;
            else if (div3)
                count[3] = 1;
            if (div125)
                count[5] = 3;
            else if (div25)
                count[5] = 2;
            else if (div5)
                count[5] = 1;

            vector<int> digits;
            for (int i = 2; i <= m; ++i) {
                while (count[i] > 0) {
                    --count[i];
                    digits.push_back(i);
                }
            }
            assert(digits.size() <= n);
            while (digits.size() < n) {
                if (digits.size() > 0) {
                    digits.push_back(digits[0]);
                } else {
                    digits.push_back(2);
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << digits[i];
            }
            cout << endl;
        }
    }

    return 0;
}