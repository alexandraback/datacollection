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
#define PROBLEM "C"

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        int n, m, k;
        cin >> n >> m >> k;
        
        int best = k;
        for (int p = 3; p <= n; p++) {
            for (int q = 3; q <= m; q++) {
                int area = p * q - 4;
                int perim = 2 * p + 2 * q - 8;
                if (area >= k && perim < best) {
                    best = perim;
                }
                if (area < k && perim + k - area < best) {
                    best = perim + k - area;
                }
            }
        }
        cout << best;
    
        printf("\n");
    }

    return 0;
}
