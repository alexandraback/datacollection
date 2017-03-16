#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long int64;
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
#define PROBLEM "B"

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        double c, f, x;
        cin >> c >> f >> x;

        double ans = 0;
        int i;
        for (i = 0; ; i++) {
            if (2 * c + c * f * (i+1) > x * f) {
                break;
            }
            ans += c / (2 + f * i);
        }
        assert(i < 101000);
        cerr << i << endl;
        ans += x / (2 + f * i);

        printf("%0.7lf", ans);

        printf("\n");
    }

    return 0;
}
