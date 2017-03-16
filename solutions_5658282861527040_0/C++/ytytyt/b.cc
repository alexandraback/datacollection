#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int T, a, b, k, tk, ans1;

inline float f(int n) {
    return ceil(log(n+1) / log(2)) - 1;
}

int main() {
    // cout << f(8) << endl;
    cin >> T;
    for (int ti = 1; ti <= T; ti++) {
        cin >> a >> b >> k;
        // tk = f(k);
        // ans1 = min(a + 1, 1 << tk) * min(b + 1, 1 << tk);
        // ans1 = min(a, k) * b + min(b, k) * a - min(a, k) * min(b, k);
        // cout << ans1 << endl;
        int ans = 0;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i & j) < k)
                    ans++;
        printf("Case #%i: %i\n", ti, ans);
    }
    return 0;
}
