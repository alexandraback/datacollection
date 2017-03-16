#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>

using namespace std;

int c, d, v, used[100], ans;
bool good;

void rec(int val, int rm) {
    if (val == v + 1 || rm == 0) {
        int pos[100] = {1};
        vector< int > ds;

        for (int i = 0; i <= v; i++) {
            if (used[i]) {
                ds.push_back(i);
            }
        }

        for (int i = 0; i < ds.size(); i++) {
            for (int j = v; j >= 0; j--) {
                if (pos[j] && j + ds[i] <= v) {
                    pos[j + ds[i]] = 1;
                }
            }
        }

        if (!count(pos, pos + v + 1, 0)) {
            good = true;
        }

        return;
    }

    rec(val + 1, rm);

    if (!used[val]) {
        used[val] = 1;

        rec(val + 1, rm - 1);

        used[val] = 0;
    }
}

int main() {
    int tests;

    cin >> tests;

    for (int test_id = 1; test_id <= tests; test_id++) {
        cin >> c >> d >> v;

        memset(used, 0, sizeof(used));

        for (int i = 0; i < d; i++) {
            int x;

            cin >> x;

            used[x] = 1;
        }

        good = false;

        ans = v;

        for (int i = 0; ; i++) {
            rec(1, i);

            if (good) {
                ans = i;
                break;
            }
        }

        cout << "Case #" << test_id << ": " << ans << endl;
    }

    return 0;
}
