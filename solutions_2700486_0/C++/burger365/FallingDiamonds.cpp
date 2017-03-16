#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>

#define PRINT_VAL(sx, vx) cout << sx << " = " << vx
#define PRINT1(x, ...) PRINT_VAL(#x, x)
#define PRINT2(x, ...) PRINT_VAL(#x, x); cout << ", "; PRINT1(__VA_ARGS__)
#define PRINT3(x, ...) PRINT_VAL(#x, x); cout << ", "; PRINT2(__VA_ARGS__)
#define PRINT4(x, ...) PRINT_VAL(#x, x); cout << ", "; PRINT3(__VA_ARGS__)
#define PRINT5(x, ...) PRINT_VAL(#x, x); cout << ", "; PRINT4(__VA_ARGS__)
#define PRINT(n, ...)                                                   \
    do {                                                                \
        PRINT##n(__VA_ARGS__);                                          \
        cout << " [" << __func__ << ", " << __LINE__ << "]" << endl;    \
    } while (0)                                                         \

using namespace std;

int main() {
    int T;
    assert(scanf("%d", &T) != EOF);

    for (int t = 1; t <= T; ++t) {
        int N, X, Y;
        assert(scanf("%d %d %d", &N, &X, &Y) != EOF);
        X = abs(X);
        Y = abs(Y);
        
        int c = 1, n = 1, triangle = 0;
        while (n <= N) {
            //PRINT(1, n);
            ++triangle;
            c = n;
            n += 4 * (triangle + 1) - 3;
        }

        int r = N - c;
        //PRINT(2, triangle, r);
        if (X + Y < triangle * 2) {
            printf("Case #%d: 1.0\n", t);
            continue;
        }

        if (X + Y > triangle * 2 || r < Y + 1 || Y == triangle * 2) {
            printf("Case #%d: 0.0\n", t);
            continue;
        }

        int maxY = triangle * 2;
        int num = Y + 1;
        if (num <= r - maxY) {
            printf("Case #%d: 1.0\n", t);
            continue;
        }
        
        vector<double> p(maxY + 1), np;
        p[0] = 1.0;
        for (int i = 0; i < r; ++i) {
            np = vector<double>(maxY + 1);
            for (int j = min(maxY, i); j >= 0; --j) {
                //PRINT(2, j, p[j]);
                int left = i - j;
                if (j == maxY) {
                    np[j] += p[j];
                } else if (left >= maxY) {
                    np[j + 1] += p[j];
                    np[j] = 0.0;
                } else {
                    np[j + 1] += p[j] * 0.5;
                    np[j] += p[j] * 0.5;
                }
                //PRINT(3, i, j, np[num]);
            }
            swap(p, np);
        }
        
        double ans = 0;
        for (int i = num; i <= maxY; ++i)
            ans += p[i];
        printf("Case #%d: %7f\n", t, ans);
    }

    return 0;
}
