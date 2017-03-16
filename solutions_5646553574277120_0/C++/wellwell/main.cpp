#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <functional>
#include <bitset>

using namespace std;

long long reversed(long long num) {
    long long res = 0;
    while (num) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }

    return res;
}

void printans(int test, int ans) {
    cout << "Case #" << test << ": " << ans << endl;
}



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int cases;
    cin >> cases;

    for (int test = 1; test <= cases; test++) {
        int c, d, v;
        cin >> c >> d >> v;

        vector<int> a(d);
        set<int> used;

        for (int i = 0; i < d; i++) {
            cin >> a[i];
            used.insert(a[i]);
        }

        int ans = 100;
        for (int i = 0; i < (1 << 16); i++) {
            bitset<16> mask(i);
            bool can_use = true;
            for (int j = 0; j < 16; j++) {
                if (mask[j] && used.count(j + 1)) {
                    can_use = false;
                    break;
                }
            }

            if (!can_use) {
                continue;
            }

            vector<int> b = a;
            for (int j = 0; j < 16; j++) {
                if (mask[j]) {
                    b.push_back(j + 1);
                }
            }

            vector<vector<int> > sum(b.size() + 1, vector<int>(31));
            sum[0][0] = true;

            for (int i = 1; i <= b.size(); i++) {
                for (int j = 0; j < 31; j++) {
                    if (sum[i - 1][j]) {
                        sum[i][j] = true;
                    } else {
                        continue;
                    }

                    if (j + b[i - 1] >= 31) {
                        continue;
                    }

                    sum[i][j + b[i - 1]] = true;
                }
            }

            can_use = true;

            // cout << b.size() << endl;
            // for (auto e : sum[b.size()]) {
            //     cout << e << " ";
            // }
            // cout << endl;

            for (int i = 1; i <= v; i++) {
                if (!sum[b.size()][i]) {
                    can_use = false;
                    break;
                }
            }

            if (can_use) {
                ans = min(ans, (int)mask.count());
            }
        }


        cout << "Case #" << test << ": " << ans << endl;
    }
}
