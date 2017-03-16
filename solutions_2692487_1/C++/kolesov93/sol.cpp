#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int _T;
    scanf("%d\n", &_T);

    for (int __test = 1; __test <= _T; ++__test) {
        int n;
        ll A;
        vector<ll> a;
        cin >> A;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());

        if (A == 1) {
            printf("Case #%d: ", __test);
            cout << n << endl;
            continue;
        }

        int ans = n;
        int already = 0;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, already + n - i);
            while (A <= a[i]) {
                A += A - 1;
                ++already;
            }
            A += a[i];
        }
        ans = min(ans, already);

        printf("Case #%d: ", __test);
        cout << ans << endl;
    }


    return 0;
}

