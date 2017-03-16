#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX_D = 1005;

int main() {
    int tests;

    cin >> tests;

    for (int test_id = 1; test_id <= tests; test_id++) {
        int d, a[MAX_D];

        cin >> d;

        for (int i = 0; i < d; i++) {
            cin >> a[i];
        }

        int ans = 1e9;

        for (int i = 1; i < MAX_D; i++) {
            int cur = 0;

            for (int j = 0; j < d; j++) {
                if (a[j] <= i) {
                    continue;
                }

                cur += (a[j] - i + (i - 1)) / i;
            }

            ans = min(ans, cur + i);
        }

        cout << "Case #" << test_id << ": " << ans << endl;
    }

    return 0;
}
