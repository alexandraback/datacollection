#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long ll;

ll ele[1000005];

int main(void) {
    int t, n, a;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> a >> n;
        //memset(ele, 0, sizeof (int) * 1000005);
        for (int i = 0; i < n; i++) cin >> ele[i];

        std::sort(ele, ele + n);

        ll add = 0, tot = a, res = 10e9, rem = 0;
        for (int i = 0; i < n; i++) {
            if (ele[i] < tot)
                tot += ele[i];
            else {
                res = min(res, add + (n - i));
                tot += (tot - 1);
                add++;
                i--;
                if (add >= n) break;
            }
        }
        if (res == 10e9) res = 0;
        res = min(res, add);
        cout << "Case #" << test << ": " << res << "\n";
    }
    return 0;
}